#include "A.h"
#include "C.h"
#include <stdio.h>


void A(){
    printf("You are in A()\n");
    long n;
    printf("Enter long integer: ");
    scanf("%ld",&n);
    B(n);
    printf("Back to A\n"); // prints if returns to A
}

int main()
{
    A();
    return 0;
}