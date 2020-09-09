#include "helpers.h"

void patchDataType(eletype elementType, vector<typeRecord*> &typeRecordList, int scope){
    for (typeRecord* &it:typeRecordList) {
        it->scope = scope;
        it->elementType = elementType;
    }
    return;
}

void insertGlobalVariables(vector<typeRecord*> &typeRecordList, vector<typeRecord*> &globalVariables){
    globalVariables.insert(globalVariables.end(), typeRecordList.begin(), typeRecordList.end());
}

void insertParamTab(vector<typeRecord*> &typeRecordList, functionEntry* activeFunctionPointer) {
    if(activeFunctionPointer == NULL) {
        return;
    }
    activeFunctionPointer->parameterList.insert(activeFunctionPointer->parameterList.end(), typeRecordList.begin(), typeRecordList.end());
    activeFunctionPointer->numOfParam+=typeRecordList.size();
}

void insertSymTab(vector<typeRecord*> &typeRecordList, functionEntry* activeFunctionPointer) {
    if (activeFunctionPointer == NULL) {
        return;
    }
    activeFunctionPointer->variableList.insert(activeFunctionPointer->variableList.end(), typeRecordList.begin(), typeRecordList.end());
    return;
}


void searchVariable(string name, functionEntry* activeFunctionPointer, int &found, typeRecord *&vn, int scope) {
    if(activeFunctionPointer == NULL) {
        return;
    }
    vector<typeRecord*>::reverse_iterator i;
    bool flag=false;
    for (i = activeFunctionPointer->variableList.rbegin(); i != activeFunctionPointer->variableList.rend(); ++i) {
        if (name == (*i)->name && (*i)->scope==scope) {
            // found = 1;
            vn = *i;
            flag=true;
            // return;
        }
    }
    if(flag){
        found=1;
        return;
    }
    found = 0;
    vn = NULL;
    return;
}

void deleteVariableList(functionEntry* activeFunctionPointer, int scope){
    if(activeFunctionPointer == NULL) {
        return;
    }
    vector <typeRecord*> variableList;

    for(auto it:activeFunctionPointer->variableList){
        if(it->scope==scope){
            it->isValid = false;
        }
        // if(it->scope!=scope){
        //     variableList.push_back(it);
        // } else {
        //     free(it);
        // }
    }
    // activeFunctionPointer->variableList.swap(variableList);
}

void searchGlobalVariable(string name, vector<typeRecord*> &globalVariables, int &found, typeRecord *&vn, int scope){
    bool flag=false;
    for (auto it : globalVariables) {
        if (name == it->name && it->scope==scope) {
            // vn = *it;
            flag=true;
        }
    }
    if(flag){
        found=1;
        return;
    }
    found = 0;
    vn = NULL;
}



void searchCallVariable(string name, functionEntry* activeFunctionPointer, int &found, typeRecord *&vn, vector<typeRecord*> &globalVariables) {
    if(activeFunctionPointer == NULL) {
        return;
    }
    vector<typeRecord*>::reverse_iterator i;
    bool flag=false;
    int sc=0;
    for (i = activeFunctionPointer->variableList.rbegin(); i != activeFunctionPointer->variableList.rend(); ++i) {
        if (name == (*i)->name && (*i)->isValid) {
            // found = 1;
            if(sc<(*i)->scope){
                sc=(*i)->scope;
                vn = *i;
            }
            flag=true;
            // return;
        }
    }
    if(flag){
        found=1;
        return;
    }
    for(auto it : globalVariables){
        if(name == it->name && it->isValid){
            flag = true;
            vn = it;
            break;
        }
    }
    if(flag){
        found=1;
        return;
    }
    found = 0;
    vn = NULL;
    return;
}

void searchFunc(functionEntry* activeFunctionPointer, vector<functionEntry*> &functionEntryRecord, int &found){
    for (auto it : functionEntryRecord) {
        if(it->name == activeFunctionPointer->name) {
            found = 1;
            return;
        }
    }  
    found = 0;
    return;  
}

void compareFunc(functionEntry* &callFunctionPointer, vector<functionEntry*> &functionEntryRecord, int &found){
    
    for(auto it:functionEntryRecord){
        if(it->name == callFunctionPointer->name  && it->numOfParam == callFunctionPointer->numOfParam){
            int flag=1;
            for(int i=0;i<it->numOfParam;i++){
                if((it->parameterList[i])->elementType != callFunctionPointer->parameterList[i]->elementType){
                    found=-1;
                    flag=0;
                    break;
                }
            }
            if(flag == 1){
                found=1;
                callFunctionPointer->returnType = it->returnType;
                return;
            } 
        }
    }
    if (found != -1) found=0;
    return;    
}

void searchParameter(string name, vector<typeRecord*> &parameterList, int &found, typeRecord *&pn) {
    vector<typeRecord*> :: reverse_iterator i;
    for (i = parameterList.rbegin(); i != parameterList.rend(); ++i){
        if(name == (*i)->name){
            found = 1;
            pn = (*i);
            return;
        }
    }
    found = 0;
    pn = NULL;
    return;
}

int varTypeMapper(varType a){
    switch(a){
        case SIMPLE : return 0;
        case ARRAY  : return 1;
    }
    return 2;
}

void addFunction(functionEntry* activeFunctionPointer, vector<functionEntry*> &functionEntryRecord){
    functionEntryRecord.push_back(activeFunctionPointer);
}

eletype compareTypes(eletype type1, eletype type2) {
    if (type1 == INTEGER && type2 == INTEGER) {
        return INTEGER;
    }
    else if (type1 == FLOATING && type2 == FLOATING) {
        return FLOATING;
    }
    else if (type1 == INTEGER && type2 == FLOATING) {
        return FLOATING;
    }
    else if (type1 == FLOATING && type2 == INTEGER) {
        return FLOATING;
    }
    else return NULLVOID;
}

void populateOffsets(vector<functionEntry*> &functionEntryRecord, vector<typeRecord*> &globalVariables){
    int offset;
    for(auto &funcRecord : functionEntryRecord){
        offset = 0;
        for(auto &paramRecord : funcRecord->parameterList){
            paramRecord->varOffset = offset;
            offset += 4;
        }
        // offset += 80;
        offset = 0;
        offset += 92;
        for(auto &variableRecord : funcRecord->variableList){
            variableRecord->varOffset = offset;
            offset += 4*(variableRecord->maxDimlistOffset);
        }
        funcRecord->functionOffset = offset;
    }
    printSymbolTable(functionEntryRecord, globalVariables);
}

string elementTypeMapper(eletype a){
    switch(a){
        case INTEGER   : return "int";
        case FLOATING  : return "float";
        case NULLVOID  : return "void";
        case BOOLEAN   : return "bool";
        case ERRORTYPE : return "error";
    }
    return "vvv";
}

bool arithmeticCompatible(eletype type1, eletype type2) {
    if ((type1 == INTEGER || type1 == FLOATING)
        && (type2 == INTEGER || type2 == FLOATING)) return true;
    return false;
}

int eletypeIntMapper(eletype a){
    switch(a){
        case INTEGER   : return 0;
        case FLOATING  : return 1;
        case NULLVOID  : return 2;
        case BOOLEAN   : return 3;
        case ERRORTYPE : return 4;
    }
    return 5;
}

int TagMapper(Tag a){
    switch(a){
        case PARAMAETER : return 0;
        case VARIABLE   : return 1;
    }
    return 2;
}

void printSymbolTable(vector<functionEntry*> &functionEntryRecord, vector<typeRecord*> &globalVariables){
    ofstream symbolTable;
    symbolTable.open("output/symtab.txt");
    symbolTable.flush();

    // Printing Global Variables
    symbolTable << "$$" << endl;
    symbolTable << "GLOBAL " << "EMPTY " << globalVariables.size() << " 0 " << endl;
    symbolTable << "$1" << endl;
    for(auto &variableRecord : globalVariables){
        symbolTable << "_" << variableRecord->name << "_" << elementTypeMapper(variableRecord->elementType) << "_" << variableRecord->scope << " " << eletypeIntMapper(variableRecord->elementType) << " " ;
        symbolTable << variableRecord->scope << " " << variableRecord->maxDimlistOffset << endl;
    }
    symbolTable << "$2 0" << endl;

    // Printing Local Function Variables
    for(auto &funcRecord : functionEntryRecord){
        symbolTable << "$$" << endl;
        if(funcRecord->name != "main"){
            symbolTable << "_" << funcRecord->name << " " << elementTypeMapper(funcRecord->returnType) << " ";
        }
        else{
            symbolTable << funcRecord->name << " " << elementTypeMapper(funcRecord->returnType) << " ";
        }
        symbolTable << funcRecord->numOfParam << " " << funcRecord->functionOffset << endl;
        symbolTable << "$1" << endl;
        for(auto &variableRecord : funcRecord->parameterList){
            symbolTable << "_" << variableRecord->name << "_" << elementTypeMapper(variableRecord->elementType) << "_" << variableRecord->scope << " " << eletypeIntMapper(variableRecord->elementType) << " " ;
            symbolTable << variableRecord->scope << " " << variableRecord->varOffset << endl;
        }
        symbolTable << "$2 " << funcRecord->variableList.size() << endl;
        for(auto &variableRecord : funcRecord->variableList){
            symbolTable << "_" << variableRecord->name << "_" << elementTypeMapper(variableRecord->elementType) << "_" << variableRecord->scope << " " << eletypeIntMapper(variableRecord->elementType) << " " ;
            symbolTable << variableRecord->scope << " " << variableRecord->varOffset << endl;
        }
    }
    symbolTable.flush();
    symbolTable.close();
}

void printList(vector<functionEntry*> &functionEntryRecord){
    
    for(auto it:functionEntryRecord){
        cout<<"Function Entry: "<<(it->name)<<endl;
        cout<<"Printing Parameter List"<<endl;
        for(auto it2:it->parameterList){
            cout<<(it2->name)<<" "<<(it2->elementType)<<endl;
        }
        cout<<"Printing Variable List"<<endl;
        for(auto it2:it->parameterList){
            cout<<(it2->name)<<" "<<(it2->elementType)<<endl;
        } 
    }
}

void printFunction(functionEntry* &activeFunctionPointer){
    
        cout<<"Function Entry: --"<<(activeFunctionPointer->name)<<"--"<<endl;
        cout<<"Printing Parameter List"<<endl;
        for(auto it2:activeFunctionPointer->parameterList){
            cout<<(it2->name)<<" "<<(it2->elementType)<<endl;
        }
        cout<<"Printing Variable List"<<endl;
        for(auto it2:activeFunctionPointer->variableList){
            cout<<(it2->name)<<" "<<(it2->elementType)<<endl;
        } 
}
