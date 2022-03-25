%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "y.tab.h"
    extern int yycolumn;
    extern int yyleng;
%}


WHITESPACE      [ \t\v\f]
IDENTIFIER      [a-zA-Z_][a-zA-Z0-9_]*
NUMBER          ([0-9]+|[0-9]+\.[0-9]+)
OPERATOR        [-+*/]|"=="|">="|"<="|">"|"<"
UNARY_OPERATOR  "++"|"--"
SINGLE_CHAR     [=(){};]

%%

\n              { yycolumn = 0; yylineno++; }
{SINGLE_CHAR}   { yycolumn++; return yytext[0]; }
{OPERATOR}      { yycolumn += yyleng; return OP; }
{UNARY_OPERATOR} { yycolumn += yyleng; return UNARY_OP; }
"if"            { yycolumn += 2; return IF; }
"for"           { yycolumn += 3; return FOR; }
"else"          { yycolumn += 4; return ELSE; }
{NUMBER}        { yycolumn += yyleng; return NUM; }
{IDENTIFIER}    { yycolumn += yyleng; return ID; }
{WHITESPACE}    { yycolumn += yyleng; }
.               { yycolumn += 1; return yytext[0]; }

%%

int yywrap() {
    return -1;
}