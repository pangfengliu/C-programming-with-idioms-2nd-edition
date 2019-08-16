#include "date.h"
#define NAMELEN 20
#define PHONELEN 10
#define YEAR 4
typedef struct student {
  char name[NAMELEN];
  int id;
  char phone[PHONELEN];
  float grade[YEAR];
  Date birthday;
} Student;

