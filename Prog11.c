#include <stdio.h>
#include <stdlib.h>
int n;
void display(int *heap)
{
    for(int i=0;i<n;i++)
        printf("%d ", heap[i]);
    printf("\n");
}
void top_up(int *h, int n)
{
    int j, key, i;
    for(int k=1;k<=n;k++)
    {
        i = k;
        key = h[k];
        j = (i-1)/2;
        while(i>0 && key<h[j])
        {
            h[i] = h[j];
            i = j;
            j = (i-1)/2;
        }
        h[i] = key;
    }
}
int main()
{
    int *heap = (int*)malloc(sizeof(int)*100);
    printf("Enter number of elements : ");
    scanf("%d", &n);
    for(int i = 0;i<n;i++)
    {
        printf("Enter element : ");
        scanf("%d", &heap[i]);
    }
    display(heap);
    top_up(heap,n-1);
    display(heap);
}