#include <stdio.h>
#include <string.h>

int main(void)
{
  char string1[80] = "programming";
  char string2[] = "programming";
  char *string3 = "programming";
  strcpy(string1, "more programming");
  strcpy(string2, "more programming");
  strcpy(string3, "more programming");
  return 0;
}


