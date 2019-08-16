#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
 
void preorder(Node *root)
{
  if (root == NULL) return;
  printf("%d ", root->value);
  preorder(root->left);
  preorder(root->right);
}
 
void inorder(Node *root)
{
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ", root->value);
  inorder(root->right);
}

Node *insertBST(Node *root, int value)
{
  if (root == NULL) 
    return (genNode(value, NULL, NULL));

  if (value < root->value)
    root->left = insertBST(root->left, value);
  else
    root->right = insertBST(root->right, value);
  return root;
}
 
int main()
{
  Node *tree[2] = {NULL, NULL};
  for (int t = 0; t < 2; t++) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      int value;
      scanf("%d", &value);
      tree[t] = insertBST(tree[t], value);
    }
  }

  Node *result = treeAND(tree[0], tree[1]);
  preorder(result);
  printf("\n");
  inorder(result);
  printf("\n");

  result = treeOR(tree[0], tree[1]);
  preorder(result);
  printf("\n");
  inorder(result);
  printf("\n");

  return 0;
}
