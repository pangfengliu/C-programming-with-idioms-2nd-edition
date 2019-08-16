#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct treenode {
  char data;
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
/* postorder */
void postorder(TreeNode *root)
{
  if (root == NULL)
    return;
  postorder(root->left);
  postorder(root->right);
  printf("%c", root->data);
}
/* reconstruct */
TreeNode *reconstruct(int n, char pre[],
		      char in[])
{
  if (n == 0)
    return NULL;

  int leftn = strchr(in, pre[0]) - in;
  int rightn = n - leftn - 1;
  return
    genTreeNode(pre[0], 
		reconstruct(leftn, pre + 1, in),
		reconstruct(rightn,
			    pre + 1 + leftn, 
			    in + leftn + 1));
}
/* freeTree */
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
#define N 80
int main(void)
{
  char preorder[N], inorder[N];
  scanf("%s%s", preorder, inorder);

  int length = strlen(preorder);
  assert(length == strlen(inorder) &&
	 length < N);

  TreeNode *root =
    reconstruct(length, preorder, inorder);
  postorder(root);

  freeTree(root);
  return 0;
}
/* end */
