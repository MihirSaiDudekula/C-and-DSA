//this code still needs debugging
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

struct circularQueue{
    int data;
};

struct circularQueue queue[MAX];
int rear = - 1;
int front = - 1;

int main()

{

    int choice,value;
    while (1)       
    {

        printf("1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Display all elements of queue \n");

        printf("4.Quit \n");

        printf("Enter your choice from the choice no.s : ");

        scanf("%d", &choice);

        int value=10;

        switch (choice)

        {

            case 1:
                printf("\nenter the value to be inserted\n");
                scanf("%d",&value);
                insert(value);
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(1);

            default:
                printf("Wrong choice \n");

        }

    }

}



void insert(int item)

{

    if ((rear+1)%MAX == front)
            printf("Queue Overflow \n");
            return;
            
    if (front == - 1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1)%MAX;
    }
    queue[rear].data = item;

}



void delete()

{
    int value;

    if (front == - 1)
    {

        printf("Queue Underflow \n");

        return -1;

    }
    value = queue[front].data;
    if (front == rear)
    {

        front = rear = -1;
    }

    else

    {

        front = (front + 1)%MAX;

    }
    return value;

}



void display()

{

    int i;

    if (front == - 1)

        printf("Queue is empty \n");

    else

    {
        printf("Front is %d\n",front);
        printf("Queue is : \n");

        for (i = front; i!=rear; i=(i+1)%MAX)
            printf("%d ", queue[i].data);

        printf("\n");
        printf("Rear is %d\n",rear);

    }

}
