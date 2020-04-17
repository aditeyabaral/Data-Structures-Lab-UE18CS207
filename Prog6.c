#include <stdio.h>
#include <stdlib.h>
int stack[100];
int top = -1;
void push(int val)
{
    top+=1;
    stack[top]=val;
}
int pop()
{
    int c = stack[top];
    top--;
    return c;
}
int eval(char *s)
{
    int i = 0;
    char c,op1,op2;
    int ans;
    while(s[i])
    {
        c = s[i];
        if (c=='+' || c=='-' || c=='/' || c=='*')
        {
            op1 = pop();
            op2 = pop();
            switch(c)
            {
                case '+': 
                {
                    ans = op1+op2;
                    break;
                }
                case '-': 
                {
                    ans = op1-op2;
                    break;
                }
                case '*': 
                {
                    ans = op1*op2;
                    break;
                }
                case '/': 
                {
                    ans = op1/op2;
                    break;
                }
            }
            push(ans);
        }
        else
            push(c-48);
        i++;
    }
    return pop();
}
void hanoi(int n, char A, char C, char B)
{
    if(n==1)
    {
        printf("%d from %c to %c\n",n,A,C);
        return;
    }
    hanoi(n-1,A,B,C);
    printf("%d from %c to %c\n",n,A,C);
    hanoi(n-1,B,C,A);
}
int main()
{
    printf("Enter postfix : ");
    char postfix[20];
    scanf("%s",postfix);
    int val = eval(postfix);
    printf("Value = %d\n",val);
    int n;
    printf("Enter n : ");
    scanf("%d",&n);
    hanoi(n,'A','C','B');
}