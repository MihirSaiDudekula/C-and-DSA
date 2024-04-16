#include <stdio.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *getnode(int data)
{
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr; 
}

struct node* start = NULL;

void insert(int choice)
{
    int data =10;
    struct node* nn = getnode(data);
    if(start==NULL)
    {
        start = nn;
    }
    if(choice == 1)
    {
        start->prev=nn;
        nn->next=start;
        start=nn;
    }
}
void delete()
