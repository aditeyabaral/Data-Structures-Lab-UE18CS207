#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int priority;
};
typedef struct node NODE;
void display();
void heapify();
void insert(int,int);
void delete();
NODE *heap[100];
int n;
int top = -1;
void insert(int data, int pty)
{
    top++;
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->priority = pty;
    heap[top] = node;
}
void delete()
{
    if(top!=-1)
    {
        for(int i=0;i<top;i++)
            heap[i] = heap[i+1];
        top--;
    }
}
void heapify(int n)
{
    int j, i;
    NODE* key;
    for(int k=(n-1)/2;k>=0;k--)
    {
        j = k;
        key = heap[k];
        i = 2*j+1;
        while(i<=n)
        {
            if((i+1)<=n)
            {
                if(heap[i+1]->priority>heap[i]->priority)
                    i++;
            }
            if(key->priority<heap[i]->priority)
            {
                heap[j] = heap[i];
                j = i;
                i = 2*j+1;
            }
            else
                break;
        }
        heap[j] = key;
    }
}
void display()
{
    for(int i=0;i<=top;i++)
        printf("%d %d\n",heap[i]->data,heap[i]->priority);
    printf("\n");
}
int main()
{
    printf("Enter value of n :");
    scanf("%d",&n);
    int x,pty;
    for(int i=0;i<n;i++)
    {
        printf("Enter data and priority : ");
        scanf("%d %d",&x,&pty);
        insert(x,pty);
    }
    heapify(n-1);
    display();
    delete();
    display();
}