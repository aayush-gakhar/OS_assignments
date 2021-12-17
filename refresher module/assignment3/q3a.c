#include <stdio.h>
#include <stdlib.h>

// BST node
struct node{
    int val;
    struct node *left, *right;
};


struct node* newNode(int v){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->val=v;
    n->left=n->right=NULL;
    return n;
}
void inorder(struct node* curr){
    if(curr==NULL)return;
    inorder(curr->left);
    printf("%d ", curr->val);
    inorder(curr->right);
}

struct node* insert(struct node *curr,int k){
    if(curr==NULL){
        return newNode(k);
    }
    if(curr->val<k)curr->right=insert(curr->right,k);
    else if(curr->val>k)curr->left=insert(curr->left,k);
    return curr;
}

struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
struct node* deleteNode(struct node* curr, int key){
    if (curr == NULL)
        return curr;
    if (key < curr->val)
        curr->left = deleteNode(curr->left, key);
    else if (key > curr->val)
        curr->right = deleteNode(curr->right, key);
    else {
        if (curr->left == NULL) {
            struct node* temp = curr->right;
            return temp;
        }
        else if (curr->right == NULL) {
            struct node* temp = curr->left;
            return temp;
        }
        struct node* temp = minValueNode(curr->right);
        curr->val = temp->val;
        curr->right = deleteNode(curr->right, temp->val);
    }
    return curr;
}
int main(){
    printf("BST:\nI -> insert x\nD -> delete x\nP -> print inorder\nE -> exit\n");
    char q;
    int x;
    struct node *root=NULL;
    while(1){
        scanf(" %c",&q);
        fflush(stdin);
        if(q=='E')break;
        else if (q=='P'){
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n\n");
        }else if (q=='I')
        {
            printf("Enter x: ");
            scanf(" %d",&x);
            root=insert(root,x);
            printf("done\n");
        }else if (q=='D')
        {
            printf("Enter x: ");
            scanf(" %d",&x);
            root=deleteNode(root,x);
            printf("done\n");
        }        
    }
    return 0;
}
