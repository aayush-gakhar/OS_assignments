#include <stdio.h>
#include <stdlib.h>

int main(){
    int rows;
    printf("Enter no of rows: ");
    scanf("%d",&rows);
    printf("Enter space separated lengths of %d rows: ",rows);

    // arr which contains row lengths
    int r[rows];

    // array of pointers to different rows
    int** arr=(int**)malloc(sizeof *arr * rows);

    for(int i=0;i<rows;i++){
        scanf("%d",&r[i]);
        // arr for each row
        arr[i]=(int*)malloc(sizeof(int) * r[i]);
    }

    printf("arr:\n");
    for(int i=0;i<rows;i++){
        for (int j = 0; j < r[i]; j++){
            arr[i][j]=1;
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
    
    printf("arr is the required array\n");
}