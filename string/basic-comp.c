#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int allDigits(char string[])
{
  for (int i = 0; i < strlen(string); i++)
    if (!isdigit(string[i]))
      return 0;
  return 1;
}

int variableName2index(char name[80], char names[][80], 
		       int number)
{
  for (int i = 0; i < number; i++)
    if (strcmp(name, names[i]) == 0)
      return i;
  return -1;
}

int token2Value(char token[], char names[][80], int values[], int number)
{
  if (allDigits(token))
    return atoi(token);
  else {
    int index = variableName2index(token, names, number);
    return values[index];
  }
}

int token2Op(char token[])
{
  if (strcmp(token, "+") == 0)
    return 1;
  else if (strcmp(token, "-") == 0)
    return 2;
  else if (strcmp(token, "*") == 0)
    return 3;
  else if (strcmp(token, "/") == 0)
    return 4;
  else if (strcmp(token, "%") == 0)
    return 5;
  else
    return -1;
}

int compute(int operand1, int operand2, int op)
{
  switch (op) {
  case 1:
    return operand1 + operand2;
  case 2:
    return operand1 - operand2;
  case 3:
    return operand1 * operand2;
  case 4:
    return operand1 / operand2;
  case 5:
    return operand1 % operand2;
  default:
    exit(-1);
  }
}

int getLine(char line[])
{
  char c;
  int length = 0;
  while (scanf("%c", &c) != EOF && c != '\n') {
    line[length] = c;
    length++;
  }
  line[length] = '\0';
  return length;
}

int main()
{
  char line[80];
  char variableNames[100][80];
  int variableValues[100];
  int numVariables = 0;
  char *token;

  while (getLine(line) > 0) {

    int index;
    int operand1Value, operand2Value;

    token = strtok(line, " ");
    
    if (strcmp(token, "print") == 0) {
      token = strtok(NULL, " ");
      index = variableName2index(token, variableNames, numVariables);
      printf("%d\n", variableValues[index]);
    } else {			/* assignment */
      index = variableName2index(token, variableNames, numVariables);
      if (index == -1) {
	strcpy(variableNames[numVariables], token);
	index = numVariables;
	numVariables++;
      }
	
      token = strtok(NULL, " "); /* get the = */
      token = strtok(NULL, " "); /* get operand1 */
      operand1Value = 
	token2Value(token, variableNames, variableValues, numVariables);

      token = strtok(NULL, " "); /* get operator */
      if (token == NULL) 
	variableValues[index] = operand1Value;
      else {
	int operator = token2Op(token);
	token = strtok(NULL, " "); /* get operand2 */
	operand2Value = 
	  token2Value(token, variableNames, variableValues, numVariables);

	variableValues[index] =
	  compute(operand1Value, operand2Value, operator);
      }

    }
  }
}
