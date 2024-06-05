#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definicion de la estructura de un nodo del arbol
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Funcion para crear un nuevo nodo
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Funcion para insertar un nodo en el arbol
struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return newNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Funcion para buscar un nodo en el arbol
bool searchNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == data)
    {
        return true;
    }
    if (data < root->data)
    {
        return searchNode(root->left, data);
    }
    else
    {
        return searchNode(root->right, data);
    }
}

// Funcion para eliminar un nodo del arbol
struct Node *deleteNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Funcion para encontrar el nodo con el valor minimo en un subarbol
struct Node *minValueNode(struct Node *node)
{
    struct Node *current = node;
    while (current && current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Funcion para recorrer el arbol en orden
void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Funcion para recorrer el arbol en preorden
void preorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Funcion para recorrer el arbol en postorden
void postorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Funcion para obtener la altura del arbol
int getHeight(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
}

// Funcion para obtener el numero de nodos en el arbol
int getNodeCount(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getNodeCount(root->left) + getNodeCount(root->right) + 1;
}

// Funcion para verificar si el arbol esta completo
bool isComplete(struct Node *root, int index, int nodeCount)
{
    if (root == NULL)
    {
        return true;
    }
    if (index >= nodeCount)
    {
        return false;
    }
    return (isComplete(root->left, 2 * index + 1, nodeCount) && isComplete(root->right, 2 * index + 2, nodeCount));
}

// Funcion para verificar si el arbol esta balanceado
bool isBalanced(struct Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}

// Funcion para liberar la memoria asignada al arbol
void freeTree(struct Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

// Funcion para mostrar el menu interactivo
void menu()
{
    struct Node *root = NULL;

    while (1)
    {
        printf("\nMenu de opciones:\n");
        printf("1. Insercion de nodos\n");
        printf("2. Busqueda de un nodo especifico\n");
        printf("3. Eliminacion de nodos\n");
        printf("4. Recorrido del arbol\n");
        printf("5. Obtencion de informacion del arbol\n");
        printf("6. Modificacion de nodos\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");

        int opcion;
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
        {
            int valor;
            printf("Ingrese el valor a insertar en el arbol: ");
            scanf("%d", &valor);
            root = insertNode(root, valor);
            printf("Nodo %d insertado en el arbol.\n", valor);
        }
        break;
        case 2:
        {
            int valor;
            printf("Ingrese el valor a buscar en el arbol: ");
            scanf("%d", &valor);
            if (searchNode(root, valor))
            {
                printf("El nodo %d esta presente en el arbol.\n", valor);
            }
            else
            {
                printf("El nodo %d no esta presente en el arbol.\n", valor);
            }
        }
        break;
        case 3:
        {
            int valor;
            printf("Ingrese el valor del nodo a eliminar: ");
            scanf("%d", &valor);
            root = deleteNode(root, valor);
            printf("Nodo %d eliminado del arbol.\n", valor);
        }
        break;
        case 4:
        {
            printf("Recorrido en orden del arbol: ");
            inorderTraversal(root);
            printf("\nRecorrido en preorden del arbol: ");
            preorderTraversal(root);
            printf("\nRecorrido en postorden del arbol: ");
            postorderTraversal(root);
            printf("\n");
        }
        break;
        case 5:
        {
            printf("Altura del arbol: %d\n", getHeight(root));
            printf("Numero de nodos en el arbol: %d\n", getNodeCount(root));
            if (isComplete(root, 0, getNodeCount(root)))
            {
                printf("El arbol esta completo.\n");
            }
            else
            {
                printf("El arbol no esta completo.\n");
            }
            if (isBalanced(root))
            {
                printf("El arbol esta balanceado.\n");
            }
            else
            {
                printf("El arbol no esta balanceado.\n");
            }
        }
        break;
        case 6:
            // Aqui puedes implementar la modificacion de nodos si lo deseas
            printf("La modificacion de nodos aun no esta implementada.\n");
            break;
        case 7:
            printf("Saliendo...\n");
            freeTree(root);
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
