#include <stdio.h>

typedef struct Node
{
  int matri;
  char ln_f[50];
  char ln_m[50];
  char name[100];
  int carrera;
  struct Node *next;
} Node;

Node *createNode(int matri, const char *ln_f, const char *ln_m, const char *name)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Error: No se pudo asignar memoria para el nuevo nodo.\n");
  }
  newNode->matri = matri;
  strcpy(newNode->ln_f, ln_f);
  strcpy(newNode->ln_m, ln_m);
  strcpy(newNode->name, name);
  newNode->next = NULL;
  return newNode;
}

void insertAtBeginning(Node **head, int matri, const char *ln_f, const char *ln_m, const char *name)
{
  Node *newNode = createNode(matri, ln_f, ln_m, name);
  newNode->next = *head;
  *head = newNode;
}

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

void printList(Node *head)
{
  Node *current = head;
  printf("Lista de estudiantes:\n");
  while (current != NULL)
  {
    printf("Matricula: %d, Apellido Paterno: %s, Apellido Materno: %s, Nombre: %s\n", current->matri, current->ln_f, current->ln_m, current->name);
    current = current->next;
  }
}

int main()
{
  Node *list = NULL;

  char respuesta;
  int matri;
  char ln_f[50], ln_m[50], name[100];

  do
  {
    printf("Ingrese la matricula del estudiante: ");
    scanf("%d", &matri);
    printf("Ingrese el apellido paterno del estudiante: ");
    scanf("%s", ln_f);
    printf("Ingrese el apellido materno del estudiante: ");
    scanf("%s", ln_m);
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", name);

    insertAtEnd(&list, matri, ln_f, ln_m, name);

    printf("Desea ingresar otro estudiante? (s/n): ");
    scanf(" %c", &respuesta);
  } while (respuesta == 's' || respuesta == 'S');

  printList(list);

  return 0;
}
