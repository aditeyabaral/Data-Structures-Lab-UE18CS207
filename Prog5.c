#include <stdio.h>
#include <stdlib.h>
char stack[100];
int top = -1;
void push(char c)
{
    top+=1;
    stack[top] = c;
}
char pop()
{
    char x = stack[top];
    top-=1;
    return x;
}
int inputprecedence(char s)
{
    switch(s)
    {
        case '+':return 1;
        case '-':return 1;
        case '*':return 3;
        case '/':return 3;
        case '(': return 9;
        case ')':return 0;
        default: return 7;
    }
}
int stackprecedence(char s)
{
    switch(s)
    {
        case '+':return 2;
        case '-':return 2;
        case '*':return 6;
        case '/':return 6;
        case '#':return -1;
        case '(': return 0;
        default: return 8;
    }
}
void convert(char* infix, char*postfix)
{
    int i=0,ctr=0;
    push('#');
    while(infix[i])
    {
        while(stackprecedence(stack[top])>inputprecedence(infix[i]))
        {
            postfix[ctr] = pop();
            ctr++;
        }
        if(stackprecedence(stack[top])<inputprecedence(infix[i]))
            push(infix[i]);
        else
            pop();
        i++;
    }
    while(top!=-1)
    {
        postfix[ctr] = pop();
        ctr++;
    }
    postfix[ctr-1] = '\0';
}
int fibo(int n)
{
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    else
        return fibo(n-1)+fibo(n-2);
}
int main()
{
    char infix[100],postfix[100];
    printf("Enter infix : ");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("%s\n",postfix);
    printf("Enter n : ");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        printf("%d ", fibo(i));
}
