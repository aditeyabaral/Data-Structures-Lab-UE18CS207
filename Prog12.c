#include <stdio.h>
#include <stdlib.h>
int n;
void display(int *heap)
{
    for(int i=0;i<n;i++)
        printf("%d ", heap[i]);
    printf("\n");
}
void bottom_down(int *h, int n)
{
    int j, key, i;
    for(int k=(n-1)/2;k>=0;k--)
    {
        j = k;
        key = h[k];
        i = 2*j+1;
        while(i<=n)
        {
            if((i+1)<=n)
            {
                if(h[i+1]>h[i])
                    i++;
            }
            if(key<h[i])
            {
                h[j] = h[i];
                j = i;
                i = 2*j+1;
            }
            else
                break;
        }
        h[j] = key;
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
    bottom_down(heap,n-1);
    display(heap);
}