#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node {
  int data;
  struct node *next;
} Node;
/* printList */
void printList(Node *node)
{
  for (; node != NULL; node = node->next)
    printf("%d\n", node->data);
}
/* genNode */
Node *genNode(int data, Node *next)
{
  Node *node = (Node *)malloc(sizeof(Node));
  assert(node != NULL);
  node->data = data;
  node->next = next;
  return node;
}
/* findNext */
int findNext(Node *lists[], int index, int n,
	     int adj)
{
  while (index >= 0 && index < n) {
    if (lists[index] != NULL)
      return index;
    index += adj;
  }
  return -1;
}
/* merge */
Node *merge(Node *lists[], int n)
{
  int last = 0;
  Node *lastPtr = NULL, *head = NULL;
  int adj = 1;            /* foreward */
  int current;
 
  while ((current = findNext(lists, last, n,
			     adj)) != -1) {
    if (lastPtr == NULL) 
      head = lists[current];
    else
      lastPtr->next = lists[current];
    int next;
    while ((next = findNext(lists, current+adj,
			    n, adj)) != -1) {
      Node *currentPtr = lists[current];
      lists[current] = currentPtr->next;
      currentPtr->next = lists[next];
      current = next;
    }
    last = current;
    lastPtr = lists[current];
    lists[current] = lastPtr->next;
    adj = -adj;
  }
  return head;
}
/* main */
int main()
{
  int k;
  scanf("%d", &k);
  Node *list[k], *previous;
  
  for (int i = 0; i < k; i++) {
    previous = NULL;
    list[i] = NULL;
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; j++) {
      int data;
      scanf("%d", &data);
      list[i] = genNode(data, previous);
      previous = list[i];
    }
  }
  Node *result = merge(list, k);
  printList(result);
  return 0;
}
