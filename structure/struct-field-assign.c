#include <stdio.h>
#include <string.h>
#define NAMELEN 20
#define PHONELEN 10
#define YEAR 4
struct student {
  char name[NAMELEN];
  int id;
  char phone[PHONELEN];
  float grade[YEAR];
  int birthYear;
  int birthMonth;
  int birthDay;
};  
/* main */
int main(void)
{
  struct student john;
  strcpy(john.name, "John Smith");
  john.id = 12345;
  strcpy(john.phone, "1234567");
  john.grade[0] = 4.0;
  john.grade[1] = 3.9;
  john.grade[2] = 3.8;
  john.grade[3] = 3.6;
  john.birthYear = 2000;
  john.birthMonth = 1;
  john.birthDay = 1;
  /* print */
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
/* end */
