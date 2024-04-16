#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node_t *getnode(int data)
{
    struct node* ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data = data;
    ptr->prev=NULL;
    ptr->next=NULL;
    return ptr; 
}

struct node_t* root =NULL
struct node_t* temp = root;

struct node_t* insert(struct node_t* temp,int data)
{
	if(temp = NULL)
	{
		return getnode(data);
	}
	if(key<root->data)
	{
		temp->left = insert(temp->left,data);
	}
	if(key>=root->data)
	{
		temp->right = insert(temp->right,data);
	}
}



void preorder(struct node_t* temp)
{
	if(temp == NULL)
		{return}
	print(temp->data)
	preorder(temp->left);
	preorder(temp->right);
	return;
}