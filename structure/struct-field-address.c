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
  struct student john;
  printf("name is at %p\n", &(john.name));
  printf("id is at %p\n", &(john.id));
  printf("phone is at %p\n", &(john.phone));
  printf("grade is at %p\n", &(john.grade));
  printf("birthYear is at %p\n", 
	 &(john.birthYear));
  printf("birthMonth is at %p\n", 
	 &(john.birthMonth));
  printf("birthDay is at %p\n", 
	 &(john.birthDay));
  return 0;
}
