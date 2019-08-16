#include<stdio.h>
#include<stdint.h>
int main(void)
{
  printf("sizeof(int8_t) = %ld\n",
	 sizeof(int8_t));
  printf("sizeof(int16_t) = %ld\n",
	 sizeof(int16_t));
  printf("sizeof(int32_t) = %ld\n",
	 sizeof(int32_t));
  printf("sizeof(int64_t) = %ld\n", 
	 sizeof(int64_t));
  printf("INT8_MIN = %d INT8_MAX = %d\n",
	 INT8_MIN, INT8_MAX);
  printf("INT16_MIN = %d INT16_MAX = %d\n",
	 INT16_MIN, INT16_MAX);
  printf("INT32_MIN = %d INT32_MAX = %d\n",
	 INT32_MIN, INT32_MAX);
  printf("INT64_MIN = %ld\nINT64_MAX = %ld\n",
	 INT64_MIN, INT64_MAX);
  return 0;
}
