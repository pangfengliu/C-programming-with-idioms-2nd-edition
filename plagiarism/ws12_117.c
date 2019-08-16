#include <stdlib.h>
struct listnode {
       int data;
       struct listnode *next;
       };
typedef struct listnode ListNode;

struct queue {
       ListNode *front;
       ListNode *rear;
       };
typedef struct queue Queue;

void init (Queue *s);
     
int empty (Queue *s);

void enqueue (Queue *s, int data);
     
int dequeue (Queue *s);


#include<stdio.h>
#include"queue.h"
#include <stdlib.h>

void init (Queue *s)
{
     s->front = NULL;
     s->rear = NULL;
     }
     
int empty (Queue *s)
{
    if (s->front == NULL) return 1;
    else return 0;
}

void enqueue (Queue *s, int data)
{
     ListNode *newdata;
     newdata = (ListNode*)malloc(sizeof(ListNode));
     newdata->data = data;
     newdata->next = NULL;
     if (empty (s)) {
         s->front = newdata;
     }
     else {
         s->rear->next = newdata;
     }
     s->rear = newdata;
}
     
int dequeue (Queue *s)
{
    int temp;
    temp = s->front->data;
    ListNode *cur = s->front; 
    s->front = s->front->next;
    if (empty (s)) init (s);
    free(cur);
    return temp;
}
