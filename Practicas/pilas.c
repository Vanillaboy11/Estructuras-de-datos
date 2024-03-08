#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura de un nodo de la pila
struct Node
{
    int data;
    struct Node *next;
};

// Función para crear un nuevo nodo
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Estructura de la pila
struct Stack
{
    struct Node *top;
    int size;
};

// Función para inicializar la pila
void initializeStack(struct Stack *stack)
{
    stack->top = NULL;
    stack->size = 0;
}   

// Función para verificar si la pila está vacía
int isEmpty(struct Stack *stack)
{
    return stack->top == NULL;
}

// Función para hacer push en la pila
void push(struct Stack *stack, int data)
{
    struct Node *node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

// Función para hacer pop de la pila
int pop(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
    struct Node *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return data;
}

// Función para obtener el elemento superior (peek)
int peek(struct Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Error: La pila está vacía.\n");
        return -1;
    }
    return stack->top->data;
}

// Función para contar los elementos de la pila
int count(struct Stack *stack)
{
    return stack->size;
}

int main()
{
    struct Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemento superior de la pila: %d\n", peek(&stack));
    printf("Conteo de elementos de la pila: %d\n", count(&stack));

    printf("Elemento extraído de la pila: %d\n", pop(&stack));
    printf("Conteo de elementos de la pila después de pop: %d\n", count(&stack));

    return 0;
}
