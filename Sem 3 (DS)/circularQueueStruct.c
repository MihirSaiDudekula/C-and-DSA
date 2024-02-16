#include <stdio.h>
#include <stdlib.h>

#define MAX 7

struct queue {
	int value;
};

struct queue circularQueue[MAX];
int front = -1;
int rear = -1;

void insert(int value)
{
	//full condition
	if(front==0 && rear == MAX-1 || ((rear%MAX)+1)==front)
	{
		printf("the queue is full\n");
		return;
	}
	// empty condition
	if(rear == -1)
	{
		front = 0;
	}
	rear++;
	rear=rear%MAX;
	circularQueue[rear].data = value;
}
void remove()
{
	if (rear == -1) {
	    printf("the queue is empty \n");
	    return;
	}
	if(front == 0)
	{
		front = -1;
		rear = -1;
	}
	front++;
	front=front%MAX;
}
void display()
{
	for(int i=front;i!=rear;i=((i++)%MAX))
	{
		printf("%d",circularQueue[i].data)
	}
}

void main()
{}

