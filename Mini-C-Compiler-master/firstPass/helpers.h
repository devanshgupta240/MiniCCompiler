#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
// #include <algorithm>
#include <utility>
#include <fstream>
using namespace std;

// BOLD(FRED("ERROR : "))

#define RST  "\x1B[0m"
#define RED  "\x1B[31m"
#define BLU  "\x1B[34m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define MAG  "\x1B[35m"

#define FRED(x) RED x RST
#define FGRN(x) GRN x RST
#define FCYN(x) CYN x RST
#define FWHT(x) WHT x RST
#define FYEL(x) YEL x RST
#define FBLU(x) BLU x RST
#define FMAG(x) MAG x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

enum eletype {INTEGER, FLOATING, NULLVOID, BOOLEAN, ERRORTYPE};
enum varType {SIMPLE, ARRAY};
enum Tag{PARAMAETER, VARIABLE};

struct condition2temp{
    vector<int> *temp;
};

struct expression{
    eletype type;
    string* registerName;
    string* offsetRegName;
};

struct shortCircuit{
    eletype type;
    string* registerName;
    vector<int>* jumpList;
};

struct statement {
    vector<int> *nextList;
    vector<int> *breakList;
    vector<int> *continueList;
};

struct switchTemp{
    vector<pair<string,int>> *casePair;
};

struct whileExpression {
    int begin;
    vector<int> *falseList;
};

struct switchCaser{
    vector<int> *nextList;
    vector<pair<string,int>> *casePair;
    vector<int> *breakList;
    vector<int> *continueList;
};


struct typeRecord {
    string name;
    varType type;
    eletype elementType;
    Tag tag;
    int scope;
    vector<int> dimensionList; // cube[x][y][z] => (x -> y -> z)
    int varOffset;
    bool isValid;
    int maxDimlistOffset;
}; 

struct functionEntry {
    string name;
    eletype returnType;
    int numOfParam;
    int functionOffset;
    vector <typeRecord*> variableList;
    vector <typeRecord*> parameterList;
}; 

void insertGlobalVariables(vector<typeRecord*> &typeRecordList, vector<typeRecord*> &globalVariables);
void searchGlobalVariable(string name, vector<typeRecord*> &globalVariables, int &found, typeRecord *&vn, int scope);
void patchDataType(eletype type, vector<typeRecord*> &typeRecordList, int scope);
void searchFunc(functionEntry* activeFunctionPointer,vector<functionEntry*> &functionEntryRecord,int &found);
void compareFunc(functionEntry* &activeFunctionPointer,vector<functionEntry*> &functionEntryRecord,int &found);
void searchVariable(string name, functionEntry* activeFunctionPointer, int &found, typeRecord *&vn, int scope);
void printList(vector<functionEntry*> &functionEntryRecord);
void printList(vector<functionEntry*> &functionEntryRecord);
void printFunction(functionEntry* &activeFunctionPointer);
bool arithmeticCompatible(eletype type1, eletype type2);
void printFunction(functionEntry* &activeFunctionPointer);
bool arithmeticCompatible(eletype type1, eletype type2);
void searchCallVariable(string name, functionEntry* activeFunctionPointer, int &found, typeRecord *&vn, vector<typeRecord*> &globalVariables);
void searchParameter(string name, vector<typeRecord*> &parameterList, int &found, typeRecord *&pn);
void addFunction(functionEntry* activeFunctionPointer, vector<functionEntry*> &functionEntryRecord);
eletype compareTypes(eletype type1, eletype type2);
void printSymbolTable(vector<functionEntry*> &functionEntryRecord, vector<typeRecord*> &globalVariables);
string elementTypeMapper(eletype a);
void populateOffsets(vector<functionEntry*> &functionEntryRecord, vector<typeRecord*> &globalVariables);
void deleteVariableList(functionEntry* activeFunctionPointer, int scope);
void insertSymTab(vector<typeRecord*> &typeRecordList, functionEntry* activeFunctionPointer);

int eletypeIntMapper(eletype a);
int varTypeMapper(varType a);
int TagMapper(Tag a);