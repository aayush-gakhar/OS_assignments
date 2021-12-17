#include <stdio.h>
#include <stdint.h>

void B(long n){
    printf("%ld",n);
    return;
}

void A(){
    long n=1311768465173141112;
    B(n);
}

int main()
{
    A();
    return 0;
}