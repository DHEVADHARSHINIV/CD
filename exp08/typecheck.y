%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *s);

char type1[20], type2[20];

%}

%union{
    char *str;
}

%token <str> ID
%token INT FLOAT

%%

program:
      declaration declaration assignment
      ;

declaration:
      INT ID ';'
      {
          if(strcmp($2,"a")==0)
              strcpy(type1,"int");
          else
              strcpy(type2,"int");
      }
    | FLOAT ID ';'
      {
          if(strcmp($2,"a")==0)
              strcpy(type1,"float");
          else
              strcpy(type2,"float");
      }
      ;

assignment:
      ID '=' ID '+' ID ';'
      {
          if(strcmp(type1,type2)==0)
              printf("No Type Mismatch\n");
          else
              printf("Type Mismatch\n");
      }
      ;

%%

int main()
{
    printf("Enter declarations and expression:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s)
{
    printf("Syntax Error\n");
}