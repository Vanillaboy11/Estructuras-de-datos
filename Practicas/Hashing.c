#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para un elemento de la tabla hash
typedef struct Elemento
{
    int clave;
    char *valor;
    struct Elemento *siguiente;
} Elemento;

// Estructura para la tabla hash
typedef struct TablaHash
{
    int tamano;
    Elemento **tabla;
} TablaHash;

// Función de hashing simple
int funcionHash(int clave)
{
    // Tamaño de la tabla hash, preferiblemente un número primo
    const int tamanoTabla = 101;
    return clave % tamanoTabla;
}

// Función para crear una nueva tabla hash
TablaHash *crear_tabla(int tamano)
{
    TablaHash *tabla = (TablaHash *)malloc(sizeof(TablaHash));
    tabla->tamano = tamano;
    tabla->tabla = (Elemento **)calloc(tamano, sizeof(Elemento *));
    return tabla;
}

// Función para insertar un elemento en la tabla hash
void insertar_elemento(TablaHash *tabla, int clave, char *valor)
{
    int indice = funcion_hash(clave, tabla->tamano);

    Elemento *nuevo_elemento = (Elemento *)malloc(sizeof(Elemento));
    nuevo_elemento->clave = clave;
    nuevo_elemento->valor = strdup(valor); // Duplicamos el valor para evitar problemas de memoria
    nuevo_elemento->siguiente = tabla->tabla[indice];
    tabla->tabla[indice] = nuevo_elemento;
}

// Función para buscar un elemento en la tabla hash
char *buscar_elemento(TablaHash *tabla, int clave)
{
    int indice = funcion_hash(clave, tabla->tamano);
    Elemento *actual = tabla->tabla[indice];
    while (actual != NULL)
    {
        if (actual->clave == clave)
        {
            return actual->valor;
        }
        actual = actual->siguiente;
    }
    return NULL; // Elemento no encontrado
}

// Función para eliminar un elemento de la tabla hash
void eliminar_elemento(TablaHash *tabla, int clave)
{
    int indice = funcion_hash(clave, tabla->tamano);
    Elemento *actual = tabla->tabla[indice];
    Elemento *anterior = NULL;
    while (actual != NULL)
    {
        if (actual->clave == clave)
        {
            if (anterior == NULL)
            {
                tabla->tabla[indice] = actual->siguiente;
            }
            else
            {
                anterior->siguiente = actual->siguiente;
            }
            free(actual->valor);
            free(actual);
            return;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
}

// Función para liberar la memoria de la tabla hash
void liberar_tabla(TablaHash *tabla)
{
    for (int i = 0; i < tabla->tamano; i++)
    {
        Elemento *actual = tabla->tabla[i];
        while (actual != NULL)
        {
            Elemento *siguiente = actual->siguiente;
            free(actual->valor);
            free(actual);
            actual = siguiente;
        }
    }
    free(tabla->tabla);
    free(tabla);
}

// Función principal para probar el código
int main()
{
    TablaHash *tabla = crear_tabla(10);
    int opcion, clave;
    char valor[100];

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insertar un nuevo elemento\n");
        printf("2. Buscar un elemento\n");
        printf("3. Eliminar un elemento\n");
        printf("4. Salir\n");
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese la clave del elemento: ");
            scanf("%d", &clave);
            printf("Ingrese el valor del elemento: ");
            scanf("%s", valor);
            insertar_elemento(tabla, clave, valor);
            break;
        case 2:
            printf("Ingrese la clave del elemento a buscar: ");
            scanf("%d", &clave);
            char *resultado = buscar_elemento(tabla, clave);
            if (resultado != NULL)
            {
                printf("Valor encontrado: %s\n", resultado);
            }
            else
            {
                printf("La clave no existe en la tabla.\n");
            }
            break;
        case 3:
            printf("Ingrese la clave del elemento a eliminar: ");
            scanf("%d", &clave);
            eliminar_elemento(tabla, clave);
            break;
        case 4:
            liberar_tabla(tabla);
            printf("Saliendo del programa...\n");
            exit(0);
        default:
            printf("Opcion no valida. Por favor, ingrese un numero del 1 al 4.\n");
            break;
        }
    }

    return 0;
}
