#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int key;
    char word[20];
    int mark;
};
typedef struct node NODE;
NODE *h;
int len = 0;
int size;
void insert(int key, char *s)
{
    if(len==size)
    {
        printf("Table full!\n");
        return;
    }
    int index = key%size;
    while(h[index].mark==1)
        index = (index+1)%size;
    h[index].key = key;
    h[index].mark=1;
    strcpy(h[index].word,s);
    len++;
}
void display()
{
    if(len==0)
        return;
    else
    {
        for(int i=0;i<size;i++)
        {
            if(h[i].mark==1)
                printf("%d %s\n", h[i].key,h[i].word);
        }
    }
}
void search(int key)
{
    if(len==0)
        return;
    else
    {
        int index = key%size;
        int ctr = 0;
        while(ctr<=len)
        {
            if(h[index].key==key)
            {
                printf("%d %s\n", h[index].key,h[index].word);
                return;
            }
            index = (index+1)%size;
            if(h[index].mark==1) ctr++;
        }
        printf("Not found!\n");
    }
}
void delete(int key)
{
    if(len==0)
        return;
    else
    {
        int index = key%size;
        int ctr = 0;
        while(ctr<=len)
        {
            if(h[index].key==key)
            {
                h[index].mark = 0;
                return;
            }
            index = (index+1)%size;
            if(h[index].mark==1) ctr++;
        }
        printf("Not found!\n");
    }
}
int main()
{
    printf("Enter size : ");
    scanf("%d",&size);
    h = (NODE*)malloc(sizeof(NODE)*size);
    for(int i=0;i<size;i++)
        h[i].mark = 0;
    char s[20];
    int key;
    while(1)
    {
        printf("Enter key and word : ");
        scanf("%d %s",&key,s);
        if(key==-1) break;
        insert(key,s);
    }
    display();
    printf("Enter key to search : ");
    scanf("%d",&key);
    search(key);
    printf("Enter key to delete : ");
    scanf("%d",&key);
    delete(key);
    display();
}