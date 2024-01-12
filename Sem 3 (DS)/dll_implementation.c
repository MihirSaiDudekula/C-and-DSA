#include <stdio.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *getnode()
{
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr; 
}

void insert_at_start(struct node *n1,struct node *head)
{
    struct node *nn=getnode();
    nn->next=n1;
    n1->prev=nn;
    head=nn;
    glistlength++;
}

void insert_at_end(struct node *n2,struct node *tail)
{
    struct node *nn=getnode();
    nn->prev=n2;
    n2->next=nn;
    tail=nn;
    glistlength++;
}

void insert_at_p(struct node *n1,struct node *n2)
{
    struct node *nn=getnode();
    nn->next=n2;
    nn->prev=n1;
    n1->next=nn;
    n2->prev=nn;
    glistlength++;
}
