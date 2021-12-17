#include "A.h"
#include "B.h"
#include "C.h"
#include <stdio.h>
#include <stdint.h>

void B(long n){
    printf("\nYou're in B()\nASCII string: ");
    char *a=(char*)&n;
    for (int i = 7; i >= 0; i--)
    {
        printf("%c",*(a+i));
    }
    void* ptr=C;
    asm( "movq %0, 8(%%rbp)" : : "r" ( ptr ));
    return;
}