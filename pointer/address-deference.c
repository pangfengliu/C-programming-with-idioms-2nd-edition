#include <stdio.h>
int main(void)
{
  int i;
  int *iptr = &i;
  scanf("%d", &i);
  printf("iptr = %p\n", iptr);
  printf("&iptr = %p\n", &iptr);
  printf("*iptr = %d\n", *iptr);
  printf("*(&iptr) = %p\n", *(&iptr));
  printf("&(*iptr) = %p\n", &(*iptr));
  printf("*(*(&iptr)) = %d\n", *(*(&iptr)));
  printf("*(&(*iptr)) = %d\n", *(&(*iptr)));
  printf("&(*(&iptr)) = %p\n", &(*(&iptr)));
  printf("i = %d\n", i);   /* errorcase */
  printf("&i = %p\n", &i);
  /* printf("*i = %p\n", *i); do not do this */
  printf("*(&i) = %d\n", *(&i));
  /* printf("&(*i) = %p\n", &(*i)); 
     do not do this either */
  return 0;
}
