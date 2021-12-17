#include <stdlib.h>
#include <stdio.h>

struct node {
    int a;
    int b;
};

void addvalues(struct node *n, int a, int b) {
    n->a = a;
    n->b = b;
}

int main(int argc, char const *argv[])
{
    struct node n;
    addvalues(n, 1, 2);
    return 0;
}

