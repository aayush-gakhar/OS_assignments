#include <stdio.h>

void foo(){
    int a=1;
    printf("%p",&a);
}

int main() {
    int a=1;
    printf("%p\n",&a);
    float x=0;
    printf("%f",x/100);
    return 0;
}