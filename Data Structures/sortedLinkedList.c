#include <stdio.h>
#include <stdlib.h>

struct node
{
    char name[10];
    struct node *next ;
};

struct node node;

node *start = NULL;

struct node* getnode(char gname[10])
{
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->name,gname);
    temp->next = NULL;
    return temp;
}

void insert()
{
    printf("enter the name \n");
    scanf("%s",name);
    struct node *nn = getnode(name);
    if(start==NULL)
    {
        start = nn;
    }
    if(strcmp(nn->name,start->name)<0)
    {
        nn->next=start;
        start=nn;
    }
    struct node* temp = start;
    while(temp->next!=NULL && strcmp(nn->name,temp->next->name)>=0)
    {
        temp=temp->next;
    }
    nn->next=temp->next;
    temp->next=nn;
}

void delete()
{
    printf("enter the name \n");
    scanf("%s",name);
    struct node* temp
    if(start==NULL)
    {
        printf("empty \n");
    }
    if(strcmp(name,start->name)==0)
    {
        temp = start;
        start=start->next;
        temp->next =NULL;
        free(temp);
    }
    temp = start;
    while(temp->next!=NULL && strcmp(name,temp->next->name)!=0)
    {
        temp->next=temp->next->next;
    }
    nn->next=temp->next;
    temp->next=nn;
}