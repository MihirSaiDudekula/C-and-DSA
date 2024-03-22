#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char ele)
{
    if(top>99)
    {
        return;
    }
    top++;
    stack[top]=ele;
}

char pop()
{
    if(top>=0)
    {
        char temp = stack[top];
        top--;
        return temp; 
    }

}

int main()
{
    char postfix[] = "75-63/*";
    char *e;
    int res=0;
    int a;
    int b;
    e=postfix;

    while(*e!='\0')
    {
        if(isalnum(*e))
        {
            int temp = *e-48;
            push(temp);
        }
        else
        {
            //operator
            a=pop();
            b=pop();
            if(*e=='+')
            {
               push(b+a);
            }
            else if(*e=='-') 
            {
               push(b-a);
            }
            else if(*e=='*')
            {
               push(b*a);
            }
            else if(*e=='/')
            {
               push(b/a);
            }
        }
        e++;
    }
    res = pop();
    printf("Postfix expression: %d\n",res);
}

