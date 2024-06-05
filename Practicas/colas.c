#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definicion de la estructura de un nodo de la cola
struct Node
{
    int data;
    struct Node *next;
};

// Funcion para crear un nuevo nodo
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Definicion de la estructura de la cola
struct Queue
{
    struct Node *front;
    struct Node *rear;
    int size;
};

// Funcion para inicializar la cola
void initializeQueue(struct Queue *queue)
{
    queue->front = queue->rear = NULL;
    queue->size = 0;
}

// Funcion para insertar elementos al final de la cola (enqueue)
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    queue->size++;
}

// Funcion para eliminar elementos del frente de la cola (dequeue)
int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Error: La cola esta vacia.\n");
        return -1;
    }
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    free(temp);
    queue->size--;
    return data;
}

// Funcion para obtener el elemento en el frente de la cola sin eliminarlo (front)
int front(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Error: La cola esta vacia.\n");
        return -1;
    }
    return queue->front->data;
}

// Funcion para verificar si la cola esta vacia (isEmpty)
bool isEmpty(struct Queue *queue)
{
    return queue->front == NULL;
}

// Funcion para obtener el tamaño de la cola (size)
int size(struct Queue *queue)
{
    return queue->size;
}

// Funcion para vaciar la cola (clear)
void clear(struct Queue *queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
}

// Funcion para mostrar el menu interactivo
void menu()
{
    struct Queue queue;
    initializeQueue(&queue);

    while (1)
    {
        printf("\nMenu de opciones:\n");
        printf("1. Insertar elemento al final de la cola (enqueue)\n");
        printf("2. Eliminar elemento del frente de la cola (dequeue)\n");
        printf("3. Obtener elemento en el frente de la cola (front)\n");
        printf("4. Verificar si la cola esta vacia (isEmpty)\n");
        printf("5. Obtener el tamano de la cola (size)\n");
        printf("6. Vaciar la cola (clear)\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int valor;
            printf("Ingrese el valor a insertar en la cola: ");
            scanf("%d", &valor);
            enqueue(&queue, valor);
            printf("Elemento %d insertado en la cola.\n", valor);
        }
        break;
        case 2:
        {
            int valor = dequeue(&queue);
            if (valor != -1)
            {
                printf("Elemento %d eliminado del frente de la cola.\n", valor);
            }
        }
        break;
        case 3:
        {
            int valor = front(&queue);
            if (valor != -1)
            {
                printf("Elemento en el frente de la cola: %d\n", valor);
            }
        }
        break;
        case 4:
            if (isEmpty(&queue))
            {
                printf("La cola esta vacia.\n");
            }
            else
            {
                printf("La cola no esta vacia.\n");
            }
            break;
        case 5:
            printf("Tamano de la cola: %d\n", size(&queue));
            break;
        case 6:
            clear(&queue);
            printf("La cola ha sido vaciada.\n");
            break;
        case 7:
            printf("Saliendo...\n");
            return;
        default:
            printf("Opcion no valida. Por favor, intente de nuevo.\n");
            break;
        }
    }
}

// Funcion principal
int main()
{
    menu();
    return 0;
}
