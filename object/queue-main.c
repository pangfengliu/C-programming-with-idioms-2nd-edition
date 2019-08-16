#include <stdio.h>
#include "queue.h"

int main(void)
{
  Queue queue;
  Queue *q = &queue;

  init(q);
  if (empty(q))
    printf("initially queue is empty\n");

  enqueue(q, 2);
  enqueue(q, 3);
  printf("%d\n", dequeue(q));
  enqueue(q, 4);
  printf("%d\n", dequeue(q));
  printf("%d\n", dequeue(q));
  enqueue(q, 5);
  enqueue(q, 6);
  printf("%d\n", dequeue(q));
  printf("%d\n", dequeue(q));
  return 0;
}
