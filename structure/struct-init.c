#include <stdio.h>
#define NAMELEN 20
#define PHONELEN 10
#define YEAR 4
struct student {
  char name[NAMELEN];
  int id;
  char phone[PHONELEN];
  float grade[YEAR];
  int birthYear, birthMonth, birthDay;
};  
int main(void)
{
  struct student john = 
    {"John Smith", 12345, "1234567", 
     {4.0, 3.9, 3.8, 3.6}, 2000, 1, 1};
  printf("name is %s\n", john.name);
  printf("id is %d\n", john.id);
  printf("phone is %s\n", john.phone);
  printf("grade is %f %f %f %f\n",
	 john.grade[0], john.grade[1],
	 john.grade[2], john.grade[3]);
  printf("birthYear is %d\n", john.birthYear);
  printf("birthMonth is %d\n", john.birthMonth);
  printf("birthDay is %d\n", john.birthDay);
  return 0;
}

