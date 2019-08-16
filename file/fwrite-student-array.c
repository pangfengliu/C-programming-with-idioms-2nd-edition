/* declaration */
#include <stdio.h>
#include <assert.h>
#define NAMELEN 20
#define PHONENUM 10
#define GRADE 4
struct student {
  char name[NAMELEN];
  int id;
  char phone[PHONENUM];
  float grade[GRADE];
  int year;
  int month;
  int day;
};
typedef struct student Student;  
/* printstudent */
void printStudent(Student *s)
{
  puts(s->name);
  printf("id = %d\n", s->id);
  puts(s->phone);
  printf("grade = %f %f %f %f\n", s->grade[0], 
	 s->grade[1], s->grade[2], s->grade[3]);
  printf("%d %d %d\n",  
	 s->year, s->month, s->day);
}
/* dumpfile */
void dumpFile(char *filename, char *mode)
{
  int c;
  int count = 0;
  FILE *fp = fopen(filename, mode);
  assert(fp != NULL);
  while ((c = fgetc(fp)) != EOF) {
    printf("%02x ", c);
    count++;
    if (count % 16 == 0)
      putchar('\n');
  }
  fclose(fp);
  printf("\nThere are %d bytes in file %s\n", 
	 count, filename);
  return;
}
/* main */
int main(void)
{
  Student a[2] = 
    {{"John Smith", 12345, "1234567", 
      {3.0, 3.0, 3.0, 3.0}, 2000, 1, 1},
     {"Mary Smith", 67890, "7654321", 
      {4.0, 4.0, 4.0, 4.0}, 2000, 1, 1}};
  Student b[2];

  FILE *fp = fopen("file", "wb");
  assert(fp != NULL);
  fwrite(a, sizeof(Student), 2, fp);
  fclose(fp);

  fp = fopen("file", "rb");
  assert(fp != NULL);
  fread(b, sizeof(Student), 2, fp);
  fclose(fp);

  for (int i = 0; i < 2; i++)
    printStudent(&(b[i]));
  dumpFile("file", "rb");
  return 0;
}
/* end */
