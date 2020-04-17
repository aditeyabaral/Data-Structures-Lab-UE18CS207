#include <stdio.h>
#include <stdlib.h>
int visited[100];
int graph[100][100];
int n,ctr = 0;
int q[100];
int top=-1;
void enqueue(int);
int dequeue();
int empty();
void dfs(int v)
{
    visited[v]=ctr;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0 && graph[v][i]==1)
            dfs(i); 
    }
}
int components()
{
    for (int i=1;i<=n;i++)
        visited[i]=0;
    for (int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            ctr++;
            dfs(i);
        }
    }
    return ctr;
}
void create_graph()
{
    int i,j;
    while (1)
    {
        printf("Enter source and destination vertex : ");
        scanf("%d %d", &i,&j);
        if(i==0 && j==0)
            break;
        else
            graph[i][j] = 1;
    }
}
void bfs(int v)
{
    printf("%d->",v);
    enqueue(v);
    visited[v] = 1;
    int temp;
    while(!empty())
    {
        temp = dequeue();
        for(int i=1;i<=n;i++)
        {
            if(visited[i]==0 && graph[temp][i])
            {
                printf("%d->",i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}
void enqueue(int n)
{
    top+=1;
    q[top] = n;
}
int dequeue()
{
    int temp = q[0];
    for(int i = 0;i<top;i++)
    {
        q[i] = q[i+1];
    }
    top-=1;
    return temp;
}
int empty()
{
    if (top==-1)
        return 1;
    else
        return 0;
}
int main()
{
    int source;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    create_graph();
    printf("Components : %d\n", components());
    for(int i=1;i<=n;i++)
        visited[i] = 0;
    bfs(1);
}