#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura del nodo
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para insertar un nodo al final de la lista
void insertarFinal(struct Nodo** cabeza, int valor) {
    // Crear un nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía, el nuevo nodo es la cabeza
    if (*cabeza == NULL) {
        *cabeza = nuevoNodo;
    } else {
        // Recorrer hasta el último nodo
        struct Nodo* temp = *cabeza;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        // Enlazar el nuevo nodo al final
        temp->siguiente = nuevoNodo;
    }
}

// Función para mostrar la lista
void mostrarLista(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía\n");
    } else {
        struct Nodo* temp = cabeza;
        while (temp != NULL) {
            printf("%d -> ", temp->dato);
            temp = temp->siguiente;
        }
        printf("NULL\n");
    }
}

// Función para eliminar un nodo dado su valor
void eliminarNodo(struct Nodo** cabeza, int valor) {
    if (*cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }

    // Si el nodo a eliminar es el primero
    if ((*cabeza)->dato == valor) {
        struct Nodo* temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
        return;
    }

    // Buscar el nodo a eliminar
    struct Nodo* temp = *cabeza;
    while (temp->siguiente != NULL && temp->siguiente->dato != valor) {
        temp = temp->siguiente;
    }

    // Si no se encontró el valor
    if (temp->siguiente == NULL) {
        printf("Valor no encontrado\n");
    } else {
        // Eliminar el nodo
        struct Nodo* nodoAEliminar = temp->siguiente;
        temp->siguiente = temp->siguiente->siguiente;
        free(nodoAEliminar);
    }
}

int main() {

    //Ejemplo de uso

    // Crear la cabeza de la lista
    struct Nodo* cabeza = NULL;

    // Insertar elementos al final
    insertarFinal(&cabeza, 5);
    insertarFinal(&cabeza, 10);
    insertarFinal(&cabeza, 15);

    // Mostrar la lista
    printf("Lista después de inserciones:\n");
    mostrarLista(cabeza);

    // Eliminar un nodo
    printf("\nEliminando el valor 10:\n");
    eliminarNodo(&cabeza, 10);
    mostrarLista(cabeza);

    // Intentar eliminar un valor que no existe
    printf("\nIntentando eliminar el valor 20:\n");
    eliminarNodo(&cabeza, 20);

    // Mostrar la lista final
    printf("\nLista final:\n");
    mostrarLista(cabeza);

    return 0;
}