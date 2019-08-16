#include <stdio.h>
#include <sys/stat.h>
int main(void)
{
  char pathname[80];
  struct stat stat_info;
  scanf("%s", pathname);
  stat(pathname, &stat_info);
  if (0400 & stat_info.st_mode) 
    printf("USR" " can read.\n"); 
  if (0200 & stat_info.st_mode) 
    printf("USR" " can write.\n"); 
  if (0100 & stat_info.st_mode) 
    printf("USR" " can exec.\n"); 
  if ((0400 >> 3) & stat_info.st_mode) 
    printf("GRP" " can read.\n"); 
  if ((0200 >> 3) & stat_info.st_mode) 
    printf("GRP" " can write.\n"); 
  if ((0100 >> 3) & stat_info.st_mode) 
    printf("GRP" " can exec.\n"); 
  if (((0400 >> 3) >> 3) & stat_info.st_mode) 
    printf("OTH" " can read.\n"); 
  if (((0200 >> 3) >> 3) & stat_info.st_mode) 
    printf("OTH" " can write.\n"); 
  if (((0100 >> 3) >> 3) & stat_info.st_mode) 
    printf("OTH" " can exec.\n");
  return 0;
}
