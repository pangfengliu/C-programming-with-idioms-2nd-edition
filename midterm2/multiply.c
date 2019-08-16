#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// #define DEBUG

#define MAXC 128
#define MAXUNKNOWN 26		/* 26 letters */

typedef struct unknowns {
  char name[MAXUNKNOWN];
  int number;
} Unknowns;

typedef struct equation {
  char multiplier[MAXC];
  char multiplicant[MAXC];
  char product[MAXC];
} Equation;

int testOK(Equation *equation)
{
  int multiplierValue = atoi(equation->multiplier);
  int multiplicantValue = atoi(equation->multiplicant);
  int productValue = atoi(equation->product);
  int OK = multiplierValue * multiplicantValue == productValue;

  if (OK)
    printf("%d x %d == %d\n", multiplicantValue, multiplierValue, productValue);
  return (OK);
}

void replaceString(char *string, char from, char to)
{
  int i;
  for (i = 0; i < strlen(string); i++)
    if (string[i] == from)
      string[i] = to;
}

void replace(Equation *equation, char unknown, char onetonine)
{
  replaceString(equation->multiplier, unknown, onetonine);
  replaceString(equation->multiplicant, unknown, onetonine);
  replaceString(equation->product, unknown, onetonine);
}

void addUnknown(char *string, int has[])
{
  int i;
  for (i = 0; i < strlen(string); i++)
    if (isalpha(string[i]))
      has[string[i] - 'A'] = 1;
}

void processUnknown(Equation *equation, Unknowns *unknowns)
{
  int has[MAXUNKNOWN] = {0};
  int i;

  addUnknown(equation->multiplier, has);
  addUnknown(equation->multiplicant, has);
  addUnknown(equation->product, has);

  unknowns->number = 0;
  for (i = 0; i < MAXUNKNOWN; i++)
    if (has[i]) {
      unknowns->name[unknowns->number] = 'A' + i;
      (unknowns->number)++;
    }
}

int solve(Equation equation, Unknowns *unknowns, int n)
{
  if (n == unknowns->number) 
    return testOK(&equation);

  int i;
  for (i = 1; i < 10; i++) {
    Equation newEquation = equation;
    replace(&newEquation, unknowns->name[n], '0' + i);
    if (solve(newEquation, unknowns, n + 1))
      return 1;
  }
  return 0;
}

int main()
{
  Unknowns unknowns; 
  Equation equation;
  scanf("%s", equation.multiplicant);
  scanf("%s", equation.multiplier);
  scanf("%s", equation.product);

  processUnknown(&equation, &unknowns);
  solve(equation, &unknowns, 0);
  return 0;
}
