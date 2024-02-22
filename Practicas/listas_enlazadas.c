#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
    char Matricula[20];
    char A_Paterno[50];
    char A_Materno[50];
    char Nombre[50];
    int carrera;
} Alumno;

typedef struct Nodo {
    Alumno alumno;
    struct Nodo *siguiente;
} Nodo;

typedef struct Lista {
    Nodo *Cabeza;
} Lista;

Nodo *crearNodo(Alumno *alumno) {
    Nodo *nodo = (Nodo *)malloc(sizeof(Nodo));
    strcpy(nodo->alumno.Matricula, alumno->Matricula);
    strcpy(nodo->alumno.A_Paterno, alumno->A_Paterno);
    strcpy(nodo->alumno.A_Materno, alumno->A_Materno);
    strcpy(nodo->alumno.Nombre, alumno->Nombre);
    nodo->alumno.carrera = alumno->carrera;
    nodo->siguiente = NULL;
    return nodo;
}

void liberarNodo(Nodo *nodo) {
    free(nodo);
}

void insertarAlPrincipio(Lista *lista, Alumno *alumno) {
    Nodo *nodo = crearNodo(alumno);
    nodo->siguiente = lista->Cabeza;
    lista->Cabeza = nodo;
}

void insertarAlFinal(Lista *lista, Alumno *alumno) {
    Nodo *nodo = crearNodo(alumno);
    if (lista->Cabeza == NULL) {
        lista->Cabeza = nodo;
    } else {
        Nodo *puntero = lista->Cabeza;
        while (puntero->siguiente) {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
}

void insertarEspecifico(Lista *lista, Alumno *alumno, int n) {
    Nodo *nodo = crearNodo(alumno);
    if (lista->Cabeza == NULL) {
        lista->Cabeza = nodo;
    } else {
        Nodo *puntero = lista->Cabeza;
        int posicion = 0;
        while (posicion < n && puntero->siguiente) {
            puntero = puntero->siguiente;
            posicion++;
        }
        nodo->siguiente = puntero->siguiente;
        puntero->siguiente = nodo;
    }
}

void printList(Lista *lista) {
    Nodo *puntero = lista->Cabeza;
    while (puntero != NULL) {
        printf("Matricula: %s, Apellido Paterno: %s, Apellido Materno: %s, Nombre: %s, Carrera: %d\n",
               puntero->alumno.Matricula, puntero->alumno.A_Paterno,
               puntero->alumno.A_Materno, puntero->alumno.Nombre, puntero->alumno.carrera);
        puntero = puntero->siguiente;
    }
}

int main() {
    Lista list;
    list.Cabeza = NULL;

    int choice;
    Alumno alumno;
    int posicion;

    do {
        printf("\nMenu:\n");
        printf("1. Insertar al principio\n");
        printf("2. Insertar al final\n");
        printf("3. Insertar en posicion especifica\n");
        printf("4. Imprimir lista\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese los datos del alumno:\n");
                printf("Matricula: ");
                scanf("%s", alumno.Matricula);
                printf("Apellido Paterno: ");
                scanf("%s", alumno.A_Paterno);
                printf("Apellido Materno: ");
                scanf("%s", alumno.A_Materno);
                printf("Nombre: ");
                scanf("%s", alumno.Nombre);
                printf("Carrera: ");
                scanf("%d", &alumno.carrera);
                insertarAlPrincipio(&list, &alumno);
                break;
            case 2:
                printf("Ingrese los datos del alumno:\n");
                printf("Matricula: ");
                scanf("%s", alumno.Matricula);
                printf("Apellido Paterno: ");
                scanf("%s", alumno.A_Paterno);
                printf("Apellido Materno: ");
                scanf("%s", alumno.A_Materno);
                printf("Nombre: ");
                scanf("%s", alumno.Nombre);
                printf("Carrera: ");
                scanf("%d", &alumno.carrera);
                insertarAlFinal(&list, &alumno);
                break;
            case 3:
                printf("Ingrese los datos del alumno:\n");
                printf("Matricula: ");
                scanf("%s", alumno.Matricula);
                printf("Apellido Paterno: ");
                scanf("%s", alumno.A_Paterno);
                printf("Apellido Materno: ");
                scanf("%s", alumno.A_Materno);
                printf("Nombre: ");
                scanf("%s", alumno.Nombre);
                printf("Carrera: ");
                scanf("%d", &alumno.carrera);
                printf("Ingrese la posicion de insercion: ");
                scanf("%d", &posicion);
                insertarEspecifico(&list, &alumno, posicion);
                break;
            case 4:
                printf("Lista:\n");
                printList(&list);
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion no valida. Por favor, seleccione nuevamente.\n");
        }
    } while (choice != 5);

    return 0;
}
