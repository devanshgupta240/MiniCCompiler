%{    
# include "parser.tab.h"
%}
%option noyywrap

%%

"case"                          { return CASE; }
"if"                            { return IF; }
"else"                          { return ELSE; }
"return"                        { return RETURN; }
"break"                         { return BREAK; }
"default"                       { return DEFAULT; }
"continue"                      { return CONTINUE; }
"while"                         { return WHILE; }
"for"                           { return FOR; }
"switch"                        { return SWITCH; }
"main"                          { return MAIN; }
"read"                          { return READ; }
"print"                         { return PRINT; }

"int"                           { return INT; }
"float"                         { return FLOAT; }
"void"                          { return VOID; }

"{"                             { return LCURLYB; }
"}"                             { return RCURLYB; }
";"                             { return SEMI; }
"=="                            { return EQUAL; }
"!="                            { return NOTEQUAL; }
"<<"                            { return LSHIFT; }
">>"                            { return RSHIFT; }
"^"                             { return XOR; }
"<"                             { return LESSTHAN; }
">"                             { return GREATTHAN; }
"<="                            { return LESSEQUAL; }
">="                            { return GREATEQUAL; }
"+="                            { return PLUSASSIGNMENT; }
"-="                            { return MINASSIGNMENT; }
"*="                            { return MULASSIGNMENT; }
"%="                            { return MODASSIGNMENT; }
"/="                            { return DIVASSIGNMENT; }
"&&"                            { return AND; }
"||"                            { return OR; }
"++"                            { return INCREMENT; }
"--"                            { return DECREMENT; }
"["                             { return LSQUAREB; }
"]"                             { return RSQUAREB; }
"("                             { return LPARE; }
")"                             { return RPARE; }
":"                             { return COLON; }
","                             { return COMMA; }
"="                             { return ASSIGN; }
"!"                             { return NOT; }
"&"                             { return BITAND; }
"|"                             { return BITOR; }
"+"                             { return PLUS; }
"-"                             { return MINUS; }
"/"                             { return DIV; }
"*"                             { return MUL; }
"%"                             { return MOD; }

[0-9]+\.[0-9]+                  { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return DATAFLOAT; }
[0-9]+                          { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return DATAINT; }
[a-zA-Z_][a-zA-Z_0-9]*          { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return ID; }

\n                              { yylineno++;}
[ \t]                           {/* ignore whitespace */ }
%%