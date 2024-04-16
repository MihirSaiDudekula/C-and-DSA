#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *getNode(int data)
{
    struct node* node = (struct node *) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

void InorderTraversal(struct node* node)
{
  //   if (node==NULL){
  //     return;
  //   }
  //   else
  //   {
  //     InorderTraversal(node->left);
  //     printf("%d ", node->data);
  //     InorderTraversal(node->right);      
  //   }
  // return;
  if(node->left!=NULL && node->right==NULL)
  {
    InorderTraversal(node->left);
    // printf("%d ", node->data);    
  }
  else if(node->left==NULL && node->right!=NULL)
  {
    printf("%d ", node->data);
    InorderTraversal(node->right);
  }    
  
  else if(node->left!=NULL && node->right!=NULL)
  {
    printf("%d ", node->data);
  }
  else
  {
    printf("%d ", node->data);
    // InorderTraversal(node->left);
    return;
  }
  return;
}

// Driver code
int main()
{
  struct node* ptr = getNode(1);
  ptr->left = getNode(2);
  ptr->right = getNode(3);
  ptr->left->left = getNode(4);
  ptr->left->right = getNode(5);
  InorderTraversal(ptr);
  return 0;
}
