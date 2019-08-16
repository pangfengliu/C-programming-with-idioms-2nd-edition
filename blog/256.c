#include <stdio.h>

int main(void)
{
  FILE *fp;
  char c;
  fp = fopen("file", "wb");
  for (c = 0; c < 256; c++)
    fputc(c, fp);
  fclose(fp);
  return 0;
}
