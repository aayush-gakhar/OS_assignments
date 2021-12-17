#include <stdio.h>
#include <stdint.h>

void C(){
    long* sp;
    asm( "mov %%rsp, %0" : "=rm" ( sp )); // sp=stack pointer
    printf("sp=%p\n",sp); // sp
    printf("val=%lx\n",*sp); // value stored at sp
}

void B(){
    // char str[9];
    // int i=0,c;
    // while (n>0)
    // {
    //     str[i++]=(char)n%8;
    //     n/=8;
    // }str[i]='\0';
    void *addr = __builtin_extract_return_addr (__builtin_return_address (0));
    printf("%p\n",addr);
    void* ptr=C;
    asm( "movq %0, 8(%%rbp)" : : "r" ( ptr )); // sp=stack pointer
    // C();
}

void A(){
    // long n=12345623;
    long* sp;
    void *addr = __builtin_extract_return_addr (__builtin_return_address (0));
    printf("%p\n",addr);
    
    
    asm( "mov %%rsp, %0" : "=rm" ( sp )); // sp=stack pointer
    printf("sp=%p\n",sp); // sp
    printf("val=%lx\n",*(sp)); // value stored at sp
    B();
    printf("Back to a");
}

int main()
{
    printf("%p\n",A);
    printf("%p\n",B);
    printf("%p\n",C);
    printf("%p\n",main);

    A();
    return 0;
}