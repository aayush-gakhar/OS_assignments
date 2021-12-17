#include <stdio.h>
#include <stdlib.h>


struct node{
    int val;
    struct node *next;
};
struct node *head=NULL;

void push(int val){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->val=val;
    ptr->next=head;
    head=ptr;
}

void pop(){
    if(head==NULL){
        printf("Stack empty");
        return;
    }
    int val=head->val;
    head=head->next;
    printf("%d",val);
}
void peek(){
    if(head==NULL){
        printf("Stack empty");
        return;
    }
    printf("%d",head->val);
}
int main(){
    printf("Stack:\nU -> push x\nO -> pop x\nP -> peek\nX -> exit\n");
    char q;
    int x;
    while(1){
        printf(":");
        scanf(" %c",&q);
        fflush(stdin);
        if(q=='X')break;
        else if (q=='P'){
            printf("peek: ");
            peek();
            printf("\n\n");
        }else if (q=='U')
        {
            printf("Enter x: ");
            scanf(" %d",&x);
            push(x);
            printf("\n");
        }else if (q=='O')
        {
            printf("popped: ");
            pop();
            printf("\n\n");
        }        
    }
}
