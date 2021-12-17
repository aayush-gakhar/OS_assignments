#include <stdio.h>
#include <stdint.h>

void C(){
    printf("C");
    uint64_t sp;
    asm( "mov %%rbp, %0" : "=rm" ( sp )); // sp=stack pointer
    printf("sp=%llu\n",sp); // sp
    uint64_t* p=(uint64_t*)sp;
    printf("val=%llu\n",*p); // value stored at sp
}

void B(long n){
    char *a=(char*)&n;
    for (int i = 0; i < 8; i++)
    {
        printf("%c\n",*(a+i));
    }
    
    char str[9];
    int i=0,c;
    while (n>0)
    {
        str[i++]=(char)(n%256);
        // printf("%d %ld\n",str[i-1],n);
        n/=256;
    }str[i]='\0';
    printf("%s",str);
    


    // uint64_t sp;
    // asm( "mov %%rbp, %0" : "=rm" ( sp )); // sp=stack pointer
    // printf("sp=%llu\n",sp); // sp
    // uint64_t* p=(uint64_t*)sp;
    // printf("val=%llu\n",*p); // value stored at sp
    // void **addr = __builtin_extract_return_addr (__builtin_return_address (0));
    // printf("%p\n",addr);
    // void *ptr=C;

    
    // C();
    return;
}

void A(){
    // printf("A");
    long n=24930;
    // uint64_t sp;
    // asm( "mov %%rbp, %0" : "=rm" ( sp )); // sp=stack pointer
    // printf("sp=%llu\n",sp); // sp
    // uint64_t* p=(uint64_t*)sp;
    // printf("val=%llu\n",*p); // value stored at sp
    B(n);
    // printf("Back to a");
}

int main()
{
    // printf("%p\n",A);
    A();
    return 0;
}