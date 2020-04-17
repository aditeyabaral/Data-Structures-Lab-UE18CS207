#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
typedef struct node NODE;
struct list
{
    NODE *head;
};
typedef struct list LIST;
int len(LIST*);
void display(LIST*);
void insert(LIST *l, int key)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = key;
    node->link = NULL;
    if(l->head == NULL)
    {
        l->head = node;
        node->link = l->head;
    }
    else
    {
        NODE *pres = l->head;
        NODE *prev = NULL;
        while(pres->link!=l->head)
        {
            prev = pres;
            pres = pres->link;
        }
        pres->link = node;
        node->link = l->head;
    }
}
int josephus(LIST *l, int k)
{
    NODE *pres = l->head;
    int ctr = 0;
    while(ctr!=k)
    {
        pres = pres->link;
        ctr++;
    }
    while(len(l)!=1)
    {
        if(pres->link==l->head)
            l->head = l->head->link;
        pres->link = pres->link->link;
        pres = pres->link;
    }
    return pres->data;
}
int len(LIST *l)
{
    NODE *pres = l->head;
    int ctr = 0;
    if(l->head==NULL) return 0;
    while(pres->link!=l->head)
    {
        pres = pres->link;
        ctr++;
    }
    return ctr+1;
}
void display(LIST *l)
{
    NODE *pres = l->head;
    while(pres->link!=l->head)
    {
        printf("%d ",pres->data);
        pres = pres->link;
    }
    printf(" %d\n",pres->data);
}
int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    l->head = NULL;
    int val;
    for(int i=0;i<5;i++)
    {
        printf("Enter value : ");
        scanf("%d",&val);
        insert(l,val);
    }
    display(l);
    int k;
    printf("Enter k : ");
    scanf("%d",&k);
    printf("Joseph : %d",josephus(l,k));
}