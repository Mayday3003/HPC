#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;
} Nodo;

// Función para crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria\n");
        exit(1);
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;
    return nuevoNodo;
}

// Función para mostrar el nodo 
void mostrarNodo(Nodo* nodo) {
    if (nodo != NULL) {
        printf("Valor: %d\n", nodo->dato);
    } else {
        printf("Nodo nulo\n");
    }
}