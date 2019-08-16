#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// #define DEBUG

#define MAXC 128
#define MAXUNKNOWN 26		/* 26 letters */

typedef struct unknowns {
  char name[MAXUNKNOWN];
  char value[MAXUNKNOWN];
  int number;
} Unknowns;

typedef struct equation {
  char multiplier[MAXC];
  char multiplicant[MAXC];
  char product[MAXC];
} Equation;

void replaceString(char *string, Unknowns *unknowns)
{
  int i, j;
  for (i = 0; i < strlen(string); i++)
    for (j = 0; j < unknowns->number; j++)
      if (string[i] == unknowns->name[j])
	string[i] = unknowns->value[j];
}

Equation replace(Equation *equation, Unknowns *unknowns)
{
  Equation equationAfter = *equation;
  replaceString(equationAfter.multiplier, unknowns);
  replaceString(equationAfter.multiplicant, unknowns);
  replaceString(equationAfter.product, unknowns);
  return equationAfter;
}

#ifdef DEBUG
void printEquation(Equation *equation)
{
  printf("%s x %s = %s\n", equation->multiplier, equation->multiplicant,
	 equation->product);
}

void printUnknowns(Unknowns *unknowns)
{
  int i;
  for (i = 0; i < unknowns->number; i++)
    printf("%c = %c\n", unknowns->name[i], unknowns->value[i]);
}
#endif

int testOK(Equation *equation, Unknowns *unknowns)
{
  Equation equationAfter = replace(equation, unknowns);
#ifdef DEBUG
  printUnknowns(unknowns);
  printEquation(&equationAfter);
#endif
  int multiplierValue = atoi(equationAfter.multiplier);
  int multiplicantValue = atoi(equationAfter.multiplicant);
  int productValue = atoi(equationAfter.product);
  int OK = multiplierValue * multiplicantValue == productValue;

  if (OK)
    printf("%d x %d == %d\n", multiplicantValue, multiplierValue, productValue);
  return (OK);
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

int solve(Equation *equation, Unknowns *unknowns, int n)
{
  if (n == unknowns->number) 
    return testOK(equation, unknowns);

  int i;
  for (i = 1; i < 10; i++) {
    unknowns->value[n] = '0' + i;
    if (solve(equation, unknowns, n + 1))
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
  solve(&equation, &unknowns, 0);
  return 0;
}
