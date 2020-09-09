%{    
# include "second_pass.tab.h"
%}
%option noyywrap
%%

"function"                      { return FUNCTION; }
"begin"                         { return BEG; }
"if"                            { return IF; }
"goto"                          { return GOTO; }
"param"                         { return PARAMETER; }
"refparam"                      { return REFPARAMETER; }
"call"                          { return CALL; }
"end"                           { return END; }
"return"                        { return RETURN; }
"convertToFloat"                { return CONVERTTOFLOAT; }
"convertToInt"                  { return CONVERTTOINT; }
"print"                         { return PRINT;}
"read"                          { return READ; }
"<="                            { return LESSEQUAL; }
">="                            { return GREATEQUAL; }
"=="                            { return EQUAL; }
"!="                            { return NOTEQUAL; }
"&&"                            { return AND; }
"||"                            { return OR; }
":"                             { return COLON; }
"["                             { return LSQUAREB; }
"]"                             { return RSQUAREB; }
"("                             { return LPARE; }
")"                             { return RPARE; }
","                             { return COMMA; }
"="                             { return ASSIGN; }
"<"                             { return LESSTHAN; }
">"                             { return GREATTHAN; }
"~"                             { return NEG; }
"+"                             { return PLUS; }
"/"                             { return DIV; }
"*"                             { return MUL; }
"%"                             { return MOD; }

-[0-9]+\.[0-9]*|[0-9]+\.[0-9]*  { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return DATAFLOAT; }
-[0-9]+|[0-9]+                  { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return DATAINT; }
"-"                             { return MINUS; }
[T][0-9]+                       { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return REGINT; }
[F][0-9]+                       { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return REGFLOAT; }
[L][0-9]+                       { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return LABEL; }
[_a-zA-Z][a-zA-Z_0-9]*          { yylval.idName = (char *)malloc(100); memset(yylval.idName, 0, 100); memcpy(yylval.idName, yytext, yyleng); return USERVARIABLE; }

\n                              { yylineno++;return NEWLINE;}
[ \t]                           { /* ignore whitespace */ }
%%