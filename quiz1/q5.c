#include <stdio.h>
#include <string.h>

void copyarr(char* p1,char p2[]){
    memcpy(p2, p1, sizeof(p1));
    memcpy(p2,"ABCD",4);
}
int main(){
    char arr1[100];
    char arr2[100];
    printf("Enter a string:");
    scanf("%[^\n]s",arr1);
    copyarr(arr1,arr2);
    printf("%s",arr2);
    return 0;
}