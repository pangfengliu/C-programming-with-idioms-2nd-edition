#include <stdio.h>
#include <ctype.h>

int main(void)
{
  char c;
  while (scanf("%c", &c) != EOF) {
    if (isupper(c))
      c = tolower(c);
    else if (islower(c))
      c = toupper(c);

    printf("%c", c);
  }
  return 0;
}
