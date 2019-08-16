#include <stdio.h>
#include <ctype.h>
int main(void)
{
  char c;
  c = toupper('m');
  printf("%c", c);
  c = toupper('a');
  printf("%c", c);
  c = toupper('i'); 
  printf("%c", c);
  c = toupper('n');
  printf("%c", c);
  c = toupper('('); 
  printf("%c", c);
  c = toupper(')'); 
  printf("%c", c);
  c = toupper('\n'); 
  printf("%c", c);
  c = toupper('{'); 
  printf("%c", c);
  c = toupper('\n');
  printf("%c", c);
  c = toupper('}'); 
  printf("%c", c);
  c = toupper('\n');
  printf("%c", c);
  return 0;
}
