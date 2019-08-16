#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.h"

void printListBackward(ListNode *ptr);

int main(void)
{
  int n;
  ListNode *head;
  ListNode *previous = NULL;

  while (scanf("%d", &n) != EOF) {
    head = (ListNode *)malloc(sizeof(ListNode));
    assert(head != NULL);
    head->data = n;
    head->next = previous;
    previous = head;
  }
  printListBackward(head);
  return 0;
}
