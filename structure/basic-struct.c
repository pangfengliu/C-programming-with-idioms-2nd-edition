#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

enum Operator
  {ADD, SUB, MUL, DIV, MOD, EQL, NOTEQL,
   SMALLER, LARGER, SMALLEREQL, LARGEREQL};

enum StatementType
  {STOP, IF, GOTO, PRINT, ASSIGN};

/* variable */
/* max length of var name */
#define NAMELENGTH 80  
typedef struct variable {
  char name[NAMELENGTH];
  int value;
} Variable;
/* variableset */
#define VAR 100	       /* max # of var */
typedef struct variableSet {
  Variable variables[VAR];
  char *varNameTable[VAR];
} VariableSet;
/* statement */
typedef struct statement {
  int code;
  int opd1, opd2, compopr;	/* IF */
  int gotoLine;			/* GOTO */
  int target;		/* ASSIGN and PRINT */
} Statement;
/* statementend */
int find(char *string, char *table[])
{
  int index = 0;
  while (table[index] != NULL) {
    if (strcmp(string, table[index]) == 0)
      return index;
    index++;
  }
  return(-1);			/* not found */
}

int findOprCode(char *name)
{
  char *operators[] = {"+", "-", "*", "/", "%", 
		       "==", "!=", "<", ">", 
		       "<=", ">=", NULL};
  int code = find(name, operators);
  if (code == -1)
    exit(-1);
  return(code);
}

int findVariable(char *name,
		 VariableSet *variableSet)
{
  int index =
    find(name, variableSet->varNameTable);
  if (index == -1)
    exit(-1);
  return(index);
}

void processIF(Statement *statement,
	       VariableSet *variableSet)
{
  char gotoStr[NAMELENGTH];
  char opd[NAMELENGTH], opr[NAMELENGTH];

  statement->code = IF;
  scanf("%s", opd);
  statement->opd1 = 
    findVariable(opd, variableSet);
  scanf("%s", opr);
  statement->compopr = findOprCode(opr);
  scanf("%s", opd);
  statement->opd2 = 
    findVariable(opd, variableSet);
  scanf("%s", gotoStr);
  assert(strcmp(gotoStr, "GOTO") == 0);
  scanf("%d", &(statement->gotoLine));
}

void processASSIGN(Statement *statement,
		   char *first, 
		   VariableSet *variableSet)
{
  char opd[NAMELENGTH], opr[NAMELENGTH];
  statement->target =
    findVariable(first, variableSet);
  char assignStr[NAMELENGTH];
  scanf("%s", assignStr);
  assert(strcmp(assignStr, "=") == 0);
  scanf("%s", opd);
  statement->opd1 = 
    findVariable(opd, variableSet);
  scanf("%s", opr);
  statement->compopr = findOprCode(opr);
  scanf("%s", opd);
  statement->opd2 = 
    findVariable(opd, variableSet);
}

/* processcode */
void processCode(VariableSet *variableSet,
		 Statement statements[])
{
  char first[NAMELENGTH], opd[NAMELENGTH];
  char *firstTable[] =   /* must in order */
    {"STOP", "IF", "GOTO", "PRINT", NULL};
  Statement *statement = &(statements[2]); 
  while (scanf("%s", first) != EOF) {
    int firstType = find(first, firstTable);
    switch (firstType) {
    case GOTO:
      statement->code = GOTO;
      scanf("%d",&(statement->gotoLine)); break;
    case STOP:
      statement->code = STOP; break;
    case IF:
      statement->code = IF;
      processIF(statement, variableSet); break;
    case PRINT:
      statement->code = PRINT;
      scanf("%s", opd);
      statement->target =
	findVariable(opd, variableSet); break;
    default:	       /* must be assignment */
      statement->code = ASSIGN;
      processASSIGN(statement, first,
		    variableSet);
      break;
    }
    statement++;
  }
}
/* processcodeend */
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
/* runcode */
void runCode(VariableSet *variableSet,
	     Statement statements[])
{
  int line = 2;
  Statement *statement = &(statements[line]);
  Variable *vars = variableSet->variables;
  
  while (statement->code != STOP) {
    switch (statement->code) {
    case IF:
      if (compare(vars[statement->opd1].value, 
		  vars[statement->opd2].value, 
		  statement->compopr))
	line = statement->gotoLine;
      else
	line++;
      break;
    case GOTO:
      line = statement->gotoLine;
      break;
    case ASSIGN:
      /* assignment */
      vars[statement->target].value = 
	arithemetic(vars[statement->opd1].value, 
		    vars[statement->opd2].value, 
		    statement->compopr);
      /* assignmentend */
      line++;
      break;
    case PRINT:
      printf("%d\n",
	     vars[statement->target].value);
      line++;
      break;
    default:
      printf("invalid code %d\n",
	     statement->code);
      exit(-1);
    }
    statement = &(statements[line]);
  }
}
/* readvariable */
void readVariable(VariableSet *variableSet)
{
  int count = 0;
  char name[NAMELENGTH];
  scanf("%s", name);
  while (strcmp(name, "END") != 0) {
    char assignStr[NAMELENGTH];
    Variable *variable =
      &(variableSet->variables[count]);
    strcpy(variable->name, name);
    scanf("%s", assignStr);
    variableSet->varNameTable[count] =
      variable->name;
    assert(strcmp(assignStr, "=") == 0);
    scanf("%d", &(variable->value));
    scanf("%s", name);
    count++;
  }
  variableSet->varNameTable[count] = NULL;
}
/* readvariableend */
#define LINE 200 /* max lines of code */

int main ()
{
  /* get all variables */
  VariableSet variableSet;
  readVariable(&variableSet);

  /* process code */
  Statement statements[LINE];
  processCode(&variableSet, statements);

  /* run code */
  runCode(&variableSet, statements);

  return 0;
}
