#include <stdio.h>
#include "linked-list.h"

void printListBackward(ListNode *ptr)
{
  if (ptr != NULL) {
    printListBackward(ptr->next);
    printf("%d\n", ptr->data);
  }
  return;
}

