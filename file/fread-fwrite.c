#include <stdio.h>
#include <assert.h>
void dumpFile(char *filename, char *mode)
{
  FILE *fp = fopen(filename, mode);
  assert(fp != NULL);
  int c, count = 0;
  while ((c = fgetc(fp)) != EOF) {
    printf("%02x ", c);
    count++;
    if (count % 16 == 0)
      putchar('\n');
  }
  fclose(fp);
  printf("\nThere are %d bytes in file %s\n", 
	 count, filename);
  return;
}
/* main */
#define ARRAYSIZE 10
int main(void)
{
  int a[ARRAYSIZE], b[ARRAYSIZE];
  for (int i = 0; i < ARRAYSIZE; i++)
    a[i] = i;
  FILE *fp = fopen("file", "wb");
  assert(fp != NULL);
  fwrite(a, sizeof(int), ARRAYSIZE, fp);
  fclose(fp);
  fp = fopen("file", "rb");
  assert(fp != NULL);
  fread(b, sizeof(int), ARRAYSIZE, fp);
  fclose(fp);
  for (int i = 0; i < ARRAYSIZE; i++)
    printf("%d\n", b[i]);
  dumpFile("file", "rb");
  return 0;
}
/* end */
