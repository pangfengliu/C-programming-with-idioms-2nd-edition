#include <stdio.h>
#include <sys/stat.h>
#define printAllPermission(buf) \
  printPermission(buf, USR) \
  printPermission(buf, GRP) \
  printPermission(buf, OTH)
#define printPermission(buf, user) \
if (S_IR ## user & buf.st_mode) \
     printf(#user " can read.\n"); \
if (S_IW ## user & buf.st_mode) \
     printf(#user " can write.\n"); \
if (S_IX ## user & buf.st_mode) \
     printf(#user " can exec.\n");
int main(void)
{
  char pathname[80];
  struct stat stat_info;
  scanf("%s", pathname);
  lstat(pathname, &stat_info);
  printAllPermission(stat_info);
}
