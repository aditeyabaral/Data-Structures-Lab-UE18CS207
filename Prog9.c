#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
struct tree
{
    NODE *root;
};
typedef struct tree TREE;
void insert(TREE *t, int key)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    if(t->root==NULL)
        t->root = node;
    else
    {
        NODE *prev = NULL;
        NODE *pres = t->root;
        while(pres!=NULL)
        {
            prev = pres;
            if(key>pres->data)
                pres = pres->right;
            else
                pres = pres->left;
        }
        if(key>prev->data)
            prev->right = node;
        else
            prev->left = node;
    }
}
void preorder(NODE *node)
{
    if(node!=NULL)
    {
        printf("%d->",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
int leaf=0;
int leaves(NODE *node)
{
    if (node==NULL);
    else if(node->left==NULL && node->right==NULL)
        leaf++;
    else
    {
        leaves(node->left);
        leaves(node->right);
        return leaf;    
    }
}
int max(int a, int b)
{
    return (a>=b?a:b);
}
int height(NODE *node)
{
    if(node==NULL)
        return 0;
    else 
        return 1 + max(height(node->left),height(node->right));
}
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    t->root = NULL;
    int val;
    while(1)
    {
        printf("Enter node : ");
        scanf("%d", &val);
        if(val==-1)
            break;
        insert(t,val);
    }
    preorder(t->root);
    printf("\n");
    printf("Height = %d\n", height(t->root));
    printf("Leaves = %d", leaves(t->root));
}