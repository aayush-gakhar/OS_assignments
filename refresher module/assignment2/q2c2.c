#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void enq(int val){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->val=val;
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        tail=ptr;
    }
    else{
        tail->next=ptr;
        tail=tail->next;
    }
}

void deq(){
    if(head==NULL){
        printf("Queue empty");
        return;
    }
    int val=head->val;
    head=head->next;
    printf("%d",val);
    return;
}
void peek(){
    if(head==NULL){
        printf("Queue empty");
        return;
    }
    printf("%d",head->val);
}
int main(){
    printf("Queue:\nE -> enqueue x\nD -> dequeue x\nP -> peek\nX -> exit\n");
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
        }else if (q=='E')
        {
            printf("Enter x: ");
            scanf(" %d",&x);
            enq(x);
            printf("\n");
        }else if (q=='D')
        {
            printf("popped: ");
            deq();
            printf("\n\n");
        }        
    }
}
