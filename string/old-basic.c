#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAXLINE 100
#define MAXN 32
#define MAXV 100

#define STOP 0
#define GOTO 1
#define IF 2
#define COMPUTATION 3
#define ASSIGNMENT 4
#define PRINT 5

int gotoLine(int LineNumber, int lineNumbers[], 
	     int totalLines)
{
  int i;
  for (i = 0; i < totalLines; i++)
    if (LineNumber == lineNumbers[i])
      return i;
  exit(-1);
}

int *accessAddress(char operand[], int *variableSeen, 
		   char variableName[MAXV][MAXN], 
		   int variableValue[])
{
  int i;
  for (i = 0; i < (*variableSeen); i++)
    if (strcmp(operand, variableName[i]) == 0) 
      break;

  if (i < (*variableSeen))
    return &(variableValue[i]);
  else {
    int *address = &(variableValue[*variableSeen]);
    strcpy(variableName[*variableSeen], operand);
    (*variableSeen)++;
    return address;
  }
}

int accessValue(char operand[], int *variableSeen, 
		char variableName[MAXV][MAXN], 
		int variableValue[])
{
  if (isalpha(operand[0]))
    return(*(accessAddress(operand, variableSeen, 
			   variableName, variableValue)));
  else
    return(atoi(operand));
}

int main()
{
  int programLine = 0;
  int totalLines;
  int lineNumbers[MAXLINE];
  int code[MAXLINE];
  int gotoDestination[MAXLINE];
  char variable[MAXLINE][MAXN];
  char operand1[MAXLINE][MAXN];
  char operators[MAXLINE][MAXN];
  char operand2[MAXLINE][MAXN];
  char assignString[MAXN];
  char gotoString[MAXN];
  char variableName[MAXV][MAXN];
  int variableValue[MAXV];
  int variableSeen = 0;
  int stop;

  int currentLine = 0;
  int lineNumber;
  char operator;
  char codeString[MAXN];
  char c;

  int result;
  int operand1Value;
  int operand2Value;
  char *operatorPtr;

  int value, *address;

  while (scanf("%d", &lineNumber) == 1) {
    currentLine = programLine;
    scanf("%s", codeString);
    lineNumbers[currentLine] = lineNumber; 

    if (strcmp(codeString, "STOP") == 0)
      code[currentLine] = STOP;
    else if (strcmp(codeString, "GOTO") == 0) {		
      code[currentLine] = GOTO;
      scanf("%d", &(gotoDestination[currentLine]));
    } else if (strcmp(codeString, "PRINT") == 0) {
      code[currentLine] = PRINT;
      scanf("%s", variable[currentLine]);
    } else if (strcmp(codeString, "IF") == 0) {
      code[currentLine] = IF;
      scanf("%s%s%s%s", operand1[currentLine], 
	    operators[currentLine], 
	    operand2[currentLine], gotoString);
      scanf("%d", &(gotoDestination[currentLine]));
    }
    else {			/* variable */
      strcpy(variable[currentLine], codeString);
      scanf("%s%s", assignString, 
	    operand1[currentLine]);
      assert(strcmp(assignString, "=") == 0);
      do {
	scanf("%c", &operator);
      } while (operator == ' ');
      if (operator == '\n' || operator == '\r')
	code[currentLine] = ASSIGNMENT;	       
      else {
	code[currentLine] = COMPUTATION;
	operators[currentLine][0] = operator;
	operators[currentLine][1] = '\0';
	scanf("%s", operand2[currentLine]);
      }
    }
    programLine++;
  }
  
  totalLines = programLine;
  stop = 0;
  programLine = 0;
  while (!stop) {
    switch (code[programLine]) {
    case STOP:
      stop = 1;
      break;
    case PRINT:
      printf("%d\n", 
	     accessValue(variable[programLine], 
			 &variableSeen, 
			 variableName, 
			 variableValue));
      programLine++;
      break;
    case GOTO:
      programLine = 
	gotoLine(gotoDestination[programLine],
		 lineNumbers, totalLines);
      break;
    case ASSIGNMENT:
      address = 
	accessAddress(variable[programLine], 
		      &variableSeen, variableName, 
		      variableValue);
      value = 
	accessValue(operand1[programLine], 
		    &variableSeen, variableName, 
		    variableValue);
      *address = value;
      programLine++;
      break;
    case COMPUTATION:
      operand1Value = 
	accessValue(operand1[programLine], 
		    &variableSeen, variableName, 
		    variableValue);
      operand2Value = 
	accessValue(operand2[programLine], 
		    &variableSeen, variableName, 
		    variableValue);
      operatorPtr = operators[programLine];
      if (strcmp(operatorPtr, "+") == 0)
	result = operand1Value + operand2Value;
      else if (strcmp(operatorPtr, "-") == 0)
	result = operand1Value - operand2Value;
      else if (strcmp(operatorPtr, "*") == 0)
	result = operand1Value * operand2Value;
      else if (strcmp(operatorPtr, "/") == 0)
	result = operand1Value / operand2Value;
      else if (strcmp(operatorPtr, "%") == 0)
	result = operand1Value % operand2Value;
      else
	exit(-1);

      *(accessAddress(variable[programLine], 
		      &variableSeen, variableName, 
		      variableValue)) 
	= result;
      programLine++;
      break;
    case IF:
      operand1Value = 
	accessValue(operand1[programLine], 
		    &variableSeen, variableName, 
		    variableValue);
      operand2Value = 
	accessValue(operand2[programLine], 
		    &variableSeen,variableName, 
		    variableValue);
      operatorPtr = operators[programLine];
      if (strcmp(operatorPtr, "==") == 0)
	result = operand1Value == operand2Value;
      else if (strcmp(operatorPtr, "!=") == 0)
	result = operand1Value != operand2Value;
      else if (strcmp(operatorPtr, ">") == 0)
	result = operand1Value > operand2Value;
      else if (strcmp(operatorPtr, "<") == 0)
	result = operand1Value < operand2Value;
      else if (strcmp(operatorPtr, ">=") == 0)
	result = operand1Value >= operand2Value;
      else if (strcmp(operatorPtr, "<=") == 0)
	result = operand1Value <= operand2Value;
      else
	exit(-1);
      if (result)
	programLine = 
	  gotoLine(gotoDestination[programLine], 
		   lineNumbers, totalLines);
      else
	programLine++;
      break;
    default:
      exit(-1);
    }
  }
  return 0;
}


