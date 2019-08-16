#include <stdio.h>
int main()
{
  int count = 0;
  int sum = 0;

  int grade;
  scanf("%d", &grade);
  while (grade >= 0) {
    sum += grade;
    count++;
    scanf("%d", &grade);
  }
  
  double average = sum / count;
  printf("%f\n", average);
  average = (double) sum / count;
  printf("%f\n", average);
  average = (double) (sum / count);
  printf("%f\n", average);
}

  
