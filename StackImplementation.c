#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int stack[MAX];
int top,x;

void push();
void pop();
void palin();
void display();


void main()
{
        int choice;
        top=-1;
        while(1)
        {
                printf("enter your choice of operation");
                printf("\n1.push\n");
                printf("\n2.pop\n");
                printf("\n3.palindrome check\n");
                printf("\n4.display stack\n");
                printf("\nenter your choice\n");
                scanf("%d",&choice);

                switch(choice)
                {
                        case 1:
                                push();
                                break;
                        case 2:
                                pop();
                                break;
                        case 3:
                                palin();
                                break;
                        case 4:
                                display();
                                break;
                        default:
                                exit(0);
                                break;
}

        }

}
void push()
{
        if(top<MAX)
        {
                int ele;
                printf("\nenter the element to be pushed\n");
                scanf("%d",&ele);
                top++;
                stack[top]=ele;

        }
        else
        {
                printf("\nstack overflow\n");
        }
}
void pop()
{
        if(top>=0)
        {
                int ele;
                stack[top]=ele;
                printf("\nthe popped element is %d\n",ele);
                top--;

        }
        else
        {
                printf("\nstack underflow\n");
        }
}
void display()
{
        printf("\nthe elements of the stack are\n");
        for(int i=0;i<=top;i++)
        {
                printf("\n%d\n",stack[i]);
 }

}
void palin()
{
        int palinstack[MAX];
        int temptop=top;
        for (int i=0;i<=MAX;i++)
        {
                palinstack[i]=stack[temptop];
                temptop--;
        }
        for (int i=0;i<=MAX;i++)
        {
                if(palinstack[i]!=stack[i])
                {
                        printf("\nnot palindrome\n");
                        break;
                }

        }
        printf("\npalindrome\n");


}
