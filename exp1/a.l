%{
#include <stdio.h>
#include <string.h>
char s[100][100];
int i=0;
%} 

%% 
[0-9]+ {printf("Number:%s\n",yytext);}
"int"|"float"|"char"|"if"|"else"|"return" {
    printf("Keyword:%s\n",yytext);
} 
[a-zA-Z]+ {
printf("Alphabets:%s\n",yytext);
strcpy(s[i++],yytext);
}
"+"|"-"|"*"|"^" {printf("Operators:%s\n",yytext);}
[\t\n]+ ;
. ;
%% 

int main(){
	yylex();
	for (int j=0;j<i;j++){
		printf("%s\n",s[j]);
	}
	return 0;
}

int yywrap(){
	return 1;
}
