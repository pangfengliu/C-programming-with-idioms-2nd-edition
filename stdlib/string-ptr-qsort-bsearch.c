/* compare */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ZODIAC 12
#define STRLENGTH 80
int compare(const void *ptr1, const void *ptr2)
{
  return(strcmp(*((char**)ptr1), 
		*((char**)ptr2)));
}
/* main */
int main(void)
{
  char zodiac[ZODIAC][STRLENGTH];
  char *zodiacPtr[ZODIAC]; 
  for (int i = 0; i < 12; i++) {
    zodiacPtr[i] = zodiac[i];
    scanf("%s", zodiac[i]);
  }
  qsort(zodiacPtr, ZODIAC, sizeof(char *), 
	compare);
  for (int i = 0; i < ZODIAC; i++)
    puts(zodiacPtr[i]);
  char key[STRLENGTH];
  scanf("%s", key);
  char *keyPtr = key;
  char **found =
    ((char **)bsearch(&keyPtr, zodiacPtr,
		      ZODIAC, sizeof(char *),
		      compare));
  printf("found in %ld-th position as %s\n",
	 found - zodiacPtr, *found);
  return 0;
}
/* end */
