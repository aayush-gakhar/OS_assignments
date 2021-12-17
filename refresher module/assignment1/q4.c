#include <stdio.h>

int main(int argc,char* argv[]){
    int i;
    
    // length of string
    for(i=0;argv[1][i]!='\0';i++);

    int l=i;
    // new string rev
    char rev[l+1];
    for (i = 0; i < l; ++i) {
        rev[i]=argv[1][l-i-1];
    }
    rev[l]='\0';
    printf("reversed: %s\n",rev);
}