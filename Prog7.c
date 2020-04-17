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
    //NODE *tail;
};
typedef struct list LIST;
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
void insert(LIST *l,int key)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = key;
    node->link = NULL;
    if(l->head==NULL)
        l->head = node;
    else
    {
        NODE *pres = l->head;
        NODE *prev = NULL;
        while(pres!=NULL)
        {
            prev = pres;
            pres = pres->link;
        }
        prev->link = node;
    }
}
void delete(LIST *l)
{
    if(l->head!=NULL)
        l->head = l->head->link;
}
int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    l->head = NULL;
    //l->tail = NULL;
    int val;
    for(int i=1;i<=6;i++)
    {
        printf("Enter element : ");
        scanf("%d", &val);
        insert(l,val);
    }
    display(l);
    delete(l);
    display(l);
    delete(l);
    display(l);
}
