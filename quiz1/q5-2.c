#include <stdio.h>

int main(void){
    int a=2,*b=NULL;
    b=(int*)0x1000;
    printf("%p\n",b+1);
    printf("%p\n",(char*)b+1);
    printf("%p",(void*)b+1);
    printf("%lu",sizeof(void));
}