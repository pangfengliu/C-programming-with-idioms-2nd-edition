#include <stdio.h>

int main()
{
  FILE *fp;
  fp = fopen("test", "wb");
  int i;
  short int data;

  int count = 65536;
  fwrite(&count, sizeof(int), 1, fp);

  for (i = -32768; i < 32768; i++) {
    data = i;
    fwrite(&data, sizeof(short int), 1, fp);
  }

  fclose(fp);
  return 0;
}
