#include <stdio.h>

void add(int a,int b){
    printf("%d\n",a+b);
}
void sub(int a,int b){
    printf("%d\n",a-b);
}
void mul(int a,int b){
    printf("%d\n",a*b);
}
void divn(int a,int b){
    printf("%d\n",a/b);
}
void expn(int a,int b){
    int e=1;
    for (int i = 0; i < b; i++){
        e*=a;
    }
    printf("%d\n",e);
}

int main(){
    // arr of func pointers
    void (*arr[5])(int,int)={add,sub,mul,divn,expn};
    printf("a -> add\ns -> sub\nm -> mul\nd -> div\ne -> exp\nx -> exit\n");
    char q;
    int m,n;
    while(1){
        printf(":");
        scanf(" %c",&q);
        fflush(stdin);
        if(q=='x')break;
        else if (q=='a'){
            printf("Enter 2 nos to add: ");
            scanf("%d %d",&m,&n);
            (**arr[0])(m,n);
            printf("\n");
        }else if (q=='s'){
            printf("Enter 2 nos to sub: ");
            scanf("%d %d",&m,&n);
            (**arr[1])(m,n);
            printf("\n");
        }else if (q=='m'){
            printf("Enter 2 nos to mul: ");
            scanf("%d %d",&m,&n);
            (**arr[2])(m,n);
            printf("\n");
        }else if (q=='d'){
            printf("Enter 2 nos to div: ");
            scanf("%d %d",&m,&n);
            (**arr[3])(m,n);
            printf("\n");
        }else if (q=='e'){
            printf("Enter 2 nos to exp: ");
            scanf("%d %d",&m,&n);
            (**arr[4])(m,n);
            printf("\n");
        }   
    }
}