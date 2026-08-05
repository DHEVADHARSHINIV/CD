%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int yylex();
void yyerror(const char *s);

char temp[20];
int tempCount = 1;

void emit(char *res,char *op1,char *op,char *op2)
{
    printf("%s = %s %s %s\n",res,op1,op,op2);
}

void assign(char *lhs,char *rhs)
{
    printf("%s = %s\n",lhs,rhs);
}
%}

%union{
    char *str;
}

%token <str> ID NUM
%type <str> expr

%left '+' '-'
%left '*' '/'

%%

stmt
    : ID '=' expr '\n'
      {
          assign($1,$3);
          YYACCEPT;
      }
    ;

expr
    : expr '+' expr
      {
          sprintf(temp,"t%d",tempCount++);
          emit(temp,$1,"+",$3);
          $$=strdup(temp);
      }
    | expr '-' expr
      {
          sprintf(temp,"t%d",tempCount++);
          emit(temp,$1,"-",$3);
          $$=strdup(temp);
      }
    | expr '*' expr
      {
          sprintf(temp,"t%d",tempCount++);
          emit(temp,$1,"*",$3);
          $$=strdup(temp);
      }
    | expr '/' expr
      {
          sprintf(temp,"t%d",tempCount++);
          emit(temp,$1,"/",$3);
          $$=strdup(temp);
      }
    | '(' expr ')'
      {
          $$=$2;
      }
    | ID
      {
          $$=$1;
      }
    | NUM
      {
          $$=$1;
      }
    ;

%%

int main()
{
    printf("Enter Expression:\n");
    yyparse();
    return 0;
}

void yyerror(const char *s)
{
    printf("Invalid Expression\n");
}