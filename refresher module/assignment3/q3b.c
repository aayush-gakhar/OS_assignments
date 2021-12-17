#include<stdio.h>
#include<stdlib.h>
 
// AVL tree node
struct Node{
    int val;
    struct Node *left, *right;
    int height;
};

// function to get the height of the tree
int height(struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a : b;
}

struct Node* newNode(int val){
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->val   = val;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;
    return(node);
}
 
// A utility function to right rotate subtree rooted with y
struct Node *rightRotate(struct Node *y){
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
struct Node *leftRotate(struct Node *x){
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int getBalance(struct Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
 
// function to insert a val in the tree
struct Node* insert(struct Node* node, int val){
    if (node == NULL)
        return(newNode(val));
 
    if (val < node->val)
        node->left  = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));
 
    int balance = getBalance(node);

    if (balance > 1 && val < node->left->val)
        return rightRotate(node);
 
    if (balance < -1 && val > node->right->val)
        return leftRotate(node);
 
    if (balance > 1 && val > node->left->val){
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }
 
    if (balance < -1 && val < node->right->val){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
 
    return node;
}

struct Node * minValueNode(struct Node* node){
    struct Node* current = node;
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct Node* deleteNode(struct Node* root, int val){
    if (root == NULL)
        return root;
 
    if ( val < root->val )
        root->left = deleteNode(root->left, val);

    else if( val > root->val )
        root->right = deleteNode(root->right, val);
 
    else{
        if( (root->left == NULL) || (root->right == NULL) )
        {
            struct Node *temp = root->left ? root->left:root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else 
             *root = *temp;
            free(temp);
        }
        else{
            struct Node* temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
    }
    if (root == NULL)
      return root;
    root->height = 1 + max(height(root->left),
                           height(root->right));

    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
 
    if (balance > 1 && getBalance(root->left) < 0){
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
 
// A function to print inorder traversal
void inorder(struct Node* curr){
    if(curr==NULL)return;
    inorder(curr->left);
    printf("%d ", curr->val);
    inorder(curr->right);
}

int main()
{
  struct Node *root = NULL;

  printf("BST:\nI -> insert x\nD -> delete x\nP -> print inorder\nE -> exit\n");
    char q;
    int x;
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