#include <stdio.h>
#include <assert.h>

int main()
{
  FILE *fp;
  fp = fopen("test", "rb");
  assert(fp != NULL);
  int i;
  int count[65536] = {0};
  int n = 0;
  int maxFrequency = 0;
  int numberWithMaxFrequency;
  short int data;

  fread(&n, sizeof(int), 1, fp);
  printf("n = %d\n", n);
  for (i = 0; i < n; i++) {
    fread(&data, sizeof(short int), 1, fp);
    printf("%d\n", data);
    count[data + 32768]++;
  }
  
  for (i = 65535; i >= 0; i--) {
    if (count[i] > 0) {
      if (count[i] > maxFrequency) {
	maxFrequency = count[i];
	numberWithMaxFrequency = i - 32768;
      }
    }
  }

  printf("%d\n", numberWithMaxFrequency);
  printf("%d\n", maxFrequency);
  return 0;
}
