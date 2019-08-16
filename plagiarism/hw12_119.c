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



#include<stdio.h>
#include"queue.h"
#include <stdlib.h>
int main ()
{
    Queue curr_road;
    Queue *road = &curr_road;
    int i, j;
    int a, b;
    int k;
    int curr_1, curr_2;
    int map[200][200];
    int distance[100];
    int position;
    
    
    scanf ("%d", &a);
    scanf ("%d", &b);
    
    for (i=0; i< a; i++)
    {
        distance[i]= -1;
        for (j=0; j<a; j++)
        {
            map[i][j]=0;}
    }
    
    for (i=0; i < b; i++)
    {
        scanf ("%d", &curr_1);
        scanf ("%d", &curr_2);
        map[curr_1][curr_2] = 1;
        map[curr_2][curr_1] = 1;
    }
    
    
    distance[0] = 0;
    init(road);
    enqueue (road, 0);
    
    while (!empty(road))
    {
        position = dequeue(road);
        
        for (k=0; k < a; k++)
        {
            if (map[position][k]==1)
            {
                if (distance [k]==-1)
                {
                    distance[k]= distance[position] + 1;
                    enqueue (road, k);
                }
            }
        }
    }
    
    for (i = 1; i < a ; i++)
    {
        if (distance[i] == -1)
            printf ("infinity\n");
        else
            printf ("%d\n", distance [i]);
    }
}
