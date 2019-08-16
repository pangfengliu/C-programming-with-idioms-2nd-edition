#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
/* list */
struct listnode {
  int data;
  struct listnode *next;
};
typedef struct listnode ListNode;  
/* printLinkedList */
void printLinkedList(ListNode *node)
{
  if (node == NULL) {
    printf("\n");
    return;
  }
  printf("data = %d\n", node->data);
  printLinkedList(node->next);
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
/* insert */
ListNode *insertLinkedList(ListNode *head, 
			   int data)
{
  if (head == NULL || data < head->data) 
    return(genListNode(data, head));

  head->next = 
    insertLinkedList(head->next, data);
  return(head);
}
/* delete */
ListNode *deleteLinkedList(ListNode *head, 
			   int data)
{
  ListNode *temp;
  if (head == NULL)
    return NULL;
  if (data == head->data) {
    temp = head->next;
    free(head);
    return(temp);
  }
  head->next = 
    deleteLinkedList(head->next, data);
  return(head);
}
/* freeLinkedList */
void freeLinkedList(ListNode *node)
{
  if (node == NULL)
    return;
  freeLinkedList(node->next);
  free(node);
}
/* main */
#define INSKEY 5
#define DELKEY 3
int main(void)
{
  int insertKeys[INSKEY];
  int deleteKeys[DELKEY];
  for (int i = 0; i < INSKEY; i++)
    scanf("%d", &(insertKeys[i]));
  for (int i = 0; i < DELKEY; i++)
    scanf("%d", &(deleteKeys[i]));
  
  ListNode *head = NULL;
  for (int i = 0; i < INSKEY; i++)
    head = 
      insertLinkedList(head, insertKeys[i]);
  printLinkedList(head);
  
  for (int i = 0; i < DELKEY; i++)
    head = 
      deleteLinkedList(head, deleteKeys[i]);

  printLinkedList(head);
  freeLinkedList(head);
  return 0;
}
/* end */
