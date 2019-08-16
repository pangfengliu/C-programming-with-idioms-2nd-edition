#include <stdio.h>
#include <stddef.h>
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
  printf("name is at %ld\n",
	 offsetof(struct student, name));
  printf("id is at %ld\n",
	 offsetof(struct student, id));
  printf("phone is at %ld\n",
	 offsetof(struct student, phone));
  printf("grade is at %ld\n",
	 offsetof(struct student, grade));
  printf("birthYear is at %ld\n", 
	 offsetof(struct student, birthYear));
  printf("birthMonth is at %ld\n", 
	 offsetof(struct student, birthMonth));
  printf("birthDay is at %ld\n", 
	 offsetof(struct student, birthDay));
  return 0;
}
