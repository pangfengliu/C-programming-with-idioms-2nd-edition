#include <stdio.h>
#include <string.h>
int find(char *string, char *table[])
{
  int index = 0;
  while (table[index] != NULL) {
    if (strcmp(string, table[index]) == 0)
      return index;
    index++;
  }
  return -1;
}
#define STRINGSIZE 80
int main()
{
  char *table[] =
    {"+", "-", "*", "/", "%", "==", "!=",
     "<", ">", "<=", ">=", NULL};
  char string[STRINGSIZE];
  while (scanf("%s", string) != EOF)
    printf("%d\n", find(string, table));
  return 0;
}
