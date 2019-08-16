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

void init(Queue *s);
int empty(Queue *s);
void enqueue(Queue *s, int data);
int dequeue(Queue *s);

