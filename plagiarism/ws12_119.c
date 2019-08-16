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
    if (s->front == NULL)
        return 1;
    else
        return 0;
}

void enqueue (Queue *s, int data)
{
    ListNode *i;
    i = (ListNode*) malloc(sizeof(ListNode));
    i -> data = data;
    i -> next = NULL;
    
    if (empty (s))
    {
        s->front = i;
    }
    else
    {
        s->rear->next = i;
    }
    s->rear = i;
}

int dequeue (Queue *s)
{
    int n;
   
    n = s->front->data;
    
    ListNode *position = s->front;
    s->front = s->front->next;
    
    if (empty (s)) init (s);
    free(position);
    
    return n;
}
