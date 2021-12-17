#include <stdio.h>

long binsearch(unsigned int *a,int l,int r,unsigned int x){
    // binarysearch
    int m;
    while (l<=r){
        m=(l+r)/2;
        if(a[m]==x)return m;
        if(a[m]>x)r=m-1;
        else l=m+1;
    }return -1;
}
int main(){
    int n;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    unsigned int a[n];
    long x;
    printf("Enter %d space separated integers: \n",n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter no to find index.To exit type -1: ");
    while (1)
    {
        scanf("%ld",&x);
        if(x==-1)break;
        printf("Index: %ld\n\nEnter next no. (-1 for exit): ",binsearch(a,0,sizeof(a)/sizeof(a[0])-1,x));
    }
}