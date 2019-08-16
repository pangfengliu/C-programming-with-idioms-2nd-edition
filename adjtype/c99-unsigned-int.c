#include<stdio.h>
#include<stdint.h>
int main(void)
{
  printf("sizeof(uint8_t) = %ld\n",
	 sizeof(uint8_t));
  printf("sizeof(uint16_t) = %ld\n",
	 sizeof(uint16_t));
  printf("sizeof(uint32_t) = %ld\n",
	 sizeof(uint32_t));
  printf("sizeof(uint64_t) = %ld\n", 
	 sizeof(uint64_t));
  printf("UINT8_MAX = %u\n", UINT8_MAX);
  printf("UINT16_MAX = %u\n", UINT16_MAX);
  printf("UINT32_MAX = %u\n", UINT32_MAX);
  printf("UINT64_MAX = %lu\n", UINT64_MAX);
  return 0;
}
