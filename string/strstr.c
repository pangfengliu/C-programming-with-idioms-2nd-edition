#include <stdio.h>
#include <string.h>
/* main */
#define ZODIAC 12
#define STRINGLEN 40
int main(void)
{
  char zodiac[ZODIAC][STRINGLEN];
  for (int i = 0; i < ZODIAC; i++)
    scanf("%s", zodiac[i]);
  for (int i = 0; i < ZODIAC; i++) {
      char *ptr = strstr(zodiac[i], "er");
    if (ptr == NULL)
      printf("No er in %s\n", zodiac[i]);
    else
      printf("er at %ld-th in %s\n", 
	     ptr - zodiac[i], zodiac[i]);
  }
  return 0;
}
/* end */
