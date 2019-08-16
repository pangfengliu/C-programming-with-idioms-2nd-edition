#include <stdio.h>
#include <string.h>

int min(int a, int b)
{
  return (a < b? a : b);
}

void fusion(char *string1, char *string2)
{
  int length1 = strlen(string1);
  int length2 = strlen(string2);
  int maxFusionLength = min(length1, length2);
  int length;
  for (length = maxFusionLength; length >= 0; length--)
    if (strncmp(string1 + length1 - length, string2, length) == 0) {
      strcat(string1, string2 + length);
      return; 
    }
  return;			/* never get here */
}

#define MAXC 128

int main()
{
  char string[MAXC];
  char result[MAXC];
  
  scanf("%s", result);
  while (scanf("%s", string) != EOF)
    fusion(result, string);

  printf("%s\n", result);
  return 0;
}
