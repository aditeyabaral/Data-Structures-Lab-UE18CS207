#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct trienode
{
    int end;
    struct trienode *child[255];
};
typedef struct trienode NODE;
struct stack
{
    NODE *node;
    int index;
};
typedef struct stack STACK;
int top = -1;
NODE *root;
char word[20];
STACK s[255];
int len;
NODE* createnode()
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->end = 0;
    for(int i = 0;i<255;i++)
        node->child[i] = NULL;
    return node;
}
void insert(char *key)
{
    int index;
    NODE *pres = root;
    for(int i=0;key[i]!='\0';i++)
    {
        index = key[i];
        if(pres->child[index]==NULL)
            pres->child[index] = createnode();
        pres = pres->child[index];
    }
    pres->end = 1;
}
void display(NODE *pres)
{
    for(int i = 0;i<255;i++)
    {
        if(pres->child[i]!=NULL)
        {
            word[len++] = i;
            if(pres->child[i]->end==1)
            {
                for(int j=0;j<len;j++)
                    printf("%c", word[j]);
                printf("\n");
            }
            display(pres->child[i]);
        }
    }
    len--;
    return;
}
void prefix(char *s)
{
    NODE *pres = root;
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index = s[i];
        if (pres->child[index]!=NULL)
        {
            word[len++] = index;
            pres = pres->child[index];
        }
    }
    if(pres->end==1)
        printf("%s\n",word);
    display(pres);
}
void push(NODE* node, int n)
{
    top++;
    s[top].node = node;
    s[top].index = n;
}
STACK pop()
{
    top--;
    return s[top+1];
}
int check(NODE* node)
{
    for(int i=0;i<255;i++)
    {
        if(node->child[i]!=NULL)
            return 1;
    }
    return 0;
}
void delete(char *s)
{
    NODE *pres = root;
    int index;
    for(int i=0;s[i]!='\0';i++)
    {
        index = s[i];
        if(pres->child[index]==NULL)
        {
            printf("Not found!\n");
            return;
        }
        push(pres,index);
        pres = pres->child[index];
    }
    pres->end = 0;
    push(pres,-1);
    STACK temp;
    while(1)
    {
        temp = pop();
        if(temp.index!=-1)
            temp.node->child[temp.index] = NULL;
        else if(temp.node==root || check(temp.node) || temp.node->end)
            break;
        else
            free(temp.node);
    }
    return;
}
int main()
{
    root = createnode();
    char s[20];
    while(1)
    {
        printf("Enter word : ");
        scanf("%s",s);
        if(!strcmp(s,"0"))
            break;
        insert(s);
    }
    len = 0;
    display(root);
    printf("Enter prefix : ");
    scanf("%s",word);
    len = 0;
    prefix(word);
    printf("Enter deletion : ");
    scanf("%s",word);
    delete(word);
    len = 0;
    display(root);
}