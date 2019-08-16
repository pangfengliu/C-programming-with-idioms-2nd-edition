#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct employee {
  int ID;
  char name[2][32];
  int bossID;
} Employee;

typedef struct employees {
  int number;
  Employee employee[32];
} Employees;

int name2index(char name[][32], Employees employees)
{
  int i;
  for (i = 0; i < employees.number; i++)
    if (strcmp(name[0], employees.employee[i].name[0]) == 0 &&
	strcmp(name[0], employees.employee[i].name[0]) == 0)
      return i;
  printf("cannot find name %s %s\n", name[0], name[1]);
  exit(-1);
}

int id2index(int id, Employees employees)
{
  int i;
  for (i = 0; i < employees.number; i++)
    if (id == employees.employee[i].ID)
      return i;
  printf("cannot find id %d\n", id);
  exit(-1);
}

int top(int index, Employees employees)
{
  return (employees.employee[index].ID == employees.employee[index].bossID);
}

int boss(char name1[][32], char name2[][32], Employees employees)
{
  int index1 = name2index(name1, employees);
  int index2 = name2index(name2, employees);

  do {
    index1 = id2index(employees.employee[index1].bossID, employees);
    if (index1 == index2)
      return 1;
  }
  while (!top(index1, employees));

  return 0;
}

int superBoss(char name[][32], Employees employees)
{
  int index = name2index(name, employees);

  while (!top(index, employees)) {
    index = id2index(employees.employee[index].bossID, employees);
  }
  return index;
}

int main()
{
  Employee employee;
  Employees employees;
  char name1[2][32], name2[2][32];
  int i, n, m;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%s%s%d", &(employee.ID), employee.name[0],
	  employee.name[1], &(employee.bossID));
    employees.employee[i] = employee;
  }
  employees.number = i;
#ifdef DEBUG
  for (i = 0; i < employees.number; i++)
    printf("%d %s %s %d\n", employees.employee[i].ID, employees.employee[i].name[0], employees.employee[i].name[1], employees.employee[i].bossID);
#endif
  scanf("%d", &m);
  for (i = 0; i < m; i++) {
    scanf("%s%s%s%s", name1[0], name1[1], name2[0], name2[1]); 
    if (boss(name1, name2, employees))
      printf("subordinate\n");
    else if (boss(name2, name1, employees))
      printf("supervisor\n");
    else if (superBoss(name1, employees) == superBoss(name2, employees))
      printf("colleague\n");
    else
      printf("unrelated\n");
  }
  return 0;
}
