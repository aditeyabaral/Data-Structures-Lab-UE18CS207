#include <stdio.h>
#include <stdlib.h>
void init (int* t)
{
    for(int i=0;i<1000;i++)
        t[i] = -1;
}
void insert(int *t, int i)
{
    int x;
    printf("Enter node : ");
    scanf("%d",&x);
    if(x!=-1)
    {
        t[i] = x;
        printf("Left subtree of %d : ",x);
        insert(t,2*i);
        printf("Right subtree of %d : ",x);
        insert(t,2*i+1);
    }
}
void postorder(int *t, int i)
{
    if(t[i]!=-1)
    {
        postorder(t,2*i);
        postorder(t,2*i+1);
        printf("%d->",t[i]);
    }
}
void inorder(int *t, int i)
{
    if(t[i]!=-1)
    {
        inorder(t,2*i);
        printf("%d->",t[i]);
        inorder(t,2*i+1);
    }
}
int main()
{
    int *t = (int*)malloc(sizeof(int)*1000);
    init(t);
    insert(t,1);
    inorder(t,1);
    printf("\n");
    postorder(t,1);
}