#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int stack[10];
int top = -1;

void push(int e)
{
	stack[++top]=e;
}

int pop()
{
	return stack[top--];
}

int main()
{
	char exp[20];
	printf("enter the expression");
	scanf("%s",exp);
	char *e = exp;
	while(*e!='\0')
	{
		if(isalnum(*e))
		{
			
		}
		e++;
	}
}

