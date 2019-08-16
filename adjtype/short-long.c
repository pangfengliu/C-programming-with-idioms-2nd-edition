#include<stdio.h>

int main(void)
{
  printf("sizeof(short int) = %ld\n",
	 sizeof(short int));
  printf("sizeof(int) = %ld\n",
	 sizeof(int));
  printf("sizeof(long) = %ld\n",
	 sizeof(long));
  printf("sizeof(long int) = %ld\n",
	 sizeof(long int));
  printf("sizeof(long long int) = %ld\n", 
	 sizeof(long long int));
  return 0;
}
