#include <stdio.h>
#include <string.h>
int main(void)
{
  char source[40] = "This is a string.";
  char destination[4];
  printf("The address of source = %p.\n",source);
  printf("The size of source = %lu\n", 
	 sizeof(source));
  printf("The address of destination = %p\n", 
	 destination);
  printf("The size of destination = %lu\n", 
	 sizeof(destination));
  printf("strlen(source) = %lu\n",strlen(source));
  strcpy(destination, source);
  printf("source <%s>\n", source);
  printf("destination <%s>\n",destination);
  return 0;
}
