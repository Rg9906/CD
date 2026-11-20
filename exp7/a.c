
#include <stdio.h>
#include <string.h>

char code[50][100],v[50][20];
int n=0,m=0;

int isNum(char *s){
    int i=0;
    if(s[0]=='-') i++;
    if(!s[i]) return 0;
    for(;s[i];i++)
        if(s[i]<'0'||s[i]>'9') return 0;
    return 1;
}

void add(char *s){
    int i;
    if(isNum(s)) return;
    for(i=0;i<m;i++)
        if(!strcmp(v[i],s)) return;
    strcpy(v[m++],s);
}

void load(char *s){
    char l[20],x[20],y[20],op;
    if(sscanf(s,"%19s = %19s %c %19s",l,x,&op,y)==4){
        add(l);
        add(x);
        add(y);
    }
    else if(sscanf(s,"%19s = %19s",l,x)==2){
        add(l);
        add(x);
    }
}

void gen(char *s){
    char l[20],x[20],y[20],op;
    if(sscanf(s,"%19s = %19s %c %19s",l,x,&op,y)==4){
        if(isNum(x)) printf("    MOV AX, %s\n",x);
        else printf("    MOV AX, [%s]\n",x);

        if(op=='+'){
            if(isNum(y)) printf("    ADD AX, %s\n",y);
            else printf("    ADD AX, [%s]\n",y);
        }
        else if(op=='-'){
            if(isNum(y)) printf("    SUB AX, %s\n",y);
            else printf("    SUB AX, [%s]\n",y);
        }
        printf("    MOV [%s], AX\n",l);
    }
    else if(sscanf(s,"%19s = %19s",l,x)==2){
        if(isNum(x)) printf("    MOV AX, %s\n",x);
        else printf("    MOV AX, [%s]\n",x);
        printf("    MOV [%s], AX\n",l);
    }
}

int main(){
    char s[100];
    printf("Enter TAC (Ctrl+D to stop):\n");

    while(n<50 && fgets(s,sizeof(s),stdin)){
        s[strcspn(s,"\n")]=0;
        strcpy(code[n++],s);
        load(s);
    }

    printf("\n; 8086 Assembly Code\n");
    printf(".model small\n.stack 100h\n.data\n");

    for(int i=0;i<m;i++)
        printf("%s DW ?\n",v[i]);

    printf(".code\nmain proc\n");
    printf("    MOV AX, @data\n    MOV DS, AX\n");

    for(int i=0;i<n;i++)
        gen(code[i]);

    printf("    MOV AX, 4C00H\n    INT 21H\n");
    printf("main endp\nend main\n");
    return 0;
}
