#include <stdio.h>
#define X 2
#define Y 3
#define Z 4
int main()
{
  int a[X][Y][Z];
  int *intPtr;
  int *arrayPtr[Z];
  int *matrixPtr[Y][Z];
  
  printf("sizeof(intPtr) = %ld\n",
	 sizeof(intPtr));
  printf("sizeof(arrayPtr) = %ld\n",
	 sizeof(arrayPtr));
  printf("sizeof(matrixPtr) = %ld\n\n",
	 sizeof(matrixPtr));
  return 0;
}
