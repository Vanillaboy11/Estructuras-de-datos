// Author: Isaac Varela
//  Creacion y evaluacion de arboles binarios de expresiones

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node
{
  char operator;
  int constant;
  struct Node *left, *right;
};

struct tree
{
  struct Node *root;
};

char highestOperator(char *expresion);
void evaluateExpression(char *expresion);

int main()
{
  char *exp = "5 * 6 - 4 + 8 * (3 ^ (4 - 2)) * sqrt(3)";
  printf("Highest precedence operator: %c\n", highestOperator(exp));

  return 0;
}

char highestOperator(char *expression)
{
  char highestPrecedenceOperator = '\0';
  int highestPrecedence = -1, lenght = strlen(expression);
  for (int i = 0; i < lenght; i++)
  {
    char currentChar = expression[i];

    // Check if the current character is an operator
    if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '^')
    {
      int currentPrecedence = 0;

      // Assign precedence values based on operator type
      if (currentChar == '+' || currentChar == '-')
      {
        currentPrecedence = 1;
      }
      else if (currentChar == '*' || currentChar == '/')
      {
        currentPrecedence = 2;
      }
      else if (currentChar == '^')
      {
        currentPrecedence = 3;
      }

      // Update the highest precedence operator if necessary
      if (currentPrecedence > highestPrecedence)
      {
        highestPrecedence = currentPrecedence;
        highestPrecedenceOperator = currentChar;
      }
    }
  }
  return highestPrecedenceOperator;
}

void evaluateExpression(char *expresion)
{
  expresion = "5 * 6 - 4 + 8 * (3 ^ (4 - 2)) * sqrt(3)";
}
