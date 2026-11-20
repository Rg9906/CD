
%{
#include <stdio.h>
#include <string.h>
int yylex(void);
int yyerror(const char *s);
int n=0;
%}

%union {
    char str[100];
}

%token <str> ID
%type <str> E

%%
S : E ;
E : E '+' E {sprintf($$,"t%d",++n); printf("%s = %s + %s\n",$$,$1,$3);}
  | E '*' E {sprintf($$,"t%d",++n); printf("%s = %s * %s\n",$$,$1,$3);}
  | '(' E ')' {strcpy($$,$2);}
  | ID {strcpy($$,$1);}
  ;
%%

int main(){
    printf("Enter expression: ");
    yyparse();
    return 0;
}

int yyerror(const char *s){
    printf("Invalid Expression\n");
    return 0;
}
