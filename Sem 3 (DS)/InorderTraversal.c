#include <stdio.h>
#include <stdlib.h>

struct tree {
    int data;
    struct tree* left;
    struct tree* right;
};

// Function to create a new node
struct tree* getNode(int value) {
    struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
    nn->data = value;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

void inot(struct tree *root)
{
  if(root == NULL)
  {
    return;
  }
  inot(root->left);
  printf("%d\n",root->data);
  inot(root->right);
  return;
}

int main() {
    // Creating nodes for the tree
    struct tree* root = getNode(5);
    root->left = getNode(3);
    root->right = getNode(8);
    root->left->left = getNode(1);
    root->left->right = getNode(4);
    root->right->left = getNode(7);
    root->right->right = getNode(9);
    inot(root);

    // Tree construction
    /*
               5
             /   \
            3     8
           / \   / \
          1   4 7   9
    */

    return 0;
}

//1 3 4 5 7 8 9 