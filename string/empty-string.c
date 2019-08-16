#include <stdio.h>

int main(void)
{
  char emptyString[] = "";
  printf("sizeof(emptyString) = %ld\n", 
	 sizeof(emptyString));
  printf("emptyString looks like %s\n", 
	 emptyString); 
  return 0;
}
