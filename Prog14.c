#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
    int lthread;
    int rthread;
};
typedef struct node NODE;
struct tree
{
    NODE *root;
};
typedef struct tree TREE;
void preorder(NODE *node)
{
    if(node->lthread==0)
        preorder(node->left);
    if(node->rthread==0)
        preorder(node->right);
    printf("%d ",node->data);
}
void insert(TREE *t, int x)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = x;
    node->left = NULL;
    node->right = NULL;
    node->lthread = 1;
    node->rthread = 1;
    if(t->root==NULL)
        t->root = node;
    else
    {
        NODE *pres = t->root;
        while(pres!=NULL)
        {
            if(x>pres->data)
            {
                if(pres->rthread==0)
                    pres = pres->right;
                else
                    break;
            }
            else
            {
                if(pres->lthread==0)
                    pres = pres->left;
                else
                    break;
            }
        }
        if(x<pres->data)
        {
            node->left = pres->left;
            node->right = pres;
            pres->lthread = 0;
            pres->left = node;
        }
        else
        {
            node->right = pres->right;
            node->left = pres;
            pres->right = node;
            pres->rthread = 0;
        }
    }
}
int main()
{
    TREE *t = (TREE*)malloc(sizeof(TREE));
    t->root = NULL;
    int val;
    while(1)
    {
        printf("Enter node : ");
        scanf("%d",&val);
        if(val==-1)
            break;
        insert(t,val);
    }
    preorder(t->root);
    printf("\n");
}