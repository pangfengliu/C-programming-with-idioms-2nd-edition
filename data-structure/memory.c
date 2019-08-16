#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
/* freeBlock */
typedef struct freeBlock {
  int start;
  int length;
  struct freeBlock *next;
} FreeBlock;
/* getFreeBlock */
FreeBlock *getFreeBlock(int start, int length,
			FreeBlock *next)
{
  FreeBlock *block =
    (FreeBlock *)malloc(sizeof(FreeBlock));
  block->start = start;
  block->length = length;
  block->next = next;
  return block;
}
/* initMemory */
void initMemory(FreeBlock **head, int length)
{
  assert(length > 0);
  *head = getFreeBlock(0, length, NULL); 
}
/* allocateMemory */
void allocateMemory(FreeBlock **head, int start,
		    int length)
{
  FreeBlock *current = *head;
  FreeBlock *before = NULL;
  assert(current != NULL);
  while (!((start >= current->start) && 
    (start < current->start + current->length)))
    {
      before = current;
      current = current->next;
      assert(current != NULL);
    }
  /* same */
  int beginSame = (start == current->start);
  int endSame =
    (start + length ==
     current->start + current->length);
  if (beginSame && endSame) {
    if (before == NULL) {
      assert(current == *head);
      *head = current->next;
    } else 
      before->next = current->next;
    free(current);
  } else if (beginSame) {
    current->start += length;
    current->length -= length;
  } else if (endSame) {
    current->length -= length;
  } else {
    FreeBlock *after = 
      getFreeBlock(start + length, 
	 (current->start + current->length) -
	 (start + length), current->next); 
      current->next = after;
      current->length = start - current->start;
  }
}
/* freeMemory */
void freeMemory(FreeBlock **head, int start,
		int length)
{
  FreeBlock *current = *head;
  FreeBlock *before = NULL;
  while ((current != NULL) &&
	 (start > current->start)) {
    before = current;
    current = current->next;
  }
  bool adjacentBefore = (before != NULL) && 
    (start == before->start + before->length);
  assert(!((before != NULL) &&
	   before->start + before->length > start));
  bool adjacentCurrent = (current != NULL) && 
    (start + length == current->start);
  assert(!((current != NULL) &&
	   (start + length > current->start)));
  
  /* adjacent */
  if (adjacentBefore && adjacentCurrent) {
    before->length +=(length + current->length);
    before->next = current->next;
    free(current);
  } else if (adjacentBefore) 
    before->length += length;
  else if (adjacentCurrent) {
    current->length += length;
    current->start -= length;
  } else {
    FreeBlock *between =
      getFreeBlock(start, length, current);
    if (before == NULL) 
      *head = between; 
    else
      before->next = between;
  }
}
/* print */
void printMemory(FreeBlock *head)
{
  FreeBlock *ptr = head;
  printf("==========\n");
  while (ptr != NULL) {
    printf("start %d, length %d\n", ptr->start,
	   ptr->length);
    ptr = ptr->next;
  }
}
/* main */
#define N 100
int main()
{
  FreeBlock *head = NULL;
  int memorySize;
  scanf("%d", &memorySize);
  initMemory(&head, memorySize);
  printMemory(head);
  int n;
  scanf("%d", &n);
  int start[N], size[N];
  for (int i = 0; i < n; i++) 
    scanf("%d%d", &(start[i]), &(size[i]));
  for (int i = 0; i < n; i++) {
    allocateMemory(&head, start[i], size[i]);
    printMemory(head);
  }
  for (int i = n - 1; i >= 0; i--) {
    freeMemory(&head, start[i], size[i]);
    printMemory(head);
  }
  return 0;
}
/* end */
