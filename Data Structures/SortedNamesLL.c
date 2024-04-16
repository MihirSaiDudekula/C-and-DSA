#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
  char name[50];
   struct node *next;
};

struct node *head = NULL;

void insert(char *name)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  strcpy(newNode->name, name);
  newNode->next = NULL;
  if (head == NULL || strcmp(head->name, name) >= 0)
  {
    newNode->next = head;
    head = newNode;
  }
  else
  {
    struct node *current = head;
    while(current->next != NULL && strcmp(current->next->name, name) < 0)
      {
        current=current->next;
      }
      newNode->next=current->next;
      current->next=newNode;
      
  }
}

void delete(char *name)
{
  struct node *temp = head;
  struct node *prev;
  if (temp != NULL && strcmp(temp->name, name) == 0){
    head = temp->next;
    free(temp);
    return;
  }
  while (temp!=NULL && strcmp(temp->name, name) != 0)
    {
      prev=temp;
      temp=temp->next;
    }
  if(temp==NULL)
  {
    printf("\nName not found\n");
    return;
  }
  prev->next = temp->next;
  free(temp);
  
}
void display()
{
  struct node *ptr = head;
  printf("\n Names in the list \n");
  while(ptr != NULL)
  {
    printf("\n%s\n",ptr->name);
    ptr=ptr->next;
  }
  
}

int main() {
  int choice=0;
  char name[50];
  while(1)
    {
      printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
      scanf( "%d", &choice);
      switch(choice)
      {
        case 1:
          printf("\nEnter the name to be inserted: ");
          scanf("%s",name);
          insert(name);
          break;
        case 2:
          printf("\nEnter the name to be deleted: ");
          scanf("%s",name);
          delete(name);
          break;
        case 3:
          display();
          break;
        case 4:
          exit(1);
        default:
          printf("\nInvalid choice\n");
      }
    }
  return 0;
}
