%{
#include <stdio.h>
%}

%%
"int"|"float"|"char"|"if"|"else"|"return" {printf("Keyword: %s\n",yytext);}
[a-zA-Z][a-zA-Z0-9]* {printf("Identifier: %s\n",yytext);}
[0-9]+ {printf("Constant: %s\n",yytext);}
"+"|"-"|"*"|"/"|"=" {printf("Operator: %s\n",yytext);}
";"|"("|")"|"{"|"}" {printf("Special Symbol: %s\n",yytext);}
"//".* {printf("Comment: %s\n",yytext);}
[ \t\n]+ ;
. ;
%%

int main(){
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
