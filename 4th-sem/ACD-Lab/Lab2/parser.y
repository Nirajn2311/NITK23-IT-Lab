%{
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    extern int yylex(void);
    extern FILE* yyin;
    int yyerror(const char *msg);
    int success = 1;
    int errors = 0;
    int yycolumn = 0;
%}

%union {
    char* f;
}
%token ID IF FOR NUM OP UNARY_OP
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
    STMTS : STMTS STMT
          | %empty
          ;

    STMT  : ';'
          | EXPR ';'
          | IF '('EXPR')' STMT  %prec LOWER_THAN_ELSE
          | IF '('EXPR')' STMT ELSE STMT
          | FOR '('EXPR';'EXPR';'EXPR')' STMT
          | '{'STMTS'}'
          ;

    EXPR  : TERM
          | ID UNARY_OP
          | UNARY_OP ID
          | TERM OP EXPR
          | ID '=' EXPR
          | error
          ;

    TERM  : ID
          | NUM
          ;
%%

int main() {
    char fin[50];
    extern int yylineno;
    filename:
    printf("Enter name of file to scan: ");
    scanf("%s", fin);

    if(!(yyin = fopen(fin, "r"))) {
        printf("\nFILE NOT FOUND OR INVALID FILE ENTERED\n\n");
        goto filename;
    }
    yyin = fopen(fin, "r");
    do {
        yyparse();
    }while(!feof(yyin));
    if(success) {
        printf("\nOK\n");
    }
    else {
        printf("\nParsing failed due to %d error(s)\n", errors);
    }
    return 0;
}

int yyerror(const char *msg) {
    extern char* yytext;
    extern int yylineno;
    extern int yycolumn;
    printf("\nProblem occured at line number %d, column number %d, near '%s'\nError: %s\n", yylineno, yycolumn, yytext, msg);
    errors++;
    success = 0;
    return 1;
}