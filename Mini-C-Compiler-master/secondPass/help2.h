#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
#include <fstream>
#include <utility>
using namespace std;

#define RST   "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

#define FRED(x) RED x RST
#define FGRN(x) GRN x RST
#define FYEL(x) YEL x RST
#define FBLU(x) BLU x RST
#define FMAG(x) MAG x RST
#define FCYN(x) CYN x RST
#define FWHT(x) WHT x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

enum eletype {INTEGER, FLOATING, NULLVOID, BOOLEAN, ERRORTYPE};
enum varType {SIMPLE, ARRAY};
enum Tag {PARAMAETER, VARIABLE};

struct typeRecord {
    string name;
    eletype elementType;
    int scope;
    int variableOffset;
};

struct functionEntry {
    string name;
    eletype returnType;
    int numberOfParameters;
    int functionOffset;
    vector <typeRecord*> variableList;
    vector <typeRecord*> parameterList;
};

string elementTypeMapper(eletype a);
int elementTypeIntegerMapper(eletype a);
eletype getElementType(string x);

int getParameterOffset(vector<functionEntry> &functionList, string functionName);
void readSymbolTable(vector<functionEntry> &functionList, vector<typeRecord> &globalVariables);
int getOffset(vector<functionEntry> &functionList, vector<typeRecord> &globalVariables, string functionName, string variableName, int internalOffset, bool &isGlobal);
int getFunctionOffset(vector<functionEntry> &functionList, string functionName);
void printVector(vector<functionEntry> &functionList);