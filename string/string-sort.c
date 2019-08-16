#include <stdio.h>
#include <string.h>

#define ZODIAC 12
#define STRINGLEN 40

int main(void)
{
  char zodiac[ZODIAC][STRINGLEN];
  for (int i = 0; i < ZODIAC; i++)
    scanf("%s", zodiac[i]);

  for (int i = ZODIAC - 2; i >= 1; i--)
    for (int j = 0; j <= i; j++)
      if (strcmp(zodiac[j], zodiac[j+1]) > 0) {
	char temp[STRINGLEN];
	strcpy(temp, zodiac[j]);
	strcpy(zodiac[j], zodiac[j + 1]);
	strcpy(zodiac[j + 1], temp);
      }

  for (int i = 0; i < ZODIAC; i++)
    printf("%s\n", zodiac[i]);
  return 0;
}

