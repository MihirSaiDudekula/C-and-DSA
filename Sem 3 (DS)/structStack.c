#include <stdio.h>
#define MAX 5
struct stack 
{
	int stack[MAX];
	int top;
};

struct stack s;
void initialise()
{
	s.top=-1;
}

void push()
{
        if(s.top<MAX)
        {
                int ele;
                printf("\nenter the element to be pushed\n");
                scanf("%d",&ele);
                s.top++;
                s.stack[s.top]=ele;

        }
        else
        {
                printf("\nstack overflow\n");
        }
}
void pop()
{
        if(s.top>=0)
        {
                int ele;
                s.stack[s.top]=ele;
                printf("\nthe popped element is %d\n",ele);
                s.top--;

        }
        else
        {
                printf("\nstack underflow\n");
        }
}
void display()
{
        printf("\nthe elements of the stack are\n");
        for(int i=0;i<=s.top;i++)
        {
                printf("\n%d\n",s.stack[i]);
 }

}

void main()
{
		initialise();
        int choice;
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
                                display();
                                break;
                        default:
                                exit(0);
                                break;
}

        }
    }


#include <stdio.h>
#define MAX 5
struct stack 
{
	int stack[MAX];
	int top;
};



void push(struct stack *s)
{
        if(s->top<MAX)
        {
                int ele;
                printf("\nenter the element to be pushed\n");
                scanf("%d",&ele);
                s->top++;
                s->stack[s->top]=ele;

        }
        else
        {
                printf("\nstack overflow\n");
        }
}
void pop(struct stack *s)
{
        if(s->top>=0)
        {
                int ele;
                s->stack[s->top]=ele;
                printf("\nthe popped element is %d\n",ele);
                s->top--;

        }
        else
        {
                printf("\nstack underflow\n");
        }
}
void display(struct stack *s)
{
        printf("\nthe elements of the stack are\n");
        for(int i=0;i<=s->top;i++)
        {
                printf("\n%d\n",s->stack[i]);
 }

}

void initialise(struct stack *s)
{
	s->top=-1;
}


void main()
{
		struct stack s;

		initialise(&s);
        int choice;
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
                                push(&s);
                                break;
                        case 2:
                                pop(&s);
                                break;
                        case 3:
                                display(&s);
                                break;
                        default:
                                exit(0);
                                break;
}

        }
    }