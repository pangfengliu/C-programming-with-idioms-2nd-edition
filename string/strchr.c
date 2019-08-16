#include <stdio.h>
#include <string.h>
#include <assert.h>
#define PATHLEN 40
#define FILE 40 
/* main */
int main(void)
{
  char pathname[PATHLEN];
  scanf("%s", pathname);
  char *start = pathname;
  char file[FILE][PATHLEN];
  int fileCount = 0;
  if (*start == '/')
    start++;
  while (start != NULL) {
    char *slash = strchr(start, '/');
    if (slash == NULL) {
      strcpy(file[fileCount], start);
      fileCount++;
      start = NULL;
    } else {
      strncpy(file[fileCount], start,
	      slash - start);
      file[fileCount][slash - start] = '\0';
      fileCount++;
      start = slash + 1;
    }
    assert(fileCount < FILE);
  }
  for (int i = 0; i < fileCount; i++)
    printf("%s\n", file[i]);
  return 0;
}
/* end */
