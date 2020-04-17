#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int key;
    char word[20];
    struct node *link;
};
typedef struct node NODE;
struct hash
{
    NODE *head;
    int len;
};
typedef struct hash HASH;
HASH *h;
int size;
void insert(int key, char *name)
{
    int index = key%size;
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->key = key;
    node->link = NULL;
    strcpy(node->word,name);
    if(h[index].head==NULL)
        h[index].head = node;
    else
    {
        node->link = h[index].head;
        h[index].head = node;
        h[index].len++;
    }
}
void display()
{
    for(int i=0;i<size;i++)
    {
        if(h[i].head!=NULL)
        {
            NODE *pres = h[i].head;
            while(pres!=NULL)
            {
                printf("%d %s\n", pres->key,pres->word);
                pres = pres->link;
            }
        }
    }
}
void search(int key)
{
    int index = key%size;
    if(h[index].head==NULL)
        printf("Not found!\n");
    else
    {
        NODE *pres = h[index].head;
        while(pres!=NULL)
        {
            if(pres->key==key)
            {
                printf("%d %s\n",pres->key,pres->word);
                return;
            }
            pres = pres->link;
        }
        printf("Not found!");
    }
}
int main()
{
    printf("Enter size of table : ");
    scanf("%d",&size);
    h = (HASH*)malloc(sizeof(HASH)*size);
    for(int i=0;i<size;i++)
    {
        h[i].len = 0;
        h[i].head = NULL;
    }
    char name[20];
    int key;
    while(1)
    {
        printf("Enter key and name : ");
        scanf("%d %s",&key,name);
        if(key==-1)
            break;
        insert(key,name);
    }
    display();
    printf("Enter key to search : ");
    scanf("%d",&key);
    search(key);
    //printf("Enter key to delete : ");
    //scanf("%d",&key);
    //delete(key);
    //display();
}