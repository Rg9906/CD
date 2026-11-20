
#include <stdio.h>
#include <string.h>

struct op{
    char l;
    char r[20];
}a[10];

int main(){
    int n,i,x,y;
    char t[20],op;

    printf("Enter no of values: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Left: ");
        scanf(" %c",&a[i].l);
        printf("Right: ");
        scanf("%19s",a[i].r);
    }

    printf("\nIntermediate Code:\n");
    for(i=0;i<n;i++)
        printf("%c = %s\n",a[i].l,a[i].r);

    printf("\nAfter Constant Folding:\n");
    for(i=0;i<n;i++){
        if(sscanf(a[i].r,"%d%c%d",&x,&op,&y)==3){
            if(op=='+') sprintf(a[i].r,"%d",x+y);
            if(op=='-') sprintf(a[i].r,"%d",x-y);
            if(op=='*') sprintf(a[i].r,"%d",x*y);
        }
        printf("%c = %s\n",a[i].l,a[i].r);
    }

    printf("\nAfter Strength Reduction:\n");
    for(i=0;i<n;i++){
        char *p=strstr(a[i].r,"*2");
        if(p && p[2]=='\0'){
            *p='\0';
            strcpy(t,a[i].r);
            sprintf(a[i].r,"%s+%s",t,t);
        }
        printf("%c = %s\n",a[i].l,a[i].r);
    }

    printf("\nAfter Algebraic Transformation:\n");
    for(i=0;i<n;i++){
        int k=strlen(a[i].r);
        if(k>=2 && (!strcmp(a[i].r+k-2,"+0") ||
                    !strcmp(a[i].r+k-2,"-0") ||
                    !strcmp(a[i].r+k-2,"*1") ||
                    !strcmp(a[i].r+k-2,"/1")))
            a[i].r[k-2]='\0';
        else if(k>=2 && !strcmp(a[i].r+k-2,"*0"))
            strcpy(a[i].r,"0");

        printf("%c = %s\n",a[i].l,a[i].r);
    }
    return 0;
}
