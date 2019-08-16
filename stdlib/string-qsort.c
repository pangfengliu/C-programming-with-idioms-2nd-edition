#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define STRLENGTH 80
#define ZODIAC 12
int compare(const void *ptr1, const void *ptr2)
{
  return(strcmp((char *) ptr1, (char *) ptr2));
}
int main(void)
{
  char zodiac[ZODIAC][STRLENGTH];
  for (int i = 0; i < ZODIAC; i++)
    scanf("%s", zodiac[i]);
  qsort(zodiac, ZODIAC, sizeof(char)*STRLENGTH, 
	compare);
  for (int i = 0; i < ZODIAC; i++)
    puts(zodiac[i]);
  return 0;
}
