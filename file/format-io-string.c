#include <stdio.h>
#define N 4096
int main(void)
{
  char filename[N];
  int year[2], month[2], day[2];
  scanf("%d%d%d", &year[0], &month[0], &day[0]);
  sprintf(filename, "file-%4d-%02d-%02d", 
	  year[0], month[0], day[0]);
  printf("filename is %s\n", filename);
  sscanf(filename, "file-%d-%d-%d", 
	 &year[1], &month[1], &day[1]);
  printf("year %d month %d day %d\n", 
	 year[1], month[1], day[1]);
  return 0;
}
