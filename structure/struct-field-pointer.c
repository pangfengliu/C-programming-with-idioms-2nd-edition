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
  struct student *ptr = &john;
  strcpy(ptr->name, "John Smith");
  ptr->id = 12345;
  strcpy(ptr->phone, "1234567");
  ptr->grade[0] = 4.0;
  ptr->grade[1] = 3.9;
  ptr->grade[2] = 3.8;
  ptr->grade[3] = 3.6;
  ptr->birthYear = 2000;
  ptr->birthMonth = 1;
  ptr->birthDay = 1;

  /* print */
  printf("name is %s\n", john.name);
  printf("id is %d\n", john.id);
  printf("phone is %s\n", john.phone);
  printf("grade is %f %f %f %f\n", john.grade[0],
       john.grade[1],john.grade[2],john.grade[3]);
  printf("birthYear is %d\n", john.birthYear);
  printf("birthMonth is %d\n", john.birthMonth);
  printf("birthDay is %d\n", john.birthDay);
  return 0;
}
/* end */
