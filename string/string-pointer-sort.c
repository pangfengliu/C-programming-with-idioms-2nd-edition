#include <stdio.h>
#include <string.h>
#define ZODIAC 12
#define STRINGLEN 40
int main(void)
{
  char zodiac[ZODIAC][40], *zptr[ZODIAC];
  for (int i = 0; i < ZODIAC; i++) {
    scanf("%s", zodiac[i]);
    zptr[i] = zodiac[i];
  }
  for (int i = ZODIAC - 2; i >= 1; i--)
    for (int j = 0; j <= i; j++)
      if (strcmp(zptr[j], zptr[j + 1]) > 0) {
	char *temp = zptr[j];
	zptr[j] = zptr[j + 1];
	zptr[j + 1] = temp;
      }
  for (int i = 0; i < ZODIAC; i++)
    printf("%s\n", zptr[i]);
  return 0;
}
