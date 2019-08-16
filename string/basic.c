#include <stdio.h>
#include <string.h>
#include <assert.h>		/* for assert */
#include <stdlib.h>		/* for exit */
/* define */
/* max # of var */
#define VAR 100	       
/* max length of var name */
#define NAMELENGTH 80
/* max # of lines of code */
#define LINE 200       

enum Operator
  {ADD, SUB, MUL, DIV, MOD, EQL, NOTEQL,
   SMALLER, LARGER, SMALLEREQL, LARGEREQL};

enum StatementType
  {STOP, IF, GOTO, PRINT, ASSIGN};

/* find */
int find(char *string, char *table[])
{
  int index = 0;
  while (table[index] != NULL) {
    if (strcmp(string, table[index]) == 0)
      return index;
    index++;
  }
  return(-1); /* not found */
}
/* findOprCode */
int findOprCode(char *name)
{
  char *operators[] ={"+", "-", "*", "/", "%", 
		      "==", "!=", "<", ">", 
		      "<=", ">=", NULL};
  int code = find(name, operators);
  if (code == -1)
    exit(-1);
  return(code);
}
/* findVariable */
int findVariable (char *name,
		  char *varNameTable[])
{
  int index = find(name, varNameTable);
  if (index == -1)
    exit(-1);
  return(index);
}
/* processIF */
void processIF(int lineNum,char *varNameTable[],
	       int code[], int opd1[],
	       int opd2[], int compopr[],
	       int gotoLine[])
{
  char gotoStr[NAMELENGTH];
  char opd[NAMELENGTH], opr[NAMELENGTH];

  code[lineNum] = IF;
  scanf("%s", opd);
  opd1[lineNum] = 
    findVariable(opd, varNameTable);
  scanf("%s", opr);
  compopr[lineNum] = findOprCode(opr);
  scanf("%s", opd);
  opd2[lineNum] = 
    findVariable(opd, varNameTable);
  scanf("%s", gotoStr);
  assert(strcmp(gotoStr, "GOTO") == 0);
  scanf("%d", &(gotoLine[lineNum]));
}
/* processASSIGN */
void processASSIGN(int lineNum, char *first,
		   char *varNameTable[],
		   int code[], int opd1[],
		   int opd2[], int compopr[],
		   int target[])
{
  char opd[NAMELENGTH], opr[NAMELENGTH];
  code[lineNum] = ASSIGN;
  target[lineNum] = 
    findVariable(first, varNameTable);
  char assignStr[NAMELENGTH];
  scanf("%s", assignStr);
  assert(strcmp(assignStr, "=") == 0);
  scanf("%s", opd);
  opd1[lineNum] = 
    findVariable(opd, varNameTable);
  scanf("%s", opr);
  compopr[lineNum] = findOprCode(opr);
  scanf("%s", opd);
  opd2[lineNum] = 
    findVariable(opd, varNameTable);
}
/* processCode */
void processCode(char *varNameTable[],
		 int code[], int opd1[],
		 int opd2[], int compopr[],
		 int gotoLine[],
		 int target[])
{
  char first[NAMELENGTH];
  char opd[NAMELENGTH];
  int lineNum = 2;  /* 1 is for var */
  char *firstTable[] =
    {"STOP", "IF", "GOTO", "PRINT", NULL};
  int firstTableSize =
    sizeof(firstTable) / sizeof(char *);
  while (scanf("%s", first) != EOF) {
    int firstType = find(first, firstTable);
    switch (firstType) {
    case GOTO:
      code[lineNum] = GOTO;
      scanf("%d", &(gotoLine[lineNum]));
      break;
    case STOP:
      code[lineNum] = STOP;
      break;
    case IF:
      code[lineNum] = IF;
      processIF(lineNum, varNameTable, code,
		opd1, opd2, compopr, gotoLine);
      break;
    case PRINT:
      code[lineNum] = PRINT;
      scanf("%s", opd);
      target[lineNum] =
	findVariable(opd, varNameTable);
      break;
    default:	       /* must be assignment */
      code[lineNum] = ASSIGN;
      processASSIGN(lineNum, first,varNameTable,
		    code, opd1, opd2, compopr,
		    target);
      break;
    }
    lineNum++;
  }
}
/* compare */
int compare(int operand1, int operand2, 
	    int operator)
{
  switch (operator) {
  case EQL:
    return (operand1 == operand2);
  case NOTEQL:
    return (operand1 != operand2);
  case SMALLER:
    return (operand1 < operand2);
  case LARGER:
    return (operand1 > operand2);
  case SMALLEREQL:
    return (operand1 <= operand2);
  case LARGEREQL:
    return (operand1 >= operand2);
  default:
    printf("invalid comp %d\n", operator);
    exit(-1);
  }
}
/* arithmetic */
int arithemetic(int operand1, int operand2,
		int operator)
{
  switch (operator) {
  case ADD:
    return (operand1 + operand2);
  case SUB:
    return (operand1 - operand2);
  case MUL:
    return (operand1 * operand2);
  case DIV:
    return (operand1 / operand2);
  case MOD:
    return (operand1 % operand2);
  default:
    printf("invalid comp %d\n", operator);
    exit(-1);
  }
}
/* runCode */
void runCode(char varName[][NAMELENGTH],
	     int varValue[], int code[],
	     int opd1[], int opd2[],
	     int compopr[], int gotoLine[],
	     int target[])
{
  int line = 2; /* starts at 2 */
  while (code[line] != STOP) {
    switch (code[line]) {
    case IF:
      if (compare(varValue[opd1[line]],
		  varValue[opd2[line]],
		  compopr[line]))
	line = gotoLine[line];
      else
	line++;
      break;
    case GOTO:
      line = gotoLine[line];
      break;
    case ASSIGN:
      varValue[target[line]] = 
	arithemetic(varValue[opd1[line]],
		    varValue[opd2[line]], 
		    compopr[line]);
      line++;
      break;
    case PRINT:
      printf("%d\n", varValue[target[line]]);
      line++;
      break;
    default:
      printf("invalid code %d\n", code[line]);
      exit(-1);
    }
  }
}
/* readVariable */
void readVariable(char varName[][NAMELENGTH], 
		 int varValue[],
		 char *varNameTable[])
{  
  int count = 0;
  char name[NAMELENGTH];

  scanf("%s", name);
  while (strcmp(name, "END") != 0) {
    char assignStr[NAMELENGTH];
    strcpy(varName[count], name);
    scanf("%s", assignStr);
    assert(strcmp(assignStr, "=") == 0);
    scanf("%d", &(varValue[count]));
    varNameTable[count] = varName[count];
    count++;
    scanf("%s", name);
  }
  varNameTable[count] = NULL;
}
/* main */
int main ()
{
  char varName[VAR][NAMELENGTH];
  int varValue[VAR];
  char *varNameTable[VAR];
  /* get variables */
  readVariable(varName, varValue, varNameTable);
  int code[LINE]; 
  int opd1[LINE], compopr[LINE], opd2[LINE];  
  int gotoLine[LINE]; /* IF */
  int target[LINE];  /* both PRINT and ASSIGN */
  /* process code */
  processCode(varNameTable, code, opd1,
	      opd2, compopr, gotoLine, target);
  /* run code */
  runCode(varName, varValue, code, opd1, 
	  opd2, compopr, gotoLine, target);   
  return 0;
}
/* end */
