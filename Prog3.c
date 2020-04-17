#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node NODE;
struct list
{
    NODE *head;
};
typedef struct list LIST;
void insert(LIST *l, int pos, int val)
{
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = val;
    node->prev = NULL;
    node->next = NULL;
    if(l->head==NULL)
        l->head = node;
    else
    {
        NODE *pres = l->head;
        NODE *prev = NULL;
        int ctr = 0;
        while(pres!=NULL && ctr!=pos)
        {
            prev = pres;
            pres = pres->next;
            ctr++;
        }
        if(prev==NULL)
        {
            node->next = l->head;
            l->head->prev = node;
            l->head = node;
        }
        else if(pres==NULL)
        {
            prev->next = node;
            node->next = NULL;
            node->prev = prev;
        }
        else
        {
            prev->next = node;
            node->next = pres;
            pres->prev = node;
            node->prev = prev;
        }
    }
}
void delete(LIST *l, int pos)
{
    if(l->head!=NULL)
    {
        NODE *pres = l->head;
        NODE *prev = NULL;
        int ctr = 0;
        while(pres!=NULL && ctr!=pos)
        {
            prev = pres;
            pres = pres->next;
            ctr++;
        }
        if(prev==NULL)
        {
            l->head = pres->next;
            l->head->prev = NULL;
            free(pres);
        }
        else if (pres->next==NULL)
        {
            prev->next = NULL;
            free(pres);
        }
        else
        {
            prev->next = pres->next;
            pres->next->prev = prev;
            free(pres);
        }
    }
}
void display(LIST *l)
{
    NODE *pres = l->head;
    while(pres!=NULL)
    {
        printf("%d ",pres->data);
        pres = pres->next;
    }
    printf("\n");
}
int main()
{
    LIST *l = (LIST*)malloc(sizeof(LIST));
    l->head = NULL;
    int val, pos;
    for(int i=1;i<=6;i++)
    {
        printf("Enter element and position : ");
        scanf("%d %d", &val, &pos);
        insert(l,pos,val);
    }
    display(l);
    printf("Enter position : ");
    scanf("%d",&pos);
    delete(l,pos);
    display(l);
}