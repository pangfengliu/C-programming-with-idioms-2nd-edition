#include <stdio.h>
#include <string.h>
#include <assert.h>
#define PATHLEN 40
#define FILE 40
int main(void)
{
  char pathname[PATHLEN];
  scanf("%s", pathname);
  char file[FILE][PATHLEN];
  int fileCount = 0;
  char letters[] = "abcdefghijklmnopqrstuvwxyz";
  char *start = pathname;
  int skipLength = strcspn(start, letters);
  while (skipLength < strlen(start)) {
    start += skipLength;
    int copyLength = strspn(start, letters);
    strncpy(file[fileCount], start, copyLength);
    file[fileCount][copyLength] = '\0';
    fileCount++;
    assert(fileCount < FILE);
    start += copyLength;
    skipLength = strcspn(start, letters);
  }
  for (int i = 0; i < fileCount; i++)
    printf("%s\n", file[i]);
  return 0;
}

