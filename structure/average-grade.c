#include "grade.h" 

float average_grade(struct student *std_ptr)
{
  if (std_ptr->count == 0)
    return 0.0;
  else {
    float sum = 0.0;
    int i;
    for (i = 0; i < std_ptr->count; i++)
      sum += std_ptr->grade[i];
    return (sum / std_ptr->count);
  }
}
