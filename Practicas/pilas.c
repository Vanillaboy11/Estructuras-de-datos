#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Función para liberar la memoria de la pila
void liberarPila(struct Stack *stack)
{
    while (stack->top != NULL)
    {
        pop(stack);
    }
}

// Menu interactivo
void menu()
{
    struct Stack stack;
    int capacidad = 10; // Capacidad por defecto
    initializeStack(&stack);

    while (1)
    {
        printf("\nMenu de opciones:\n");
        printf("1. Crear Pila\n");
        printf("2. Apilar (Push)\n");
        printf("3. Desapilar (Pop)\n");
        printf("4. Verificar si la pila está vacia\n");
        printf("5. Vaciar la pila\n");
        printf("6. Obtener el tamaño de la pila\n");
        printf("7. Imprimir la pila\n");
        printf("8. Salir\n");
        printf("Seleccione una opcion: ");
        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            if (stack.top != NULL)
            {
                liberarPila(&stack);
            }
            printf("Ingrese la capacidad de la pila: ");
            scanf("%d", &capacidad);
            printf("Pila creada con capacidad %d.\n", capacidad);
            break;

        case 2:
            if (stack.top == NULL)
            {
                printf("Primero debe crear una pila.\n");
            }
            else
            {
                int item;
                printf("Ingrese el valor a apilar: ");
                scanf("%d", &item);
                push(&stack, item);
            }
            break;

        case 3:
            if (stack.top == NULL)
            {
                printf("Primero debe crear una pila.\n");
            }
            else
            {
                int item = pop(&stack);
                if (item != -1)
                {
                    printf("Valor %d desapilado.\n", item);
                }
            }
            break;

        case 4:
            if (stack.top == NULL)
            {
                printf("Primero debe crear una pila.\n");
            }
            else
            {
                if (isEmpty(&stack))
                {
                    printf("La pila está vacía.\n");
                }
                else
                {
                    printf("La pila no está vacía.\n");
                }
            }
            break;

        case 5:
            if (stack.top == NULL)
            {
                printf("Primero debe crear una pila.\n");
            }
            else
            {
                liberarPila(&stack);
                printf("Pila vaciada.\n");
            }
            break;

        case 6:
            if (stack.top == NULL)
            {
                printf("Primero debe crear una pila.\n");
            }
            else
            {
                printf("Tamaño de la pila: %d\n", count(&stack));
            }
            break;

        case 7:
            if (stack.top == NULL)
            {
                printf("Primero debe crear una pila.\n");
            }
            else
            {
                printf("Pila: ");
                struct Node *temp = stack.top;
                while (temp != NULL)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
            break;

        case 8:
            printf("Saliendo...\n");
            if (stack.top != NULL)
            {
                liberarPila(&stack);
            }
            return;

        default:
            printf("Opción no válida. Por favor, intente de nuevo.\n");
            break;
        }
    }
}

// Función principal
int main()
{
    menu();
    return 0;
}
