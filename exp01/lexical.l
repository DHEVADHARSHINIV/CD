%{
#include <stdio.h>
#include <string.h>

struct symbol
{
    char name[50];
};

struct symbol table[100];
int count = 0;

void insertSymbol(char *name)
{
    int i;

    for (i = 0; i < count; i++)
    {
        if (strcmp(table[i].name, name) == 0)
            return;
    }

    strcpy(table[count].name, name);
    count++;
}
%}

IDENTIFIER [a-zA-Z_][a-zA-Z0-9_]*
CONSTANT [0-9]+

%%

"//".* {
    printf("COMMENT\t\t%s\n", yytext);
}

"/*"([^*]|\*+[^*/])*\*+"/" {
    printf("COMMENT\t\t%s\n", yytext);
}

"int"|"float"|"char"|"double"|"void"|"if"|"else"|"for"|"while"|"return" {
    printf("KEYWORD\t\t%s\n", yytext);
}

{IDENTIFIER} {
    printf("IDENTIFIER\t%s\n", yytext);
    insertSymbol(yytext);
}

{CONSTANT} {
    printf("CONSTANT\t%s\n", yytext);
}

"+"|"-"|"*"|"/"|"="|"<"|">" {
    printf("OPERATOR\t%s\n", yytext);
}

[ \t\n]+ {
}

. {
    printf("SPECIAL\t\t%s\n", yytext);
}

%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("LEXICAL ANALYZER OUTPUT\n");
    printf("=======================\n\n");

    yylex();

    printf("\nSYMBOL TABLE\n");
    printf("============\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d\t%s\n", i + 1, table[i].name);
    }

    return 0;
}