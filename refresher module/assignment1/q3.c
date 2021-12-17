#include <stdio.h>

void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void swapArr(){
    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int arr1[n],arr2[n];
    printf("Enter %d space separated elements elements of arr1: ",n);
    for (int i = 0; i < n; i++){
        scanf("%d",&arr1[i]);
    }
    printf("Enter %d space separated elements elements of arr2: ",n);
    for (int i = 0; i < n; i++){
        scanf("%d",&arr2[i]);
    }
    printf("Swapping...\n");
    for (int i = 0; i < n; i++)
    {
        swap(&arr1[i],&arr2[i]);
    }
    
    printf("arr1 after swap: ");
    for (int i = 0; i < n; i++){
        printf("%d ",arr1[i]);
    }printf("\n");
    printf("arr2 after swap: ");
    for (int i = 0; i < n; i++){
        printf("%d ",arr2[i]);
    }printf("\n");
}
int main(){
    int q;
    printf("Enter 0 to swap 2 int; 1 to swap 2 arrays: ");
    scanf("%d",&q);
    if(q){
        swapArr();
    }else{
        int a,b;
        printf("Enter 2 space separated integers(a b): ");
        scanf("%d %d",&a,&b);
        printf("integers before swap: a=%d b=%d\n",a,b);
        swap(&a,&b);
        printf("integers after swap : a=%d b=%d\n",a,b);
    }
}