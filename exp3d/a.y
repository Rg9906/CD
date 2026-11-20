%{
#include <stdio.h>
int yylex(void);
int yyerror(const char* s);
%}

%token NUMBER
%left '+' '-'
%left '*' '/'

%%
S : E {printf("Result = %d\n",$1);}
  ;
E : E '+' E {$$=$1+$3;}
  | E '-' E {$$=$1-$3;}
  | E '*' E {$$=$1*$3;}
  | E '/' E {$$=$1/$3;}
  | '(' E ')' {$$=$2;}
  | NUMBER {$$=$1;}
  ;
%%

int main(){
    printf("Enter expression: ");
    yyparse();
    return 0;
}

int yyerror(const char* s){
    printf("Invalid Expression\n");
    return 0;
}

