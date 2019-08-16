/* list */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct listnode {
  int data;
  struct listnode *next;
};  
typedef struct listnode ListNode;
/* printLinkedList */
void printLinkedList(ListNode *node)
{
  for (; node != NULL; node = node->next)
    printf("data = %d\n", node->data);
}
/* genNode */
ListNode *genListNode(int data,
		      ListNode *next)
{
  ListNode *node =
    (ListNode *)malloc(sizeof(ListNode));
  assert(node != NULL);
  node->data = data;
  node->next = next;
  return node;
}
/* freeLinkedList */
void freeLinkedList(ListNode *node)
{
  while (node != NULL) {
    ListNode *next = node->next;
    free(node);
    node = next;
  }
}
/* main */
#define ARRAYSIZE 5
int main(void)
{
  int array[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(array[i]));

  ListNode *head;
  ListNode *previous = NULL;
  for (int i = 0; i < ARRAYSIZE; i++) {
    head = genListNode(array[i], previous);
    previous = head;
  }
  printLinkedList(head);
  freeLinkedList(head);
  return 0;
}
/* end */
