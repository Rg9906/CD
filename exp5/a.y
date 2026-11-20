
%{
#include <stdio.h>
int yylex(void);
int yyerror(const char *s);
%}

%token INT FLOAT NUM

%%
S : INT E {printf("Valid Integer Expression\n");}
  | FLOAT E {printf("Valid Float Expression\n");}
  ;
E : E '+' E
  | E '-' E
  | E '*' E
  | E '/' E
  | NUM
  ;
%%

int main(){
    printf("Enter type and expression: ");
    yyparse();
    return 0;
}

int yyerror(const char *s){
    printf("Invalid Expression\n");
    return 0;
}
