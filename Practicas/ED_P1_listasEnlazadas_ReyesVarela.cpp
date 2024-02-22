  // AUTOR: REYES VARELA SALVADOR ISAAC       MATRICULA:  372917
// 6/FEBRERO/2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicion de la estructura de un nodo
typedef struct Node
{
  int matri;
  char ln_f[50];
  char ln_m[50];
  char name[100];
  int carrera;
  struct Node *next;
} Node;

// Funcion de creacion del nodo
Node *createNode(int matri, const char *ln_f, const char *ln_m, const char *name)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
    exit(EXIT_FAILURE);
  }
  newNode->matri = matri;
  strcpy(newNode->ln_f, ln_f);
  strcpy(newNode->ln_m, ln_m);
  strcpy(newNode->name, name);
  newNode->next = NULL;
  return newNode;
}

/*    PROTOTIPOS DE FUNCION     */
void insertAtEnd(Node **head, int matri, const char *ln_f, const char *ln_m, const char *name);
void insertAtPosition(Node **head, int matri, const char *ln_f, const char *ln_m, const char *name, int position);
void deleteFirstNode(Node **head);
void deleteList(Node **head);
Node *searchElement(Node *head, int matri);
void printList(Node *head);
int isEmpty(Node *head);
int countElements(Node *head);
int compare(const void *a, const void *b);
void sortList(Node **head);

/*    FUNCION PRINCIPAL   */
int main()
{
  Node *list = NULL;

  insertAtEnd(&list, 372917, "Reyes", "Varela", "Isaac");
  insertAtEnd(&list, 371217, "Reyes", "Munoz", "Efrain");
  insertAtEnd(&list, 372922, "Salazar", "Beltran", "Pablo");
  insertAtEnd(&list, 372815, "Rabago", "Garcia", "Daniel");

  printf("Lista original:\n");
  printList(list);

  printf("Eliminando el primer elemento...\n");
  deleteFirstNode(&list);
  printf("Lista despues de eliminar el primer elemento:\n");
  printList(list);

  printf("Buscando el elemento con matricula 34567...\n");
  Node *found = searchElement(list, 371512);
  if (found != NULL)
  {
    printf("Elemento encontrado: Matricula: %d, Apellido Paterno: %s, Apellido Materno: %s, nombre: %s\n", found->matri, found->ln_f, found->ln_m, found->name);
  }
  else
  {
    printf("Elemento no encontrado.\n");
  } 

  printf("La lista esta vacia? %s\n", isEmpty(list) ? "Si" : "No");

  printf("Cantidad de elementos en la lista: %d\n", countElements(list));

  printf("Eliminando toda la lista...\n");
  deleteList(&list);
  printf("Lista despues de eliminarla:\n");
  printList(list);

  return 0;
}


/*    FUNCIONES     */
void insertAtEnd(Node **head, int matri, const char *ln_f, const char *ln_m, const char *name)
{
  Node *newNode = createNode(matri, ln_f, ln_m, name);
  if (*head == NULL)
  {
    *head = newNode;
  }
  else
  {
    Node *current = *head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
  }
}

void insertAtPosition(Node **head, int matri, const char *ln_f, const char *ln_m, const char *name, int position)
{
  if (position < 0)
  {
    printf("Error: La posicion debe ser un valor no negativo.\n");
    return;
  }
  if (position == 0)
  {
    Node *newNode = createNode(matri, ln_f, ln_m, name);
    newNode->next = *head;
    *head = newNode;
    return;
  }
  Node *current = *head;
  int counter = 0;
  while (current != NULL && counter < position - 1)
  {
    current = current->next;
    counter++;
  }
  if (current == NULL)
  {
    printf("Error: La posicion excede la longitud de la lista.\n");
    return;
  }
  Node *newNode = createNode(matri, ln_f, ln_m, name);
  newNode->next = current->next;
  current->next = newNode;
}

void deleteFirstNode(Node **head)
{
  if (*head == NULL)
  {
    printf("La lista esta vacia.\n");
    return;
  }
  Node *temp = *head;
  *head = (*head)->next;
  free(temp);
}

void deleteList(Node **head)
{
  while (*head != NULL)
  {
    deleteFirstNode(head);
  }
}

Node *searchElement(Node *head, int matri)
{
  Node *current = head;
  while (current != NULL)
  {
    if (current->matri == matri)
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void printList(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    printf("matri: %d, Apellido Paterno: %s, Apellido Materno: %s, nombre: %s\n", current->matri, current->ln_f, current->ln_m, current->name);
    current = current->next;
  }
}

int isEmpty(Node *head)
{
  return head == NULL;
}

int countElements(Node *head)
{
  int counter = 0;
  Node *current = head;
  while (current != NULL)
  {
    counter++;
    current = current->next;
  }
  return counter;
}

int compare(const void *a, const void *b)
{
  return (*(int *)a - *(int *)b);
}

void sortList(Node **head)
{
  int n = countElements(*head);
  if (n <= 1)
  {
    return;
  }

  Node *temp;
  int swapped;
  do
  {
    swapped = 0;
    Node *ptr1 = *head;
    Node *ptr2 = ptr1->next;

    while (ptr2 != NULL)
    {
      if (ptr1->matri > ptr2->matri)
      {
        // Intercambiar los nodos
        if (ptr1 == *head)
        {
          *head = ptr2;
        }
        else
        {
          temp->next = ptr2;
        }
        temp = ptr2->next;
        ptr2->next = ptr1;
        ptr1->next = temp;
        swapped = 1;
      }
      else
      {
        temp = ptr1;
        ptr1 = ptr1->next;
      }
      ptr2 = ptr1->next;
    }
  } while (swapped);
}
