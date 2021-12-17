#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[101];
    int rollno;
    int year;
    char prog[101];
    struct node *next;
};
struct node *head=NULL;
struct node *tail=NULL;

void insert(char name[],int rn,int year,char prog[]){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    strcpy(n->name,name);
    n->rollno=rn;
    n->year=year;
    strcpy(n->prog,prog);
    if(tail==NULL){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=tail->next;
}

void printList(){
    struct node *ptr=head;
    while (ptr!=NULL){
        printf("%s %d %d %s\n",ptr->name,ptr->rollno,ptr->year,ptr->prog);
        ptr=ptr->next;
    }return;
}

int main(){
    printf("made 3 nodes and printed them:\n");
    insert("A",12,2020,"cse");
    insert("B",15,2021,"csd");
    insert("C",13,2024,"ece");
    printList();
}
