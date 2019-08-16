/* check */
#include <stdio.h>
#include <ctype.h>
void check(char c)
{
  printf("c = %c\n", c);
  if (isalnum(c))
    printf("isalnum\n");
  if (isalpha(c))
    printf("isalpha\n");
  if (islower(c))
    printf("islower\n");
  if (isupper(c))
    printf("isupper\n");
  if (isdigit(c))
    printf("isdigit\n");
  if (isxdigit(c))
    printf("isxdigit\n");
  if (isprint(c))
    printf("isprint\n");
  if (isgraph(c))
    printf("isgraph\n");
  if (isspace(c))
    printf("isspace\n");
  if (ispunct(c))
    printf("ispunct\n");
  if (iscntrl(c))
    printf("iscntrl\n");
  return;
}
/* main */
int main(void)
{
  char c;
  while (scanf("%c", &c) != EOF) 
    check(c);
  return 0;
}
/* end */
