#include <stdio.h>
#include <sys/stat.h>
int main(void)
{
  char pathname[80];
  struct stat stat_info;
  scanf("%s", pathname);
  stat(pathname, &stat_info);
  if (S_IRUSR & stat_info.st_mode) 
    printf("USR" " can read.\n"); 
  if (S_IWUSR & stat_info.st_mode) 
    printf("USR" " can write.\n"); 
  if (S_IXUSR & stat_info.st_mode) 
    printf("USR" " can exec.\n"); 
  if (S_IRGRP & stat_info.st_mode) 
    printf("GRP" " can read.\n"); 
  if (S_IWGRP & stat_info.st_mode) 
    printf("GRP" " can write.\n"); 
  if (S_IXGRP & stat_info.st_mode) 
    printf("GRP" " can exec.\n"); 
  if (S_IROTH & stat_info.st_mode) 
    printf("OTH" " can read.\n"); 
  if (S_IWOTH & stat_info.st_mode) 
    printf("OTH" " can write.\n"); 
  if (S_IXOTH & stat_info.st_mode) 
    printf("OTH" " can exec.\n");
  return 0;
}
