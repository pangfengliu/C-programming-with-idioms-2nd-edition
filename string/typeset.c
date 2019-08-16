#include <stdio.h>
#include <string.h>

int main(void)
{
  char word[80];
  int current_width = 0;
  int width;

  scanf("%d", &width);
  while (scanf("%s", word) != EOF) 
    if (current_width == 0 || (current_width + 1 + strlen(word) > width)) {
      if (current_width != 0)
	printf("\n");
      printf("%s", word);
      current_width = strlen(word);
    } else {
      printf(" %s", word);
      current_width += (1 + strlen(word));
    } 
  return 0;
}
