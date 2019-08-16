#include <stdio.h>
#include <ctype.h>

int main()
{
  char string1[8];
  char string2[8];
  int A = 0;
  int B = 0;
  int i, j;
  
  scanf("%s", string1);
  scanf("%s", string2);

  for (i = 0; i < 4; i++)
    if (string1[i] == string2[i])
      A++;

  for (i = 0; i < 4; i++)
    for (j = 0; j < 4; j++)
      if (i != j && string1[i] == string2[i])
	B++;

  printf("%dA%dB\n", A, B);
  return 0;
}
