#include <stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void selectionsort(int arr[], int n){
    int i,j,k;
    for (i = 0; i < n - 1; ++i) {
        k=i;
        for (j = i+1; j < n; ++j) {
            if(arr[j]<arr[k])
                k=j;
        }
        swap(&arr[k],&arr[i]);
    }
}
void bubblesort(int arr[],int n){
    int i,j;
    for (i = 0; i < n-1 ; ++i) {
        for (j = 0; j < n - i - 1; ++j) {
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
        }
    }
}

void printarr(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
}

int main() {
    int n;
    printf("Enter no of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter space separated %d elements: ",n);
    for (int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    int t;
    printf("Enter 0 for selection sort, 1 for bubblesort: ");
    scanf("%d",&t);
    if(t){
        bubblesort(a,n);
    }else{
        selectionsort(a,n);
    }
    printarr(a,n);
    return 0;
}
