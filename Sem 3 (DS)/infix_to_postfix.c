#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char stack[100];
int top = -1;

int priority(char x)
{
 if(x=='(')
 {
    return 0;
 }
 else if(x=='+'||x=='-') 
 {
    return 1;
 }
 else if(x=='*'||x=='/')
 {
    return 2;
 }
 return -1;
}

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

void main()
{
    char infix[] = "(a+b)*c/d";
    char postfix[100];
    char *e;
    char x;
    int index=0;
    e=infix;

    while(*e!='\0')
    {
        if(*e=='(')
        {
            push(*e);
        }
        else if(isalnum(*e))
        {
            postfix[index++]=*e;
        }
        else if(*e == ')')
        {
            while(stack[top]!='(')
            {
                x=pop();
                postfix[index++]=x;
            }
        }
        else
        {
            //operator
            while(priority(stack[top])>=priority(*e))
            {
                x=pop();
                postfix[index++]=x;
            }
            push(*e);
        }
        e++;
    }
    while(top>=0)
    {
        if(stack[top]=='(' || stack[top]==')')
        {
            x=pop();
        }
        else
        {
            x=pop();
            postfix[index++]=x;
        }
    }
    postfix[index] = '\0';
    printf("Postfix expression: %s\n", postfix);
}

