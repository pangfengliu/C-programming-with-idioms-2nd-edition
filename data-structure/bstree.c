/* tree */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct treenode {
  int data;
  struct treenode *left;
  struct treenode *right;
};
typedef struct treenode TreeNode;
/* genNode */
TreeNode *genTreeNode(int data, TreeNode *left,
		      TreeNode *right)
{
  TreeNode *node = malloc(sizeof(TreeNode));
  assert(node != NULL);
  node->data = data;
  node->left = left;
  node->right = right;
  return node;
}
/* print */
void printBsTree(TreeNode *root)
{
  if (root == NULL)
    return;
  printBsTree(root->left);
  printf("data = %d\n", root->data);
  printBsTree(root->right);
}
/* insert */
TreeNode *insertBsTree(TreeNode *root, int data)
{
  struct treenode *current;
  if (root == NULL) 
    return genTreeNode(data, NULL, NULL);

  if (data < root->data) 
    root->left = insertBsTree(root->left,data);
  else 
    root->right =insertBsTree(root->right,data);
  return(root);
}
/* free */
void freeTree(TreeNode *root)
{
  if (root == NULL)
    return;
  else {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
  }
}
/* main */
#define KEYS 5
int main(void)
{
  int insertKeys[KEYS];
  for (int i = 0; i < KEYS; i++)
    scanf("%d", &(insertKeys[i]));

  TreeNode *root = NULL;
  for (int i = 0; i < KEYS; i++)
    root = insertBsTree(root, insertKeys[i]);
  printBsTree(root);

  freeTree(root);
  return 0;
}
/* end */
