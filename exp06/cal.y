%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
int yyerror(char *s);
%}

%union {
    double val;
}

%token <val> NUM
%type <val> E

%left '+' '-'
%left '*' '/'
%right UMINUS

%%

input:
      E '\n'
      {
          printf("Answer: %g\n", $1);
      }
    ;

E:
      E '+' E
      {
          $$ = $1 + $3;
      }
    | E '-' E
      {
          $$ = $1 - $3;
      }
    | E '*' E
      {
          $$ = $1 * $3;
      }
    | E '/' E
      {
          $$ = $1 / $3;
      }
    | NUM
      {
          $$ = $1;
      }
    ;

%%

int main()
{
    printf("Enter the expression:\n");
    yyparse();
    return 0;
}

int yyerror(char *s)
{
    printf("Invalid expression\n");
    return 0;
}