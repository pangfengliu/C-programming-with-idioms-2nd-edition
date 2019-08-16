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
  char *start = pathname;
  char delimeters[] = "aeiou";
  start = strtok(start, delimeters);
  while (start != NULL) {
    strcpy(file[fileCount], start);
    fileCount++;
    assert(fileCount < FILE);
    start = strtok(NULL, delimeters);
  }
  for (int i = 0; i < fileCount; i++)
    printf("%s\n", file[i]);
  printf("After strtok pathname becomes %s\n",
	 pathname); 
  return 0;
}
