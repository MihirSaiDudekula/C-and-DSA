#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;
struct node* tail = NULL;

struct node* getNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}


void insert(int data,int key)
{
    if(head==NULL)
    {
        head=getNode(data);
        return;
    }
    else
    {
        struct node* cur = head;
        while(cur!=NULL && cur->data!=key)
        {
            cur=cur->next;
        }
        if(cur==NULL)
        {
            //not found
        }
        else
        {
            struct node* nn = getNode(data);
            nn->prev=cur->prev;
            cur->prev=nn;
            nn->next=cur;
            if(cur->prev!=NULL)
            {
                nn->prev->next=nn;
            }
            else
            {
                head = nn;
            }
        }
    }

}

void delete(int data)
{
    struct node* temp = head;
    struct node* bef = NULL;
    struct node* aft = NULL;

    while(temp!=NULL && temp->data!=data)
    {
        bef=temp;
        temp=temp->next;
    }
    if(temp=NULL)
    {
        //not found
        return;
    }
    aft = temp->next;

    if(bef=NULL)
    {
        head = aft;
    }
    else
    {
        bef->next=aft; 
    }
    if(aft!=NULL)
    {
        aft->prev=bef;
    }
    free(temp);
}

void display()
{
    struct node* ptr =head;
    if(head==NULL)
    {
        //
    }
    printf("list:\n");
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    int choice;
    int value;
    int key=-1;
    while(1)
    {
        printf("\n1.insert\n2.delete\n3.display\n4.exit");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("enter the value");
            scanf("%d",&value);
            printf("enter the key");
            scanf("%d",&key);
            insert(value,key);
            break;
        case 2:
            printf("enter the value");
            scanf("%d",&value);
            delete(value);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("invalid");
        }
    }   
}