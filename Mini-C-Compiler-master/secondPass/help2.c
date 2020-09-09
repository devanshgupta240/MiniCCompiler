#include "help2.h"

string elementTypeMapper(eletype a)
{
    switch(a)
    {
        case INTEGER   : return "int";
        case FLOATING  : return "float";
        case NULLVOID  : return "void";
        case BOOLEAN   : return "bool";
        case ERRORTYPE : return "error";
        default: return "default";
    }
}

int elementTypeIntegerMapper(eletype a)
{
    switch(a)
    {
        case INTEGER   : return 0;
        case FLOATING  : return 1;
        case NULLVOID  : return 2;
        case BOOLEAN   : return 3;
        case ERRORTYPE : return 4;
        default : return 999;
    }
}
eletype getElementType(string x)
{
    if(x=="0")
        return INTEGER;
    if(x=="1")
        return FLOATING;
    if(x=="2")
        return NULLVOID;
    return ERRORTYPE;
}
int getOffset(vector<functionEntry> &functionList, vector<typeRecord> &globalVariables, string functionName, string variableName, int internalOffset, bool &isGlobal)
{
    isGlobal = false;
    for(auto it : functionList)
    {
        if(it.name == functionName)
        {
            for (auto it2 : it.variableList)
            {
                if(it2->name == variableName)
                {
                    int offset = it.functionOffset - 4*( internalOffset + 1) - it2->variableOffset;
                    return offset; 
                }
            }
            for (auto it2: it.parameterList)
            {
                if(it2->name == variableName)
                {
                    int offset = it.functionOffset + 4*(it.numberOfParameters - internalOffset - 1) - it2->variableOffset;
                    return offset;
                }
            }
        }
    }
    for(auto it : globalVariables)
    {
        if(it.name == variableName)
        {
            isGlobal = true;
            return 0;
        }
    }
    cout << "Variable " << variableName << " not found in " << functionName << endl;
    return -1;
}

int getFunctionOffset(vector<functionEntry> &functionList,string functionName)
{
    for(auto it : functionList)
    {
        if(it.name == functionName)
        {
            return it.functionOffset;
        }
    }
    return -1;
}

void printVector(vector<functionEntry> &functionPrintList)
{
    for(auto functionRecord : functionPrintList)
    {
        cout << "$$" << endl;
        cout << "_" << functionRecord.name << " " << elementTypeMapper(functionRecord.returnType) << " ";
        cout << functionRecord.numberOfParameters << " " << functionRecord.functionOffset << endl;
        cout << "$1" << endl;
        for(auto variableRecord : functionRecord.parameterList)
        {
            cout <<variableRecord->name << " " << elementTypeIntegerMapper(variableRecord->elementType) << " " ;
            cout << variableRecord->scope << " " << variableRecord->variableOffset << endl;
        }
        cout << "$2 " << functionRecord.variableList.size() << endl;
        for(auto variableRecord : functionRecord.variableList)
        {
            cout <<variableRecord->name << " " << elementTypeIntegerMapper(variableRecord->elementType) << " " ;
            cout << variableRecord->scope << " " << variableRecord->variableOffset << endl;
        }
    }
}

void readSymbolTable(vector<functionEntry> &functionList, vector<typeRecord> &globalVariables)
{
    ifstream symbolTableFile;
    symbolTableFile.open ("../firstPass/output/symtab.txt");
    string a;
    bool isGlobal = false;
    while(symbolTableFile >> a)
    {
        if(a=="$$")
        {
            // cout<<"pp "<<a<<endl;
            functionEntry p;
            symbolTableFile >> p.name;
            if(p.name == "GLOBAL")
            {
                isGlobal = true;
            }
            else
            {
                isGlobal = false;
            }
            string x;
            symbolTableFile >> x;
            p.returnType = getElementType(x);
            symbolTableFile >> p.numberOfParameters;
            symbolTableFile >> p.functionOffset;
            symbolTableFile >> x;
            if(isGlobal)
            {
                // globalVariables.insert(globalVariables.end(), p.parameterList.begin(), p.parameterList.end());
                for(int i=0;i<p.numberOfParameters;i++)
                {
                    typeRecord newType;
                    string elementType;
                    symbolTableFile >> newType.name;
                    symbolTableFile >> elementType;
                    newType.elementType = getElementType(elementType);
                    
                    symbolTableFile >> newType.scope;
                    symbolTableFile >> newType.variableOffset;
                    globalVariables.push_back(newType);
                }
                for(auto it : globalVariables)
                {
                    cout << "Global Variable Name : "<< it.name << endl;
                }
            }
            else
            {
                (p.parameterList).resize(p.numberOfParameters);
                for(int i=0;i<p.numberOfParameters;i++)
                {
                    p.parameterList[i] = new typeRecord;
                    symbolTableFile >> (p.parameterList[i])->name;
                    string t;
                    symbolTableFile >> t;
                    (p.parameterList[i])->elementType= getElementType(t);
                    symbolTableFile >> (p.parameterList[i])->scope;
                    symbolTableFile >> (p.parameterList[i])->variableOffset;
                }
            }
            symbolTableFile >> x;
            int z;
            symbolTableFile >> z;
            p.variableList.resize(z);
            for(int i=0;i<z;i++)
            {
                p.variableList[i] = new typeRecord;
                symbolTableFile >> (p.variableList[i])->name;
                string t;
                symbolTableFile >> t;
                (p.variableList[i])->elementType= getElementType(t);
                symbolTableFile >> (p.variableList[i])->scope;
                symbolTableFile >> (p.variableList[i])->variableOffset;
            }
            if(!isGlobal)
            {
                functionList.push_back(p);
            }
        }
    }
}

int getParameterOffset(vector<functionEntry> &functionList, string functionName)
{
    for(auto it : functionList)
    {
        if(it.name == functionName)
        {
            return 4*(it.numberOfParameters);
        }
    }
    return 0;
}

