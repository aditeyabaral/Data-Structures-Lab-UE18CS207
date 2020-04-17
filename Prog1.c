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
void insert(LIST *l, int key)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = key;
    node->link = NULL;
    if(l->head == NULL)
        l->head = node;
    else
    {
        NODE *prev = NULL;
        NODE *pres = l->head;
        while(pres!=NULL && key>pres->data)
        {
            prev = pres;
            pres = pres->link;
        }
        if(prev==NULL)
        {
            node->link = l->head;
            l->head = node;
        }
        else
        {
            prev->link = node;
            node->link = pres;
        }
    }
}
void delete(LIST *l)
{
    NODE *pres = l->head;
    NODE *prev = NULL;
    while(pres->link!=NULL)
    {
        prev = pres;
        pres = pres->link;
    }
    prev->link = NULL;
}
int search(LIST *l,int s)
{
    NODE *pres = l->head;
    while(pres!=NULL)
    {
        if(pres->data == s)
            return 1;
        pres = pres->link;
    }
    return 0;
}
void display(LIST *l)
{
    NODE *pres = l->head;
    while(pres!=NULL)
    {
        printf("%d ",pres->data);
        pres = pres->link;
    }
    printf("\n");
}
int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    l->head = NULL;
    int val;
    for(int i=1;i<=6;i++)
    {
        printf("Enter element : ");
        scanf("%d", &val);
        insert(l,val);
    }
    display(l);
    printf("Enter value to search : ");
    scanf("%d",&val);
    printf("Found = %d\n", search(l,val));
    delete(l);
    display(l);
}