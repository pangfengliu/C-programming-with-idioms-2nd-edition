#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
 
Node *genNode(int value, Node *left, Node *right)
{
  Node *ptr = malloc(sizeof(Node));
  ptr->value = value;
  ptr->left = left;
  ptr->right = right;
  return ptr;
}

Node *treeAND(Node *root1, Node *root2)
{
  if (root1 != NULL && root2 != NULL)
    return genNode(root1->value * root2->value,
		   treeAND(root1->left, root2->left),
		   treeAND(root1->right, root2->right));
  return NULL;
}
 
Node *treeOR(Node *root1, Node *root2)
{
  if (root1 != NULL && root2 != NULL)
    return genNode(root1->value + root2->value,
		   treeOR(root1->left, root2->left),
		   treeOR(root1->right, root2->right));
  if (root1 != NULL)
    return root1;
  else if (root2 != NULL)
    return root2;
  
  return NULL;
}
