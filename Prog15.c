#include <stdio.h>
#include <stdlib.h>
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
struct tree
{
    NODE *root;
};
typedef struct tree TREE;
NODE *stack[100];
int top=-1;
NODE *pop();
void push(NODE*);
int operator(char);
void preorder(NODE *node)
{
    if(node!=NULL)
    {
        printf("%c",node->data);
        preorder(node->left);
        preorder(node->right);
    }
}
NODE* create_tree(char *infix)
{
    int i = 0;
    while(infix[i])
    {
        NODE *node = (NODE*)malloc(sizeof(NODE));
        node->data = infix[i];
        node->left = NULL;
        node->right = NULL;
        if(operator(infix[i]))
        {
            node->left = pop();
            node->right = pop();
        }
        push(node);
        i++;
    }
    return pop();
}
int evaluate(NODE* node)
{
    if(operator(node->data))
    {
        switch (node->data)
        {
            case '+': return evaluate(node->left)+evaluate(node->right);
            case '-': return evaluate(node->left)-evaluate(node->right);
            case '*': return evaluate(node->left)*evaluate(node->right);
            case '/': return evaluate(node->left)/evaluate(node->right);
        }
    }
    else
    {
        int val;
        printf("Enter value for %c : ", node->data);
        scanf("%d",&val);
        return val;
    }
    
}
int operator(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/' || x=='%')
        return 1;
    return 0;
}
void push(NODE* x)
{
    top++;
    stack[top]=x;
}
NODE *pop()
{
    top-=1;
    return stack[top+1];
}
int empty()
{
    if(top==-1)
        return 1;
    return 0;
}
int main()
{
    TREE *t =(TREE*)malloc(sizeof(TREE));
    t->root = NULL;
    char infix[100];
    printf("Enter postfix : ");
    scanf("%s",infix);
    t->root = create_tree(infix);
    int val = evaluate(t->root);
    printf("Value = %d\n",val);
    preorder(t->root);
}