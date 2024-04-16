#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int front = -1;
int rear = -1;

int queue[MAX];

void insert(int callid) {
    if (rear == MAX - 1) {
        printf("the queue is full\n");
        return;
    }
    if (rear == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = callid;
}

void remove_item() {
    if (rear == -1) {
        printf("the queue is empty \n");
        return;
    }
    if (front == 0) {
        front = -1;
        rear = -1;
    }
    front++;
}

void display() {
    if (rear == -1) {
        printf("the queue is empty\n");
        return;
    }
    int temp = front;
    while (temp <= rear) {
        printf("%d ", queue[temp]);
        temp++;
    }
    printf("\n");
}

int main() {
    int choice;
    printf("1.Insert\n2.Delete\n3.Display\n4.Quit\n");
    printf("enter your choice of operation: ");
    scanf("%d", &choice);
    while (1) {
        switch (choice) {
            case 1:
                {
                    int id;
                    printf("enter the caller id to be inserted: ");
                    scanf("%d", &id);
                    insert(id);
                    break;
                }
            case 2:
                remove_item();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid input\n");
        }
        printf("enter your choice of operation: ");
        scanf("%d", &choice);
    }
    return 0;
}
