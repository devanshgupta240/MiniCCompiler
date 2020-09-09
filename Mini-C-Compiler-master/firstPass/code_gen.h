#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>
// #include <algorithm>
#include <utility>
#include <fstream>

using namespace std;

#define RST  "\x1B[0m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"

#define FRED(x) RED x RST
#define FWHT(x) WHT x RST
#define FGRN(x) GRN x RST
#define FMAG(x) MAG x RST
#define FCYN(x) CYN x RST
#define FYEL(x) YEL x RST
#define FBLU(x) BLU x RST

#define BOLD(x) "\x1B[1m" x RST
#define UNDL(x) "\x1B[4m" x RST

class registerSet {
private:
    vector<int> tempRegister;
    vector<int> floatRegister;
public:
    registerSet(){
        tempRegister.clear();
        for(int i=9; i>=0; i--){
            tempRegister.push_back(i);
        }
        floatRegister.clear();
        for(int i=10; i>=0; i--){
            if(i==0||i==12){
                continue;
            }
            floatRegister.push_back(i);
        }
    }
    string getRegister();
    string getFloatRegister();
    void freeRegister(string s);
};


void gen(vector<string> &, string ,int &);
void mergeSwitch(vector<pair<string,int>> *&receiver,vector<pair<string,int>> *&donor); 
void backPatch(vector<int> *&, int, vector<string> &);
void merge(vector<int> *&, vector<int> *&);
