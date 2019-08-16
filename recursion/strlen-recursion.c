#include <stdio.h>
int myStrlen(char *string)
{
  if (*string == '\0')
    return 0;
  return(myStrlen(string + 1) + 1);
}
#define STRINGLEN 128
int main(void)
{
  char string[STRINGLEN];
  scanf("%s", string);
  printf("myStrlen(string) = %d\n", 
	 myStrlen(string));
  return 0;
}
