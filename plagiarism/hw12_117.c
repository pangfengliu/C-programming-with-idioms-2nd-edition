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


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


main ()
{
     int n, m, i, p1, p2, j, city, l;
     int map[101][101];
     int ans[100];
     Queue roads;
     Queue *r = &roads;
     
     scanf ("%d", &n);
     scanf ("%d", &m);
     for (i=0; i<n; i++)
     {
         ans[i]=-1;
         for (j=0; j<n; j++){
             map[i][j]=0;}
             }
     for (i=0; i<m; i++)
     {
         scanf ("%d", &p1);
         scanf ("%d", &p2);
         map[p1][p2]=1;
         map[p2][p1]=1;
         }
         ans[0]=0;
         enqueue (r, 0);
         while (!empty(r))
         {
               city=dequeue(r);
               for (l=0; l<n; l++)
               {
                   if (map[city][l]==1) 
                   {
                         if (ans [l]==-1){
                         ans[l]=ans[city]+1;
                         enqueue (r, l);}
                         }
                   }
               }
                                       
         for (i=1; i<n; i++)
         {
             if (ans[i]==-1) printf ("infinity\n");
             else printf ("%d\n", ans [i]);
             }
     }
