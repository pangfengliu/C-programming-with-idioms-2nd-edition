#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* listnode */
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
/* insert */
ListNode *insertLinkedList(ListNode *head, 
			   int data)
{
  ListNode *current = genListNode(data, NULL);
  if (head == NULL) 
    return(current);

  ListNode *ptr = head;
  ListNode *last = NULL;
  while (ptr != NULL && ptr->data < data) {
    last = ptr;
    ptr = ptr->next;
  }
  if (last == NULL) {
    current->next = head;
    return(current);
  } else {
    current->next = last->next;
    last->next = current;
    return(head);
  }
}
/* main */
#define ARRAYSIZE 5
int main(void)
{
  int array[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    scanf("%d", &(array[i]));

  ListNode *head = NULL;
  for (int i = 0; i < ARRAYSIZE; i++)
    head = insertLinkedList(head, array[i]);

  printLinkedList(head);
  freeLinkedList(head);
  return 0;
}
/* end */
