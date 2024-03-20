// Autor: Salvador Isaac Reyes Varela   372917
// Fecha de creacion: 08/MARZO/2024

#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int input;
  struct Node *next;
};

struct Node *newNode(int data)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->input = data;
  node->next = NULL;
  return node;
}

struct Stack
{
  struct Node *head;
  int size;
};

void initializeStack(struct Stack *stack)
{
  stack->head = NULL;
  stack->size = 0;
}

int isEmpty(struct Stack *stack)
{
  return stack->head == NULL;
}

void push(struct Stack *stack, int data)
{
  struct Node *node = newNode(data);
  node->next = stack->head;
  stack->head = node;
  stack->size++;
}

int popear(struct Stack *stack)
{
  if (isEmpty(stack))
  {
    printf("Error: La pila está vacía.\n");
    return -1;
  }
  struct Node *temp = stack->head;
  int data = temp->input;
  stack->head = temp->next;
  free(temp);
  stack->size--;
  return data;
}

void printStack(struct Stack *stack)
{
  struct Node *temp = stack->head;
  while (temp != NULL)
  {
    printf("%d -> ", temp->input);
    temp = temp->next;
  }
  printf("NULL\n");
}

int main()
{
  struct Stack stack;
  initializeStack(&stack);
  push(&stack, 10);
  push(&stack, 40);
  push(&stack, 500);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);
  push(&stack, 110);

  printStack(&stack);
  printf("\n");

  popear(&stack);
  popear(&stack);
  popear(&stack);
  popear(&stack);
  popear(&stack);
  popear(&stack);
  popear(&stack);
  popear(&stack);
  printStack(&stack);

  return 0;
}