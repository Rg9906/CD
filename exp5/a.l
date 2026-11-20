
%{
#include "y.tab.h"
%}

%%
"int" {return INT;}
"float" {return FLOAT;}
[0-9]+ {return NUM;}
[+\-*/=] {return yytext[0];}
[ \t] ;
\n {return 0;}
. {return yytext[0];}
%%

int yywrap(){
    return 1;
}
