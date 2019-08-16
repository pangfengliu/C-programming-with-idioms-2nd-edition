#include <stdio.h>
#include <assert.h>
int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; i++) {
    printf("----------------------------\n");
    printf("file = %s\n", argv[i]);
    FILE *fp = fopen(argv[i], "r");
    assert(fp != NULL);
    int c;
    while ((c = fgetc(fp)) != EOF)
      putchar(c);
  }
  return 0;
}
