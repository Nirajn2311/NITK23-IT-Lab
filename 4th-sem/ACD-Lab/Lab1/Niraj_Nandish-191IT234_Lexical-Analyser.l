%{
    int num_lines = 0;
    int num_identifiers = 0;
    int num_invalid = 0;
%}

MULTILINE_COMMENT "/*"([^*]|\*+[^/])*\*+"/"
SINGLELINE_COMMENT \/\/.*
PREPROCESSOR #(include[ ]?<.*>|define.*|ifdef|endif|ifndef|if|else|undef)
STDIO_FUNCTIONS printf|scanf|fopen|getc|gets|putc|puts|fclose|fgets|fputs(?#)
STRING \"([^\"\n])*\"|\'([^\'\n])*\'
KEYWORD auto|const|default|enum|extern|register|sizeof|static|struct|typedef|union|volatile
DATATYPE char|double|float|int|long|short|signed|unsigned|void
CONTROL_STATEMENT break|continue|goto|else|switch|if|case|default|for|do|while|return
IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
INVALID_IDENTIFIER [0-9]+[a-zA-Z_]+|[a-zA-Z0-9_\$\#:?]*[\$\#:?]+[a-zA-Z0-9_\$\#:?]*
NUMERICAL_CONSTANT [1-9][0-9]*(\.[0-9]+)?|0(\.[0-9]+)?
UNARY_OPERATOR (\+\+|\-\-)
BINARY_OPERATOR \+|-|\/|\*|%
ASSIGNMENT_OPERATOR =
SHORTHAND_OPERATOR [\+|-|\*|/|%|&|\||\^|~|<<|>>]=
RELATIONAL_OPERATOR >=|>|<|<=|==|!=
BITWISE_OPERATOR &|~|\||\^|<<|>>
LOGICAL_OPERATOR &&|\|\||!
PARENTHESIS \(|\)|\[|\]|\{|\}
SEMICOLON ;
COMMA ,
DOT \.
%option noyywrap

%%

\n num_lines++;
[\t ] ;
{MULTILINE_COMMENT} {fprintf(yyout,"MULTILINE COMMENT -- \n%s\n", yytext); num_identifiers++;}
{DOT} {fprintf(yyout,"DOT -- %s\n", yytext); num_identifiers++;}
{SEMICOLON} {fprintf(yyout,"SEMICOLON -- %s\n", yytext); num_identifiers++;}
{COMMA} {fprintf(yyout,"COMMA -- %s\n", yytext); num_identifiers++;}
{PREPROCESSOR} {fprintf(yyout,"PREPROCESSOR DIRECTIVE -- %s\n", yytext); num_identifiers++;}
{ASSIGNMENT_OPERATOR} {fprintf(yyout,"ASSIGNMENT OPERATOR -- %s\n", yytext); num_identifiers++;}
{STRING} {fprintf(yyout,"STRING -- %s\n", yytext); num_identifiers++;}
{KEYWORD} {fprintf(yyout,"KEYWORD -- %s\n", yytext); num_identifiers++;}
{STDIO_FUNCTIONS} {fprintf(yyout,"STDIO FUNCTION -- %s\n", yytext); num_identifiers++;}
{CONTROL_STATEMENT} {fprintf(yyout,"FLOW CONTROL STATEMENT -- %s\n", yytext); num_identifiers++;}
{DATATYPE} {fprintf(yyout,"DATATYPE -- %s\n", yytext); num_identifiers++;}
{IDENTIFIER} {fprintf(yyout,"IDENTIFIER -- %s\n", yytext); num_identifiers++;}
{INVALID_IDENTIFIER} {fprintf(yyout,"INVALID IDENTIFIER -- %s\n", yytext); num_invalid++;} 
{NUMERICAL_CONSTANT} {fprintf(yyout,"NUMERICAL CONSTANT -- %s\n", yytext); num_identifiers++;}
{LOGICAL_OPERATOR} {fprintf(yyout,"LOGICAL OPERATOR -- %s\n", yytext); num_identifiers++;}
{BINARY_OPERATOR} {fprintf(yyout,"BINARY OPERATOR -- %s\n", yytext); num_identifiers++;}
{BITWISE_OPERATOR} {fprintf(yyout,"BITWISE OPERATOR -- %s\n", yytext); num_identifiers++;}
{UNARY_OPERATOR} {fprintf(yyout,"UNARY OPERATOR -- %s\n", yytext); num_identifiers++;}
{SINGLELINE_COMMENT} {fprintf(yyout,"SINGLE LINE COMMENT -- %s\n", yytext); num_identifiers++;}
{PARENTHESIS} {fprintf(yyout,"PARENTHESIS -- %s\n", yytext); num_identifiers++;}
{RELATIONAL_OPERATOR} {fprintf(yyout,"RELATIONAL OPERATOR -- %s\n", yytext); num_identifiers++;}
{SHORTHAND_OPERATOR} {fprintf(yyout,"SHORTHAND OPERATOR -- %s\n", yytext); num_identifiers++;}

%%

int main() {
    char fin[50];
    filename:
    printf("Enter file name of file to scan: ");
    scanf("%s", fin);

    if(!(yyin = fopen(fin, "r"))) {
        printf("\nFILE NOT FOUND OR INVALID FILE ENTERED\n\n");
        goto filename;
    }

    yyin = fopen(fin, "r");
    yyout = fopen("output.txt","w");
    yylex();
    fprintf(yyout, "\nANALYSED %d LINES OF CODE", num_lines + 1);
    fprintf(yyout, "\nFOUND %d VALID IDENTIFIERS", num_identifiers);
    fprintf(yyout, "\nFOUND %d INVALID IDENTIFIERS", num_invalid);
    printf("\nINPUT FILE: %s", fin);
    printf("\nOUTPUT FILE: output.txt");
    printf("\nANALYSED %d LINES OF CODE", num_lines + 1);
    printf("\nFOUND %d VALID IDENTIFIERS", num_identifiers);
    printf("\nFOUND %d INVALID IDENTIFIERS\n", num_invalid);
}