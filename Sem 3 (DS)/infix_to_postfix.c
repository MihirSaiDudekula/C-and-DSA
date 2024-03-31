#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[20];
int top = -1;

int priority(char e)
{
    if (e == '*' || e == '/')
    {
        return 2;
    }
    else if (e == '+' || e == '-') // Corrected condition
    {
        return 1;
    }
    else if (e == '(')
    {
        return 0;
    }
    return -1;
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int main()
{
    char postfix[20];
    int index = 0;
    char x;
    char exp[20];
    printf("enter the expression");
    scanf("%s", exp);
    char *e = exp;
    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            postfix[index++] = *e;
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while (stack[top] != '(' && top >= 0)
            {
                x = pop();
                postfix[index++] = x;
            }
            if (top >= 0 && stack[top] == '(')
            {
                pop(); // Pop the '(' from the stack
            }
            else
            {
                printf("Error: Unbalanced parentheses\n");
                return 1; // Exit the program due to error
            }
        }
        else
        {
            while (top >= 0 && priority(*e) <= priority(stack[top]))
            {
                x = pop();
                postfix[index++] = x;
            }
            push(*e);
        }
        e++;
    }
    while (top >= 0)
    {
        x = pop();
        postfix[index++] = x;
    }
    postfix[index] = '\0'; // Add null terminator to the postfix string
    printf("\n%s\n", postfix);

    return 0;
}
