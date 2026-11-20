%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%} 

%token VALID INVALID

%%
S: VALID {printf("Valid Variable Name\n");}
| INVALID {printf("Invalid Variable Name\n");}
;
%% 

int main(){
printf("Enter variable name:");
yyparse();
return 0;
}

int yyerror(const char*s){
printf("An error occured\n");
return 0;
}


