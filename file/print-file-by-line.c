#include <stdio.h>
#include <assert.h>
#define STRINGLEN 128
int main(void)
{
  FILE *fp;
  char string[STRINGLEN];
  fp = fopen("print-file-by-line.c", "r");
  assert(fp != NULL);
  while (fgets(string, STRINGLEN, fp) != NULL)
    fputs(string, stdout);
  fclose(fp);
  return 0;
}
