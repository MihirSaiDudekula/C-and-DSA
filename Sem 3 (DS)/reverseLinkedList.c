#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node_t;

node_t* reverse_list(node_t *head)
{
    // your code goes here
    node_t *temp = head;
    node_t *prev = NULL; 
    node_t *ahead = NULL;
    while(temp!=NULL)
      {
        ahead = temp->next;
        temp->next=prev;
        prev=temp;
        temp=ahead;        
      }
    head = prev;
  
    return head;
}

// A utility function to create a new node
node_t* new_node(int key)
{
    node_t* temp = (node_t*)malloc(sizeof(node_t));
    temp->data = key;
    temp->next = NULL;
    return temp;
}

void print(node_t *head)
{
    node_t *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int n = 10;
    node_t *head = new_node(0);
    node_t *temp = head;
    for (int i = 1; i < 10; i++)
    {
        (temp)->next = new_node(i);
        (temp)=(temp)->next;
    }

    print(head);

    node_t *r_head = reverse_list(head);

    print(r_head);

    return 0;
}

