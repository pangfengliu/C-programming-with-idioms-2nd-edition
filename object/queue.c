#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void init(Queue *q)
{
  q->rear = q->front = NULL;
}

int empty(Queue *q)
{
  return(q->front == NULL);
}

void enqueue(Queue *q, int data)
{
  ListNode *incoming = (ListNode *)malloc(sizeof(ListNode));
  assert(incoming != NULL);

  incoming->data = data;
  incoming->next = NULL;
  if (q->rear == NULL) 
    q->front = q->rear = incoming;
  else {
    q->rear->next = incoming;
    q->rear = incoming;
  }
  return;
}

int dequeue(Queue *q)
{
  int v;
  ListNode *to_be_removed;

  assert(!empty(q));
  v = q->front->data;
  to_be_removed = q->front;
  if (q->front == q->rear) 
    q->front = q->rear = NULL;
  else 
    q->front = to_be_removed->next;
  free(to_be_removed);    
  return v;
}

