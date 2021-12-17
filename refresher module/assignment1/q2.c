#include <stdio.h>

int main(int argc,char* argv[]){
    char c[33];
    // take 2 inputs of length 32 and add
    char carry=0,s;
    for (int i = 31; i >=0; i--) {
        s=argv[1][i]+argv[2][i]+carry;
        carry=s/128;
        c[i]=s%128;
    }
    c[32]='\0';
    printf("%s",c);
}