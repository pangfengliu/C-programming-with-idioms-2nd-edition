/* dumpfile */
#include <stdio.h>
#include <assert.h>
void dumpFile(char *filename, char *mode)
{
  FILE *fp = fopen(filename, mode);
  assert(fp != NULL);
  int c;
  int count = 0;
  while ((c = fgetc(fp)) != EOF) {
    printf("%02x ", c);
    count++;
    if (count % 8 == 0)
      putchar('\n');
  }
  fclose(fp);
  printf("\nThere are %d bytes in file %s\n", 
	 count, filename);
  return;
}
/* main */
int main(void)
{
  FILE *fp = fopen("binary", "wb");
  assert(fp != NULL);
  fputs("hello\n", fp);
  fclose(fp);
  fp = fopen("text", "wt");
  assert(fp != NULL);
  fputs("hello\n", fp);
  fclose(fp);
  dumpFile("binary", "rb");
  dumpFile("text", "rb");
  dumpFile("text", "rt");
  return 0;
}
/* end */
