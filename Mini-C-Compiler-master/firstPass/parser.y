%{
#pragma GCC diagnostic ignored "-Wwrite-strings"

#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <algorithm>
#include <stack>
#include <stdio.h>

#include "helpers.h"
#include "code_gen.h"

using namespace std;

#define YYERROR_VERBOSE 1

extern int yylex();
extern int yyparse();
extern int yylineno;
extern int yyleng;
extern char* yytext;
void yyerror(const char* s);

int offsetValue;
string text;
typeRecord* variableRecord;
vector<int> decDimensionList;
vector<typeRecord*> globalVariables;
eletype resultType;
stack<vector<typeRecord*> > parameterListStack;
vector<typeRecord*> typeRecordList;

int nextNum;
vector<string> functionInstruction;
registerSet temporarySet;

vector<functionEntry*> functionEntryRecord;
functionEntry* activeFunctionPointer;
functionEntry* callFunctionPointer;
vector<string> switchVariable;
vector<functionEntry*> callFunctionPointerList;
vector<string> dimensionList;
int scope;
int found;
bool errorFound;
int numberOfParameters;
string conditionVariable;

vector<pair<string,int>> stringVariable;
%}

%code requires{
    #include "helpers.h"
    #include "code_gen.h"
}

%union {
    int intValue;
    float floatValue;
    char *idName;
    int quad;

    struct expression expressionValue;
    struct switchCaser switchCaseValue;
    struct switchTemp switchTempValue;
    struct condition2temp conditionTemp;
    struct whileExpression whileExpressionValue;
    struct statement statementValue;
    struct shortCircuit shortCircuitValue;
}

%token INT FLOAT VOID DATAFLOAT DATAINT ID NEWLINE READ PRINT
%token COLON QUESTION DOT LCURLYB RCURLYB LSQUAREB RSQUAREB LPARE RPARE SEMI COMMA ASSIGN
%token IF ELSE CASE BREAK DEFAULT CONTINUE WHILE FOR RETURN SWITCH MAIN
%token LSHIFT RSHIFT PLUSASSIGNMENT MINASSIGNMENT MULASSIGNMENT MODASSIGNMENT DIVASSIGNMENT INCREMENT DECREMENT XOR BITAND BITOR PLUS MINUS DIV MUL MOD
%token NOT AND OR LESSTHAN GREATTHAN LESSEQUAL GREATEQUAL EQUAL NOTEQUAL

%type <idName> DATAFLOAT
%type <idName> DATAINT
%type <idName> ID
%type <shortCircuitValue> CONDITION1 CONDITION2
%type <expressionValue> TERM ID_ARR ASSIGNMENT ASSIGNMENT1 EXPR2 EXPR1 EXPR21 LHS FACTOR FUNC_CALL BR_DIMLIST
%type <whileExpressionValue> WHILEEXP IFEXP N3 P3 Q3 FOREXP TEMP1
%type <statementValue> BODY M2 FORLOOP STATEMENT WHILESTMT STATEMENT_LIST IFSTMT 
%type <quad> M1 M3 Q4
%type <conditionTemp> TP1
%type <switchTempValue> TEMP2
%type <switchCaseValue> CASELIST

%start MAIN_PROG

%%

FUNCTION_DEFINATION: FUNC_HEAD LCURLYB BODY RCURLYB
    {
        deleteVariableList(activeFunctionPointer, scope);
        activeFunctionPointer = NULL;
        scope = 0;
        string s = "function end";
        gen(functionInstruction, s, nextNum);
    }
;

FUNC_HEAD: RES_ID LPARE DECL_PLIST RPARE
    {
        int found = 0;
        searchFunc(activeFunctionPointer, functionEntryRecord, found);
        if(found){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Function " << activeFunctionPointer->name <<  " already declared." << endl;
            errorFound = true;
            delete activeFunctionPointer;
            // cout<<"Function head me activeFunctionPointer deleted"<<endl;
        }   
        else{
            activeFunctionPointer->numOfParam = typeRecordList.size();
            activeFunctionPointer->parameterList = typeRecordList;
            activeFunctionPointer->functionOffset = 0;
            typeRecordList.clear();
            addFunction(activeFunctionPointer, functionEntryRecord);
            scope = 2;
            string s = "function begin _" + activeFunctionPointer->name;
            gen(functionInstruction, s, nextNum);
        }
    }
; 

RES_ID: T ID
    {
        scope=1;
        activeFunctionPointer = new functionEntry;
        activeFunctionPointer->name = string($2);
        activeFunctionPointer->returnType = resultType;
    }
    | VOID ID
    {
        scope=1;
        activeFunctionPointer = new functionEntry;
        activeFunctionPointer->name = string($2);
        activeFunctionPointer->returnType = NULLVOID;
    }
;




DECL_PLIST: DECL_PL
    | %empty
;

DECL_PL: 
    DECL_PARAM
    {
        int found = 0;
        typeRecord* pn = NULL;
        searchParameter(variableRecord->name, typeRecordList, found , pn );
        if (found){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Redeclaration of parameter " << variableRecord->name <<endl;
        } else {
            // cout << "Variable: "<< variableRecord->name << " declared." << endl;
            typeRecordList.push_back(variableRecord);
        }
    }
    | DECL_PL COMMA DECL_PARAM
    {
        int found = 0;
        typeRecord* pn = NULL;
        searchParameter(variableRecord->name, typeRecordList, found, pn);
        if(found){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Redeclaration of parameter " << variableRecord->name <<endl;
        } else {
            // cout << "Variable: "<< variableRecord->name << " declared." << endl;
            typeRecordList.push_back(variableRecord);
        }
    }
;

DECL_PARAM: T ID
    {
        variableRecord = new typeRecord;
        variableRecord->name = string($2);
        variableRecord->type = SIMPLE;
        variableRecord->tag = VARIABLE;
        variableRecord->scope = scope;
        variableRecord->elementType = resultType;
    }
;

BODY: STATEMENT_LIST
    {
        $$.nextList = new vector<int>;
        merge($$.nextList, $1.nextList);
        $$.breakList = new vector<int>;
        merge($$.breakList, $1.breakList);
        $$.continueList = new vector<int>;
        merge($$.continueList, $1.continueList);
    }
    | %empty
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector<int>;
    }
;

STATEMENT_LIST: 
    STATEMENT
    {
        $$.nextList = new vector<int>;
        merge($$.nextList, $1.nextList);
        $$.breakList = new vector<int>;
        merge($$.breakList, $1.breakList);
        $$.continueList = new vector<int>;
        merge($$.continueList, $1.continueList);
    }
    | STATEMENT_LIST STATEMENT
    {
        $$.nextList = new vector<int>;
        merge($$.nextList, $1.nextList);
        merge($$.nextList, $2.nextList);
        $$.breakList = new vector<int>;
        merge($$.breakList, $1.breakList);
        merge($$.breakList, $2.breakList);
        $$.continueList = new vector<int>;
        merge($$.continueList, $1.continueList);
        merge($$.continueList, $2.continueList);
    }
;

VARIABLE_DECLARATION: D SEMI
;

MAIN_PROG: PROG MAINFUNCTION
    | MAINFUNCTION
;

MAINFUNCTION: MAIN_HEAD LCURLYB BODY RCURLYB
    {
        deleteVariableList(activeFunctionPointer, scope);
        activeFunctionPointer=NULL;
        scope=0;
        string s = "function end";
        gen(functionInstruction, s, nextNum);
    }
;

PROG: PROG FUNCTION_DEFINATION
    | PROG VARIABLE_DECLARATION
    | VARIABLE_DECLARATION
    | FUNCTION_DEFINATION
;

MAIN_HEAD: INT MAIN LPARE RPARE
    {   
        scope=1;
        activeFunctionPointer = new functionEntry;
        activeFunctionPointer->name = string("main");
        activeFunctionPointer->returnType = INTEGER;
        activeFunctionPointer->numOfParam = 0;
        activeFunctionPointer->parameterList.clear();
        activeFunctionPointer->variableList.clear();
        activeFunctionPointer->functionOffset = 0;      ;
        typeRecordList.clear();
        searchFunc(activeFunctionPointer, functionEntryRecord, found);
        if (found) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Function " << activeFunctionPointer->name <<  " already declared." << endl;
            delete activeFunctionPointer;
            activeFunctionPointer = NULL;
        }
        else {
            addFunction(activeFunctionPointer, functionEntryRecord);
            scope = 2; 
            string s = "function begin main";
            gen(functionInstruction, s, nextNum);
        }
    }
;

D: T L
    {
        patchDataType(resultType, typeRecordList, scope);
        if(scope > 1){
            insertSymTab(typeRecordList, activeFunctionPointer);
        }
        else if(scope == 0){
            insertGlobalVariables(typeRecordList, globalVariables);
        }
        typeRecordList.clear();
    }
;

T:  INT         { resultType = INTEGER; }
    | FLOAT     { resultType = FLOATING; }
;

L: DEC_ID_ARR
    | L COMMA DEC_ID_ARR
;

DEC_ID_ARR: ID
    {
        int found = 0;
        typeRecord* vn = NULL;
        // cout << "Scope : "<<scope<<endl;
        if(activeFunctionPointer!=NULL && scope > 0){
            searchVariable(string($1), activeFunctionPointer, found, vn, scope);
            if (found) {
                if(vn->isValid==true){
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string($1) << " already declared at same level " << scope << endl ;
                }
                else{
                    if(vn->elementType == resultType){
                        vn->isValid=true;
                        vn->maxDimlistOffset = max(vn->maxDimlistOffset,1);
                        vn->type=SIMPLE;
                    }
                    else {
                        variableRecord = new typeRecord;
                        variableRecord->name = string($1);
                        variableRecord->type = SIMPLE;
                        variableRecord->tag = VARIABLE;
                        variableRecord->scope = scope;
                        variableRecord->isValid=true;
                        variableRecord->maxDimlistOffset=1;
                        typeRecordList.push_back(variableRecord);
                    }
                }
            }
            else if (scope == 2) {
                typeRecord* pn = NULL;
                searchParameter(string($1), activeFunctionPointer->parameterList, found , pn);
                if (found) {
                    // printf("Line no. %d: Vaiable %s is already declared as a parameter with scope %d\n", yylineno, $1, scope);
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string($1) << " already declared in parameters " << endl ;
                }
                else {
                    variableRecord = new typeRecord;
                    variableRecord->name = string($1);
                    variableRecord->type = SIMPLE;
                    variableRecord->tag = VARIABLE;
                    variableRecord->scope = scope;
                    variableRecord->isValid=true;
                    variableRecord->maxDimlistOffset=1;
                    typeRecordList.push_back(variableRecord);
                }
            }
            else {
                variableRecord = new typeRecord;
                variableRecord->name = string($1);
                variableRecord->type = SIMPLE;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->isValid=true;
                variableRecord->maxDimlistOffset=1;
                typeRecordList.push_back(variableRecord);
            }
        }
        else if(scope == 0){
            searchGlobalVariable(string($1), globalVariables, found, vn, scope);
            if (found) {
                // printf("Variable %s already declared at global level \n", $1);
                cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string($1) << " already declared at global level " << endl ;
            }
            else{
                variableRecord = new typeRecord;
                variableRecord->name = string($1);
                variableRecord->type = SIMPLE;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->isValid=true;
                variableRecord->maxDimlistOffset=1;
                // cout<<"variable name: "<<variableRecord->name<<endl;
                typeRecordList.push_back(variableRecord);
            }
        }
        else {
            errorFound = true;
        }
    }
    | ID ASSIGN ASSIGNMENT
    {
        int found = 0;
        typeRecord* vn = NULL;
        if(activeFunctionPointer!=NULL){
            searchVariable(string($1), activeFunctionPointer, found, vn, scope);
            bool varCreated = false;;
            if (found) {
                if(vn->isValid==true){
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string($1) << " already declared at same level " << scope << endl ;
                }
                else{
                    if(vn->elementType == resultType){
                        vn->isValid=true;
                        vn->maxDimlistOffset = max(vn->maxDimlistOffset,1);
                        vn->type=SIMPLE;
                        varCreated = true;
                    }
                    else {
                        variableRecord = new typeRecord;
                        variableRecord->name = string($1);
                        variableRecord->type = SIMPLE;
                        variableRecord->tag = VARIABLE;
                        variableRecord->scope = scope;
                        variableRecord->isValid=true;
                        variableRecord->maxDimlistOffset=1;
                        typeRecordList.push_back(variableRecord);
                        varCreated = true;
                    }
                }
            }
            else if (scope == 2) {
                typeRecord* pn = NULL;
                searchParameter(string($1), activeFunctionPointer->parameterList, found , pn);
                if (found) {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. :" << yylineno << " Variable " << string($1) << " already declared at parameter level " << endl ;
                } 
                else {
                    variableRecord = new typeRecord;
                    variableRecord->name = string($1);
                    variableRecord->type = SIMPLE;
                    variableRecord->tag = VARIABLE;
                    variableRecord->scope = scope;
                    variableRecord->maxDimlistOffset=1;
                    variableRecord->isValid=true;
                    typeRecordList.push_back(variableRecord);
                    varCreated = true;
                }
            }
            else {
                variableRecord = new typeRecord;
                variableRecord->name = string($1);
                variableRecord->type = SIMPLE;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->maxDimlistOffset=1;
                variableRecord->isValid=true;
                typeRecordList.push_back(variableRecord);
                varCreated = true;
            }
            if(varCreated){
                if ($3.type == ERRORTYPE) {
                    errorFound = true;
                }
                else if ($3.type == NULLVOID) {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Cannot assign void to non-void type " << string($1) << endl;
                    errorFound = true;
                }
                else {
                    string registerName;
                    if (resultType == INTEGER && $3.type == FLOATING) {
                        registerName = temporarySet.getRegister();
                        string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*($3.registerName));
                    }
                    else if(resultType == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                        registerName = temporarySet.getFloatRegister();
                        string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*($3.registerName));
                    }
                    else {
                        registerName = *($3.registerName);
                    }
                    string dataType = elementTypeMapper(resultType);
                    dataType += "_" + to_string(scope);
                    string s =  "_" + string($1) + "_" + dataType + " = " + registerName ;
                    gen(functionInstruction, s, nextNum);
                    temporarySet.freeRegister(registerName);
                }   
            }
        }
        else if(scope == 0){
            cout << BOLD(FRED("ERROR : ")) << "Line No " << yylineno << ": ID assignments not allowed in global level : Variable " << string($1) << endl;
            errorFound = true;
        }
        else {
            errorFound = true;
        }
    }
    | ID DEC_BR_DIMLIST
    {  
        if (activeFunctionPointer != NULL) {
            int found = 0;
            typeRecord* vn = NULL;
            searchVariable(string($1), activeFunctionPointer, found, vn,scope); 
            if (found) {
                if(vn->isValid==true){
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Variable " << string($1) << " already declared at same level " << scope << endl;
                }
                else{
                    if(vn->elementType == resultType){
                        vn->isValid=true;
                        int a=1;
                        for(auto it : decDimensionList){
                            a*=(it);
                        }
                        vn->maxDimlistOffset = max(vn->maxDimlistOffset,a);
                        if(vn->type==ARRAY){
                            vn->dimensionList.clear();
                        }
                        vn->type=ARRAY;
                        vn->dimensionList = decDimensionList;
                    }
                    else {
                        variableRecord = new typeRecord;
                        variableRecord->name = string($1);
                        variableRecord->type = ARRAY;
                        variableRecord->tag = VARIABLE;
                        variableRecord->scope = scope;
                        variableRecord->dimensionList = decDimensionList;
                        variableRecord->isValid=true;
                        int a=1;
                        for(auto it : decDimensionList){
                            a*=(it);
                        }
                        variableRecord->maxDimlistOffset = a;
                        typeRecordList.push_back(variableRecord);
                    }
                }
            }
            else if (scope == 2) {
                typeRecord* pn = NULL;
                searchParameter(string($1), activeFunctionPointer->parameterList, found, pn);
                if (found) {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Variable " << string($1) << " already declared at parameter level " << endl;
                } 
                else {
                    variableRecord = new typeRecord;
                    variableRecord->name = string($1);
                    variableRecord->type = ARRAY;
                    variableRecord->tag = VARIABLE;
                    variableRecord->scope = scope;
                    variableRecord->dimensionList = decDimensionList;
                    variableRecord->isValid=true;
                    int a=1;
                    for(auto it : decDimensionList){
                        a*=(it);
                    }
                    variableRecord->maxDimlistOffset = a;
                    typeRecordList.push_back(variableRecord);
                }
            }
            else{
                variableRecord = new typeRecord;
                variableRecord->name = string($1);
                variableRecord->type = ARRAY;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->dimensionList = decDimensionList;
                variableRecord->isValid=true;
                int a=1;
                for(auto it : decDimensionList){
                    a*=(it);
                }
                variableRecord->maxDimlistOffset = a;
                typeRecordList.push_back(variableRecord);
            }
            // decDimensionList.clear();
        }
        else if(scope == 0){
            typeRecord* vn = NULL;
            searchGlobalVariable(string($1), globalVariables, found, vn, scope);
            if (found) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Variable " << string($1) << " already declared at global level " << endl;
            }
            else{
                variableRecord = new typeRecord;
                variableRecord->name = string($1);
                variableRecord->type = ARRAY;
                variableRecord->tag = VARIABLE;
                variableRecord->scope = scope;
                variableRecord->dimensionList = decDimensionList;
                variableRecord->isValid=true;
                int a=1;
                for(auto it : decDimensionList){
                    a*=(it);
                }
                variableRecord->maxDimlistOffset = a;
                // cout<<"variable name: "<<variableRecord->name<<endl;
                typeRecordList.push_back(variableRecord);   
            }
        }   
        else{
            errorFound = 1;
        }
        decDimensionList.clear();
    }
;

DEC_BR_DIMLIST:
    DEC_BR_DIMLIST LSQUAREB DATAINT RSQUAREB 
    {
        decDimensionList.push_back(atoi($3));
    } 
    | LSQUAREB DATAINT RSQUAREB
    {
        decDimensionList.push_back(atoi($2));
    }
;

EXPR1: NOT EXPR21
    {
        $$.type = $2.type;
        if ($2.type != ERRORTYPE && $2.type != NULLVOID) {
            $$.registerName = $2.registerName;
            string s = (*($$.registerName)) + " = ~" + (*($2.registerName));   
            gen(functionInstruction, s, nextNum);
        }
    }
    | EXPR21
    {
        $$.type = $1.type;
        if ($1.type != ERRORTYPE && $1.type != NULLVOID) {
            $$.registerName = $1.registerName;    
        }
    }
;

EXPR21: EXPR2 EQUAL EXPR2
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else {
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " == " + (*($3.registerName))   ;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 LESSTHAN EXPR2 
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " < " + (*($3.registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 GREATTHAN EXPR2
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " > " + (*($3.registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 NOTEQUAL EXPR2
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " != " + (*($3.registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 
    {
        $$.type = $1.type; 
        if($$.type == ERRORTYPE){
            errorFound = true;
        }
        else{
            if($1.type != NULLVOID){
                $$.registerName = new string(*($1.registerName)); 
                delete $1.registerName; 
            }
        }    
    }
    | EXPR2 LESSEQUAL EXPR2
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " <= " + (*($3.registerName));   
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($3.registerName));  
        }   
    }
    | EXPR2 GREATEQUAL EXPR2
    {
        if($1.type == ERRORTYPE || $3.type == ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $3.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ":Both the expessions should not be  NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());     
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " >= " + (*($3.registerName));  
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($3.registerName));  
        }   
    } 
;

EXPR2:  EXPR2 PLUS TERM
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE; 
            errorFound = true; 
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(temporarySet.getRegister());
                else
                    $$.registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " + " + (*($3.registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($1.registerName));
                temporarySet.freeRegister(*($3.registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }
    }
    | EXPR2 MINUS TERM
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;  
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(temporarySet.getRegister());
                else
                    $$.registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " - " + (*($3.registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($1.registerName));
                temporarySet.freeRegister(*($3.registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }
    }
    | TERM 
    { 
        $$.type = $1.type; 
        if ($1.type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            if($1.type!= NULLVOID){
                $$.registerName = new string(*($1.registerName)); 
                delete $1.registerName;
            }         
        } 
    }
;


FUNC_CALL: ID LPARE PARAMLIST RPARE
    {
        callFunctionPointer = new functionEntry;
        callFunctionPointer->name = string($1);
        callFunctionPointer->parameterList = typeRecordList;
        callFunctionPointer->numOfParam = typeRecordList.size();
        int found = 0;
        // printFunction(activeFunctionPointer);
        // printFunction(callFunctionPointer);
        int vfound=0;
        typeRecord* vn;
        searchVariable(callFunctionPointer->name,activeFunctionPointer,vfound,vn,scope);
        if (vfound) {
            $$.type = ERRORTYPE;
            cout<< BOLD(FRED("ERROR : ")) << "Line no." << yylineno << ": called object "<< callFunctionPointer->name << " is not a function or function pointer"<< endl;
        }
        else {
            compareFunc(callFunctionPointer,functionEntryRecord,found);
            $$.type = ERRORTYPE;
            if (found == 0) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "No function with name " << string($1) << " exists" << endl;
            }
            else if (found == -1) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "call parameter list does not match with defined paramters of function " << string($1) << endl;
            }
            else {
                $$.type = callFunctionPointer->returnType;
                if(callFunctionPointer->returnType == INTEGER){
                    $$.registerName = new string(temporarySet.getRegister());
                    gen(functionInstruction, "refparam " + (*($$.registerName)), nextNum);
                    gen(functionInstruction, "call _" + callFunctionPointer->name + ", " + to_string(typeRecordList.size() + 1 ), nextNum);
                }
                else if(callFunctionPointer->returnType == FLOATING){
                    $$.registerName = new string(temporarySet.getFloatRegister());
                    gen(functionInstruction, "refparam " + (*($$.registerName)), nextNum);
                    gen(functionInstruction, "call _" + callFunctionPointer->name + ", " + to_string(typeRecordList.size() + 1 ), nextNum);
                }
                else if (callFunctionPointer->returnType == NULLVOID) {
                    $$.registerName = NULL;
                    gen(functionInstruction, "call _" + callFunctionPointer->name + ", " + to_string(typeRecordList.size()), nextNum);
                }
                else {
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Illegal return type of function " << callFunctionPointer->name << endl;
                }
            }
        }
        typeRecordList.clear();
        typeRecordList.swap(parameterListStack.top());
        parameterListStack.pop();
    }
;

PARAMLIST: PLIST
    | {parameterListStack.push(typeRecordList); typeRecordList.clear();} %empty 
;

STATEMENT:
    FORLOOP
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
    } 
    | VARIABLE_DECLARATION
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
    }
    | IFSTMT
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        merge($$.continueList, $1.continueList);
        merge($$.breakList, $1.breakList);

    }
    | WHILESTMT
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
    }
    | ASSIGNMENT SEMI
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        if ($1.type != NULLVOID && $1.type != ERRORTYPE)
            temporarySet.freeRegister(*($1.registerName));
    } 
    | LCURLYB {scope++;} BODY RCURLYB
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        deleteVariableList(activeFunctionPointer, scope);
        scope--;
        merge($$.continueList, $3.continueList);
        merge($$.breakList, $3.breakList);
    }
    | BREAK SEMI
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        $$.breakList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
    | SWITCHCASE
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
    }
    | RETURN ASSIGNMENT1 SEMI 
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        if ($2.type != ERRORTYPE && activeFunctionPointer != NULL) {
            if (activeFunctionPointer->returnType == NULLVOID && $2.type != NULLVOID) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": function " << activeFunctionPointer->name << " has void return type not " << $2.type << endl;
            }
            else if (activeFunctionPointer->returnType != NULLVOID && $2.type == NULLVOID) {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": function " << activeFunctionPointer->name << " has non-void return type" << endl;
            }
            else {
                string s;
                if (activeFunctionPointer->returnType != NULLVOID && $2.type != NULLVOID) {
                    if ($2.type == INTEGER && activeFunctionPointer->returnType == FLOATING)  {
                        string floatReg = temporarySet.getFloatRegister();
                        s = floatReg + " = " + "convertToFloat(" + *($2.registerName) + ")";
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        s = "return " + floatReg;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*($2.registerName));
                        temporarySet.freeRegister(floatReg);
                    }
                    else if ($2.type == FLOATING && activeFunctionPointer->returnType == INTEGER) {
                        string intRegister = temporarySet.getRegister();
                        s = intRegister + " = " + "convertToInt(" + *($2.registerName) + ")";
                        cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                        gen(functionInstruction, s, nextNum);
                        s = "return " + intRegister;
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*($2.registerName));
                        temporarySet.freeRegister(intRegister);
                    }
                    else {
                        s = "return " + *($2.registerName);
                        gen(functionInstruction, s, nextNum);
                        temporarySet.freeRegister(*($2.registerName));
                    }
                }
                else if (activeFunctionPointer->returnType == NULLVOID && $2.type == NULLVOID) {
                    s = "return";
                    gen(functionInstruction, s, nextNum);
                }
                else {
                    errorFound = 1;
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": Exactly one of function " << activeFunctionPointer->name << "and this return statement has void return type" << endl;
                    if ($2.type != NULLVOID) temporarySet.freeRegister(*($2.registerName));
                }
            }
        }
    }
    | CONTINUE SEMI
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        $$.continueList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
    | PRINT ID_ARR SEMI
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        if($2.type == ERRORTYPE){
            errorFound = true;
        }
        else{
            string registerName;
            if ($2.type == INTEGER){
                registerName = temporarySet.getRegister();
            }
            else {
                registerName = temporarySet.getFloatRegister();
            }
            string s = registerName + " = " + (*($2.registerName)) ;
            gen(functionInstruction, s, nextNum);
            s = "print " + registerName;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(registerName);
            if ($2.offsetRegName != NULL) temporarySet.freeRegister(*($2.offsetRegName));
        }
    }
    | error SEMI
    {
        errorFound = 1;
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error") << endl;
    }
    | error
    {
        errorFound = 1;
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error") << endl;
    }
    | READ ID_ARR SEMI
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        if($2.type == ERRORTYPE){
            errorFound = true;
        }
        else{
            string registerName;
            if ($2.type == INTEGER){
                registerName = temporarySet.getRegister();
            }
            else {
                registerName = temporarySet.getFloatRegister();
            }
            string s;
            s = "read " + registerName;
            gen(functionInstruction, s, nextNum);
            s = (*($2.registerName)) + " = " +  registerName;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(registerName);
            if ($2.offsetRegName != NULL) temporarySet.freeRegister(*($2.offsetRegName));
        }
    }
;

PLIST: PLIST COMMA ASSIGNMENT
    {
        variableRecord = new typeRecord;
        variableRecord->elementType = $3.type;
        if ($3.type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            variableRecord->name = *($3.registerName);
            variableRecord->type = SIMPLE;
            gen(functionInstruction, "param " +  *($3.registerName), nextNum);
            temporarySet.freeRegister(*($3.registerName));
        }
        typeRecordList.push_back(variableRecord);
    }
    | {parameterListStack.push(typeRecordList); typeRecordList.clear();} ASSIGNMENT
    {
        variableRecord = new typeRecord;
        variableRecord->elementType = $2.type;
        if ($2.type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            variableRecord->name = *($2.registerName);
            variableRecord->type = SIMPLE; 
            gen(functionInstruction, "param " +  *($2.registerName), nextNum);   
            temporarySet.freeRegister(*($2.registerName));
        }
        typeRecordList.push_back(variableRecord);
    }
;

IFSTMT: IFEXP LCURLYB BODY RCURLYB 
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;
        $$.nextList= new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList= new vector<int>;
        merge($$.nextList, $1.falseList);
        merge($$.breakList, $3.breakList);
        merge($$.continueList, $3.continueList);
        backPatch($$.nextList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
    | IFEXP LCURLYB BODY RCURLYB {deleteVariableList(activeFunctionPointer,scope);} M2 ELSE M1 LCURLYB BODY RCURLYB
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;
        $$.nextList= new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList= new vector<int>;
        backPatch($1.falseList,$8,functionInstruction);
        merge($$.nextList,$6.nextList );
        backPatch($$.nextList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        merge($$.breakList, $3.breakList);
        merge($$.continueList, $3.continueList);
        merge($$.breakList, $10.breakList);
        merge($$.continueList, $10.continueList);
    }
;

IFEXP: 
    IF error RPARE
    {
        errorFound = 1;
        $$.falseList = new vector <int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error in if, discarding tokens till RPARE") << endl;
        scope++;
    }
    | IF LPARE ASSIGNMENT RPARE 
    {
        if($3.type != ERRORTYPE && $3.type!=NULLVOID){
            $$.falseList = new vector <int>;
            $$.falseList->push_back(nextNum);
            if($3.type == NULLVOID){
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << "condition in if statement can't be empty" << endl;
                errorFound=true;
            }
            gen(functionInstruction, "if "+ (*($3.registerName)) + " == 0 goto L", nextNum);
            scope++;
            temporarySet.freeRegister(*($3.registerName));
        } 
    }
;

ASSIGNMENT: CONDITION1
    {
        $$.type = $1.type;
        if($$.type != ERRORTYPE && $$.type != NULLVOID) {
            $$.registerName = $1.registerName;
            if($1.jumpList!=NULL){
                vector<int>* queryList = new vector<int>;
                queryList->push_back(nextNum);
                gen(functionInstruction,"goto L",nextNum);
                backPatch($1.jumpList, nextNum, functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                gen(functionInstruction,(*($$.registerName)) + " = 1",nextNum) ;
                backPatch(queryList,nextNum,functionInstruction);
                queryList->clear();
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
            }
        }
    }
    | LHS MODASSIGNMENT ASSIGNMENT
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if ($3.type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, temporaryRegister;
            if($1.type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*($1.registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*($1.registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " % " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) temporarySet.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS PLUSASSIGNMENT ASSIGNMENT
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if ($3.type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";  
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, temporaryRegister;
            if($1.type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*($1.registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*($1.registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " + " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) temporarySet.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS MINASSIGNMENT ASSIGNMENT
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if ($3.type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")"; 
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, temporaryRegister;
            if($1.type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*($1.registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*($1.registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " - " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) temporarySet.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS MULASSIGNMENT ASSIGNMENT
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if ($3.type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")"; 
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";  
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, temporaryRegister;
            if($1.type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*($1.registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*($1.registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " * " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) temporarySet.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS DIVASSIGNMENT ASSIGNMENT
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if ($3.type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s, temporaryRegister;
            if($1.type == INTEGER){
                temporaryRegister = temporarySet.getRegister();
                s = temporaryRegister + " = " + (*($1.registerName));
                gen(functionInstruction, s, nextNum);
            }
            else{
                temporaryRegister = temporarySet.getFloatRegister();
                s = temporaryRegister + " = " + (*($1.registerName));   
                gen(functionInstruction, s, nextNum);
            }
            s = registerName + " = " + registerName + " / " + temporaryRegister;
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(temporaryRegister);
            s = (*($1.registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) temporarySet.freeRegister(*($1.offsetRegName));
        }
    }
    | LHS ASSIGN ASSIGNMENT
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else if ($3.type == NULLVOID) {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout << "Cannot assign void to non-void type " << *($1.registerName) << endl;
            $$.type = ERRORTYPE;
            errorFound = true;
        }
        else {
            $$.type = $1.type;
            string registerName;
            if ($1.type == INTEGER && $3.type == FLOATING) {
                registerName = temporarySet.getRegister();
                string s = registerName + " = convertToInt(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($3.registerName));
            }
            else if($1.type == FLOATING && ($3.type == INTEGER || $3.type == BOOLEAN)) {
                registerName = temporarySet.getFloatRegister();
                string s = registerName + " = convertToFloat(" + (*($3.registerName)) + ")";   
                cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                gen(functionInstruction, s, nextNum); 
                temporarySet.freeRegister(*($3.registerName));
            }
            else {
                registerName = *($3.registerName);
            }
            string s = (*($1.registerName)) + " = " + registerName ;
            gen(functionInstruction, s, nextNum);
            $$.registerName = new string(registerName);
            if ($1.offsetRegName != NULL) temporarySet.freeRegister(*($1.offsetRegName));
        }
    }
;

SWITCHCASE: SWITCH LPARE ASSIGNMENT RPARE TEMP1 LCURLYB  CASELIST RCURLYB 
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;

        int q=nextNum;
        vector<int>* queryList = new vector<int>;
        queryList->push_back(q);
        gen(functionInstruction, "goto L", nextNum);
        backPatch($5.falseList, nextNum, functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        reverse($7.casePair->begin(), $7.casePair->end());
        for(auto it : *($7.casePair)){
            if(it.first == "default"){
                gen(functionInstruction, "goto L"+to_string(it.second), nextNum);
            }
            else{
                gen(functionInstruction, "if "+ (*($3.registerName)) +" == "+ it.first + " goto L" + to_string(it.second), nextNum);
            }
        }
        $7.casePair->clear();
        backPatch(queryList, nextNum, functionInstruction);
        backPatch($7.breakList, nextNum, functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
;

TEMP1: %empty
    {
        $$.begin=nextNum;
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
        scope++;
    }
;

TEMP2:%empty
    {
        $$.casePair = new vector<pair<string,int>>;

    }
;

CASELIST:
    CASE MINUS DATAINT TEMP2 {
        $4.casePair->push_back(make_pair("-"+string($3), nextNum));
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        } COLON BODY 
    CASELIST
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        $$.casePair = new vector<pair<string,int>>;
        merge($$.continueList,$8.continueList);
        merge($$.breakList, $8.breakList);
        merge($$.nextList, $8.nextList);
        merge($$.continueList,$7.continueList);
        merge($$.breakList, $7.breakList);
        merge($$.nextList, $7.nextList);
        mergeSwitch($$.casePair, $8.casePair);
        mergeSwitch($$.casePair, $4.casePair);
    }
    |
    CASE DATAINT TEMP2 {
        $3.casePair->push_back(make_pair(string($2), nextNum));
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
        } COLON BODY 
    CASELIST
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        $$.casePair = new vector<pair<string,int>>;
        merge($$.continueList,$6.continueList);
        merge($$.breakList, $6.breakList);
        merge($$.nextList, $6.nextList);
        merge($$.continueList,$7.continueList);
        merge($$.breakList, $7.breakList);
        merge($$.nextList, $7.nextList);
        mergeSwitch($$.casePair, $7.casePair);
        mergeSwitch($$.casePair, $3.casePair);
    }
    | %empty
    {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.continueList = new vector <int>;
        $$.casePair = new vector<pair<string,int>>;
    }
    | DEFAULT COLON TEMP2 {
        $3.casePair->push_back(make_pair("default", nextNum));
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
     BODY {
        $$.nextList = new vector<int>;
        $$.breakList = new vector<int>;
        $$.casePair = new vector<pair<string,int>>;
        $$.continueList = new vector <int>;
        merge($$.continueList,$5.continueList);
        merge($$.breakList, $5.breakList);
        merge($$.nextList, $5.nextList);
        mergeSwitch($$.casePair, $3.casePair);
    }
;

M3: %empty
    { 
        $$ = nextNum;
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum); 
    }
;

LHS: ID_ARR  
    {
        $$.type = $1.type;
        if ($$.type != ERRORTYPE) {
            $$.registerName = $1.registerName;
            $$.offsetRegName = $1.offsetRegName;
        } 
    } 
;

N3: %empty
    { 
        $$.begin = nextNum; 
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
;

FORLOOP: FOREXP Q4 LCURLYB BODY RCURLYB
    {
        deleteVariableList(activeFunctionPointer, scope);
        scope--;
        gen(functionInstruction, "goto L" + to_string($1.begin), nextNum); 
        merge($1.falseList,$4.breakList);
        backPatch($4.continueList,$1.begin, functionInstruction);
        backPatch($1.falseList, nextNum, functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum); 
    }
;

FOREXP: FOR LPARE ASSIGNMENT1 SEMI M3 ASSIGNMENT1 Q3 {
        if($6.type!=NULLVOID){
            gen(functionInstruction, "if "+ (*($6.registerName)) + " == 0 goto L", nextNum);
        }
    } P3 SEMI ASSIGNMENT1 N3 RPARE 
    {
        backPatch($12.falseList,$5,functionInstruction);
        backPatch($9.falseList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum); 
        $$.falseList = new vector<int>;
        if($6.type!=NULLVOID){
            $$.falseList->push_back($7.begin);
        }
        $$.begin = $9.begin;
        scope++;
        if($3.type!=NULLVOID){
            temporarySet.freeRegister(*($3.registerName));
        }
        if($6.type!=NULLVOID){
            temporarySet.freeRegister(*($6.registerName));
        }
        if($11.type!=NULLVOID){
            temporarySet.freeRegister(*($11.registerName));
        }
    }
    | FOR error RPARE
    {
        errorFound = 1;
        $$.falseList = new vector<int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error in for loop, discarded token till RPARE") << endl;
        scope++;
    }
;

P3: %empty 
    { 
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
        $$.begin = nextNum; 
        gen(functionInstruction, "L"+to_string(nextNum)+":", nextNum);
    }
;

Q3: %empty
    {
        $$.begin = nextNum;
        $$.falseList = new vector<int>;
        $$.falseList->push_back(nextNum);
    }
;

Q4: %empty
    {
        $$ = nextNum;
    }
;

ASSIGNMENT1: ASSIGNMENT
    {
        $$.type= $1.type;
        if ($1.type != ERRORTYPE && $1.type != NULLVOID) {
            $$.registerName = $1.registerName;
        }
    }
    | %empty {
        $$.type = NULLVOID;
    }
;

M2: %empty
    {
        $$.nextList = new vector<int>;
        ($$.nextList)->push_back(nextNum);
        gen(functionInstruction, "goto L", nextNum);
    }
;


M1: %empty
    {
        $$=nextNum;
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
;

WHILESTMT:  WHILEEXP LCURLYB BODY RCURLYB 
    {
        deleteVariableList(activeFunctionPointer,scope);
        scope--;

        gen(functionInstruction, "goto L" + to_string($1.begin), nextNum);
        backPatch($3.nextList, $1.begin, functionInstruction);
        backPatch($3.continueList, $1.begin, functionInstruction);
        $$.nextList = new vector<int>;
        merge($$.nextList, $1.falseList);
        merge($$.nextList, $3.breakList);
        backPatch($$.nextList,nextNum,functionInstruction);
        gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
    }
;

WHILEEXP: WHILE M1 LPARE ASSIGNMENT RPARE
    {
        scope++;
        if($4.type == NULLVOID || $4.type == ERRORTYPE){
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
            cout<<"Expression in if statement can't be empty"<<endl;
            errorFound = true;
        }
        else{
            $$.falseList = new vector<int>;
            ($$.falseList)->push_back(nextNum);
            gen(functionInstruction, "if " + *($4.registerName) + "== 0 goto L", nextNum);
            $$.begin = $2; 
        }
    }
    | WHILE error RPARE
    {   
        $$.falseList = new vector<int>;
        cout << BOLD(FRED("ERROR : ")) << FYEL("Line no. " + to_string(yylineno) + ": Syntax error in while loop, discarding tokens till RPARE") << endl;
        scope++;
    }
;

TP1: %empty
{
    $$.temp = new vector<int>;
}
;

BR_DIMLIST: LSQUAREB ASSIGNMENT RSQUAREB
    {
        if ($2.type == INTEGER) {
            dimensionList.push_back(*($2.registerName));
        }
        else {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }
    }    
    | BR_DIMLIST LSQUAREB ASSIGNMENT RSQUAREB 
    {
        if ($3.type == INTEGER) {
            dimensionList.push_back(*($3.registerName));
        }
        else {
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "One of the dimension of an array cannot be evaluated to integer" << endl;
        }  
    }
;

CONDITION1: 
    CONDITION2
    {
        $$.type = $1.type;
        if ($$.type != ERRORTYPE && $$.type != NULLVOID) {
            $$.registerName = $1.registerName; 
            if($1.jumpList!=NULL){
                vector<int>* queryList = new vector<int>;
                queryList->push_back(nextNum);
                gen(functionInstruction,"goto L",nextNum);
                backPatch($1.jumpList, nextNum, functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                gen(functionInstruction,(*($$.registerName)) + " = 0",nextNum) ;
                backPatch(queryList,nextNum,functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                queryList->clear();   
            }
        }
    }
    | CONDITION1 TP1
    {
        if($1.type!=ERRORTYPE){
            $2.temp->push_back(nextNum);
            gen(functionInstruction, "if " + *($1.registerName) + "!= 0 goto L", nextNum);

        }
    }
     OR CONDITION2
    {
        if($1.type==ERRORTYPE || $5.type==ERRORTYPE){
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $5.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ": Both the expessions should not be NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());
            vector<int>* queryList = new vector<int>;
            if($5.jumpList!=NULL){
                queryList->push_back(nextNum);
                gen(functionInstruction,"goto L",nextNum);
                backPatch($5.jumpList, nextNum, functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                gen(functionInstruction,(*($5.registerName)) + " = 0",nextNum) ;
                backPatch(queryList,nextNum,functionInstruction);
                gen(functionInstruction, "L" + to_string(nextNum) + ":", nextNum);
                queryList->clear();
            }
            
            $$.jumpList = new vector<int>;
            merge($$.jumpList,$1.jumpList);
            
            merge($$.jumpList, $2.temp);
            ($$.jumpList)->push_back(nextNum);
            gen(functionInstruction, "if " + *($5.registerName) + "!= 0 goto L", nextNum);
            string s = (*($$.registerName)) + " = 0";   
            gen(functionInstruction,s,nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($5.registerName)); 
        }
    }
;  


CONDITION2: CONDITION2 TP1
    {
      if ($1.type!=ERRORTYPE ){

          ($2.temp)->push_back(nextNum);
         gen(functionInstruction, "if " + *($1.registerName) + " == 0 " +" goto L", nextNum);
      } 
    }
    AND EXPR1 
    {
        if ($1.type==ERRORTYPE || $5.type==ERRORTYPE) {
            $$.type = ERRORTYPE;
        }
        else if($1.type == NULLVOID || $5.type == NULLVOID){
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. "<< yylineno << ": Both the expessions should not be NULL" << endl;
        }
        else{
            $$.type = BOOLEAN;
            $$.registerName = new string(temporarySet.getRegister());
            $$.jumpList = new vector<int>;
            merge($$.jumpList,$1.jumpList);
            vector<int>* queryList = new vector<int>;

            merge($$.jumpList, $2.temp);
            ($$.jumpList)->push_back(nextNum);
            gen(functionInstruction, "if " + *($5.registerName) + " == 0 "+" goto L", nextNum);

            string s = (*($$.registerName)) + " = 1";   
            gen(functionInstruction,s,nextNum);
            temporarySet.freeRegister(*($1.registerName));
            temporarySet.freeRegister(*($5.registerName));   
        }
    }
    | EXPR1
    {
        $$.type = $1.type;
        if ($1.type != ERRORTYPE && $1.type != NULLVOID) {
            $$.registerName = $1.registerName; 
            $$.jumpList = new vector<int>;
            $$.jumpList=NULL;   
        }
    }
;

TERM: TERM MUL FACTOR
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(temporarySet.getRegister());
                else
                    $$.registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " * " + (*($3.registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($1.registerName));
                temporarySet.freeRegister(*($3.registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }
    }
    | TERM DIV FACTOR  
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
        $$.type = ERRORTYPE;  
        }
        else {
            if (arithmeticCompatible($1.type, $3.type)) {
                $$.type = compareTypes($1.type,$3.type);

                if ($1.type == INTEGER && $3.type == FLOATING) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($1.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($1.registerName));
                    $1.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }
                else if ($1.type == FLOATING && $3.type == INTEGER) {
                    string newReg = temporarySet.getFloatRegister();
                    string s = newReg + " = " + "convertToFloat(" + (*($3.registerName)) + ")";
                    cout << BOLD(FBLU("Warning : ")) << FCYN("Line No. "+to_string(yylineno)+":Implicit Type Conversion") << endl;
                    temporarySet.freeRegister(*($3.registerName));
                    $3.registerName = &newReg;
                    gen(functionInstruction, s, nextNum);
                }

                if ($$.type == INTEGER) 
                    $$.registerName = new string(temporarySet.getRegister());
                else
                    $$.registerName = new string(temporarySet.getFloatRegister());
                    
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " / " + (*($3.registerName));   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($1.registerName));
                temporarySet.freeRegister(*($3.registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }   
    }  
    | FACTOR 
    { 
        $$.type = $1.type; 
        if ($1.type == ERRORTYPE) {
            errorFound = true;
        }
        else {
            if($1.type != NULLVOID){
                $$.registerName = new string(*($1.registerName)); 
                delete $1.registerName;
            }  
        } 
    }
    | TERM MOD FACTOR
    {
        if ($1.type == ERRORTYPE || $3.type == ERRORTYPE) {
            $$.type = ERRORTYPE;  
        }
        else {
            if ($1.type == INTEGER && $3.type == INTEGER) {
                $$.type = INTEGER;
                $$.registerName = new string(temporarySet.getRegister());  
                string s = (*($$.registerName)) + " = " + (*($1.registerName)) + " % " + (*($3.registerName));;   
                gen(functionInstruction, s, nextNum);
                temporarySet.freeRegister(*($1.registerName));
                temporarySet.freeRegister(*($3.registerName));   
            }
            else {
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Type mismatch in expression" << endl;
                $$.type = ERRORTYPE;
            }
        }   
    }
;

FACTOR: 
    INCREMENT ID_ARR
    {
        if ($2.type == INTEGER) {
            $$.type = INTEGER;
            string newReg = temporarySet.getRegister();
            string s = newReg + " = " + (*($2.registerName)); // T2 = i
            gen(functionInstruction, s, nextNum);
            string newReg2 = temporarySet.getRegister();
            $$.registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " + 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*($2.registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg); 
            if($2.offsetRegName != NULL){
                temporarySet.freeRegister((*($2.offsetRegName)));
            }     
        }
        else {
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable "<<*($2.registerName) << endl; 
        }
    } 
    | DECREMENT ID_ARR
    {
        if ($2.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = temporarySet.getRegister();
            string s = newReg + " = " + (*($2.registerName)); // T2 = i
            gen(functionInstruction, s, nextNum);
            string newReg2 = temporarySet.getRegister();
            $$.registerName = new string(newReg2);
            s = newReg2 + " = " + newReg + " - 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*($2.registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg);
            if($2.offsetRegName != NULL){
                temporarySet.freeRegister((*($2.offsetRegName)));
            }         
        }
        else {
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable " << *($2.registerName) << endl; 
        }
    }
    | ID_ARR  
    { 
        $$.type = $1.type;
        if ($$.type != ERRORTYPE) {
            if ($$.type == INTEGER)
                $$.registerName = new string(temporarySet.getRegister());
            else $$.registerName = new string(temporarySet.getFloatRegister());
            string s = (*($$.registerName)) + " = " + (*($1.registerName)) ;
            gen(functionInstruction, s, nextNum);
            if($1.offsetRegName != NULL){
                temporarySet.freeRegister((*($1.offsetRegName)));
            }
        }
    }
    | LPARE ASSIGNMENT RPARE 
    { 
        $$.type = $2.type; 
        if ($2.type != ERRORTYPE) {
            $$.registerName = $2.registerName;
        }
    }
    | MINUS ID_ARR
    {
        $$.type = $2.type;
        if($2.type != ERRORTYPE){
            string s="";
            if ($$.type == INTEGER){
                $$.registerName = new string(temporarySet.getRegister());
                string temp=temporarySet.getRegister();
                string temp1=temporarySet.getRegister();
                gen(functionInstruction, temp + " = 0", nextNum);
                gen(functionInstruction, temp1 + " = " +  (*($2.registerName)), nextNum);
                s = (*($$.registerName)) + " = " + temp + " -" + temp1 ;
                temporarySet.freeRegister(temp);
                temporarySet.freeRegister(temp1);
            }
            else{ 
                $$.registerName = new string(temporarySet.getFloatRegister());
                string temp=temporarySet.getFloatRegister();
                string temp1=temporarySet.getRegister();
                gen(functionInstruction, temp + " = 0", nextNum);
                gen(functionInstruction, temp1 + " = " +  (*($2.registerName)), nextNum);
                s = (*($$.registerName)) + " = 0 -" + temp1 ;
                temporarySet.freeRegister(temp);
                temporarySet.freeRegister(temp1);
            }
            // string s = (*($$.registerName)) + " = 0 -" + (*($2.registerName)) ;
            gen(functionInstruction, s, nextNum);
            if($2.offsetRegName != NULL){
                temporarySet.freeRegister((*($2.offsetRegName)));
            }
        }       
    }
    | DATAINT    
    { 
        $$.type = INTEGER; 
        $$.registerName = new string(temporarySet.getRegister());
        string s = (*($$.registerName)) + " = " + string($1) ;
        gen(functionInstruction, s, nextNum);  
    }
    | MINUS DATAFLOAT
    {
        $$.type = FLOATING;
        $$.registerName = new string(temporarySet.getFloatRegister());
        string s = (*($$.registerName)) + " = " + string($2) ;
        gen(functionInstruction, s, nextNum);  
    }
    | DATAFLOAT  
    { 
        $$.type = FLOATING;
        $$.registerName = new string(temporarySet.getFloatRegister());
        string s = (*($$.registerName)) + " = " + string($1) ;
        gen(functionInstruction, s, nextNum);  
    }
    | MINUS DATAINT
    {
        $$.type = INTEGER; 
        $$.registerName = new string(temporarySet.getRegister());
        string s = (*($$.registerName)) + " = -" + string($2) ;
        gen(functionInstruction, s, nextNum);  
        
    }
    | FUNC_CALL 
    { 
        $$.type = $1.type; 
        if ($1.type == ERRORTYPE) {
            if ($1.type == NULLVOID){
                delete callFunctionPointer;
            }
            else {
                $$.registerName = $1.registerName;
                delete callFunctionPointer;
            }
        }; 
    }
    | ID_ARR INCREMENT
    {
        if ($1.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = temporarySet.getRegister();
            $$.registerName = new string(newReg); 
            string s = newReg + " = " + (*($1.registerName)) ;
            gen(functionInstruction, s, nextNum); // T2 = i
            string newReg2 = temporarySet.getRegister();
            s = newReg2 + " = " + newReg + " + 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*($1.registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg2);
            if($1.offsetRegName != NULL){
                temporarySet.freeRegister((*($1.offsetRegName)));
            }
        }
        else {
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable "<< *($1.registerName) << endl; 
        }
    } 
    | ID_ARR DECREMENT
    {
        if ($1.type == INTEGER) {
            $$.type = INTEGER;   
            string newReg = temporarySet.getRegister();
            $$.registerName = new string(newReg);
            string s = newReg + " = " + (*($1.registerName)); // T0 = i
            gen(functionInstruction, s, nextNum);
            string newReg2 = temporarySet.getRegister();
            s = newReg2 + " = " + newReg + " - 1"; // T3 = T2+1
            gen(functionInstruction, s, nextNum);
            s = (*($1.registerName)) + " = " + newReg2; // i = T3
            gen(functionInstruction, s, nextNum);
            temporarySet.freeRegister(newReg2); 
            if($1.offsetRegName != NULL){
                temporarySet.freeRegister((*($1.offsetRegName)));
            }    
        }
        else {
            $$.type = ERRORTYPE;
            cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
            cout << "Cannot increment non-integer type variable " << *($1.registerName) << endl; 
        }
    } 
;

ID_ARR: ID
    {   
        // retrieve the highest level id with same name in param list or var list or global list
        int found = 0;
        typeRecord* vn = NULL;
        searchCallVariable(string($1), activeFunctionPointer, found, vn, globalVariables); 
        $$.offsetRegName = NULL;
        if(found){
            if (vn->type == SIMPLE) {
                $$.type = vn->elementType;
                string dataType = elementTypeMapper($$.type);
                dataType += "_" + to_string(vn->scope);
                $$.registerName = new string("_" + string($1) + "_" + dataType);
            }
            else {
                $$.type = ERRORTYPE;
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ":  ";
                cout << $1 << " is declared as an array but is being used as a singleton" << endl; 
            }
        }
        else {
            if (activeFunctionPointer != NULL)
                searchParameter(string ($1), activeFunctionPointer->parameterList, found, vn);
            if (found) {
                if (vn->type == SIMPLE) {
                    $$.type = vn->elementType;
                    string dataType = elementTypeMapper($$.type);
                    dataType += "_" + to_string(vn->scope);
                    $$.registerName = new string("_" + string($1) + "_" + dataType);
                }
                else {
                    $$.type = ERRORTYPE;
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                    cout << $1 << " is declared as an array but is being used as a singleton" << endl;
                }
            }
            else {
                $$.type = ERRORTYPE;
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Undeclared identifier " << $1 << endl;
            }
        }
    }
    | ID BR_DIMLIST
    {
        // retrieve the highest level id with same name in param list or var list
        int found = 0;
        typeRecord* vn = NULL;
        $$.offsetRegName = NULL; 
        if($2.type == ERRORTYPE){
            errorFound = true;
            $$.type = ERRORTYPE;
        }
        else{
            searchCallVariable(string($1), activeFunctionPointer, found, vn, globalVariables); 
            if(found){
                if (vn->type == ARRAY) {
                    if (dimensionList.size() == vn->dimensionList.size()) {
                        $$.type = vn->elementType;
                        // calculate linear address using dimensions then pass to FACTOR
                        string offsetRegister = temporarySet.getRegister();
                        string dimlistRegister = temporarySet.getRegister();
                        string s = offsetRegister + " = 0";
                        gen(functionInstruction, s, nextNum);
                        for (int i = 0; i < vn->dimensionList.size(); i++) {
                            s = offsetRegister + " = " + offsetRegister + " + " + dimensionList[i];
                            gen(functionInstruction, s, nextNum);
                            // offset += dimensionList[i];
                            if (i != vn->dimensionList.size()-1) {
                                // offset *= vn->dimensionList[i+1];
                                s = dimlistRegister + " = " + to_string(vn->dimensionList[i+1]);
                                gen(functionInstruction, s, nextNum);                                
                                s = offsetRegister + " = " + offsetRegister + " * " + dimlistRegister;
                                gen(functionInstruction, s, nextNum);
                            }
                            temporarySet.freeRegister(dimensionList[i]);
                        }
                        string dataType = elementTypeMapper($$.type);
                        dataType += "_" + to_string(vn->scope); 
                        s = "_" + string($1) + "_" + dataType ;
                        s += "[" + offsetRegister + "]";
                        $$.registerName = new string(s);
                        temporarySet.freeRegister(dimlistRegister);
                        $$.offsetRegName = new string(offsetRegister);
                        
                    }
                    else {
                        $$.type = ERRORTYPE;
                        cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                        cout << "Dimension mismatch: " << $1 << " should have " << dimensionList.size() <<" dimensions" << endl;
                    }
                }
                else {
                    $$.type = ERRORTYPE;
                    cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                    cout << string($1) << " is declared as a singleton but is being used as an array" << endl; 
                }
            }
            else {
                $$.type = ERRORTYPE;
                cout << BOLD(FRED("ERROR : ")) << "Line no. " << yylineno << ": ";
                cout << "Undeclared identifier " << $1 << endl;
            }
            dimensionList.clear();
        }
    }
;

%%

void yyerror(const char *s)
{      
    errorFound=1;
    fprintf (stderr, "%s\n", s);
    // cout << "Line no. " << yylineno << ": Syntax error" << endl;
    // fflush(stdout);
}

int main(int argc, char **argv)
{
    offsetValue = 0;
    errorFound=false;
    nextNum = 0;
    scope = 0;
    found = 0;

    switchVariable.clear();
    dimensionList.clear();
    
    yyparse();
    populateOffsets(functionEntryRecord, globalVariables);
    ofstream outinter;
    outinter.open("./output/intermediate_code.txt");
    if(!errorFound){
        for(auto it:functionInstruction){
            outinter<<it<<endl;
        }
        cout << BOLD(FGRN("Intermediate Code Generated")) << endl;
    } else {
        cout << BOLD(FRED("Exited without intermediate code generation")) << endl;
    }
    outinter.close();
}