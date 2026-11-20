
%{
#include "y.tab.h"
#include <string.h>
%}

%%
[a-zA-Z][a-zA-Z0-9]* {strcpy(yylval.str,yytext); return ID;}
[+*/()-] {return yytext[0];}
[ \t]+ ;
\n {return 0;}
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}

