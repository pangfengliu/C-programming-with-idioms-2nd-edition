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
/* inorder */
void inorderBsTree(TreeNode *root)
{
  if (root == NULL)
    return;
  inorderBsTree(root->left);
  printf("data = %d\n", root->data);
  inorderBsTree(root->right);
  return;
}
/* preorder */
void preorderBsTree(TreeNode *root)
{
  if (root == NULL)
    return;
  printf("data = %d\n", root->data);
  preorderBsTree(root->left);
  preorderBsTree(root->right);
  return;
}
/* postorder */
void postorderBsTree(TreeNode *root)
{
  if (root == NULL)
    return;
  postorderBsTree(root->left);
  postorderBsTree(root->right);
  printf("data = %d\n", root->data);
  return;
}
/* insert */
TreeNode *insertBsTree(TreeNode *root, int data)
{
  struct treenode *current;
  if (root == NULL)
    return genTreeNode(data, NULL, NULL);

  if (data < root->data) 
    root->left = insertBsTree(root->left, data);
  else 
    root->right =
      insertBsTree(root->right, data);
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

  printf("inorder\n");
  inorderBsTree(root);
  printf("preorder\n");
  preorderBsTree(root);
  printf("postorder\n");
  postorderBsTree(root);

  freeTree(root);
  return 0;
}
/* end */
