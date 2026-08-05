%{
#include "y.tab.h"
#include <string.h>
%}

%%

"int"      { return INT; }
"float"    { return FLOAT; }

[a-zA-Z][a-zA-Z0-9_]*   {
    yylval.str = strdup(yytext);
    return ID;
}

"="        return '=';
"+"        return '+';
";"        return ';';

[ \t\n]    ;

.          return yytext[0];

%%

int yywrap()
{
    return 1;
}