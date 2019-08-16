#include <stdio.h>
#include <assert.h>

void dump_file(char *filename, char *mode)
{
  int c;
  int count = 0;
  FILE *fp = fopen(filename, mode);

  assert(fp != NULL);
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

int main(void)
{
  FILE *fp;
  char c;

  fp = fopen("binary", "wb");
  assert(fp != NULL);
  fputs("hello\n", fp);
  fclose(fp);

  fp = fopen("text", "wt");
  assert(fp != NULL);
  fputs("hello\n", fp);
  fclose(fp);

  dump_file("binary", "rb");
  dump_file("text", "rb");
  dump_file("text", "rt");

  return 0;
}
