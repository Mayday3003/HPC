#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la pila
struct Nodo {
    int dato;
    struct Nodo* siguiente;
};

// Función para agregar elementos a la pila (Push)
void push(struct Nodo** tope, int valor) {
    // 1. Crear nuevo nodo
    struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    
    // 2. Asignar dato y enlazar con el nodo anterior
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *tope;  // Puntero al antiguo tope
    
    // 3. Actualizar tope de la pila
    *tope = nuevoNodo;  // El nuevo nodo es ahora el tope
}

// Función para eliminar elementos de la pila (Pop)
int pop(struct Nodo** tope) {
    if (*tope == NULL) {
        printf("Error: Pila vacia\n");
        return -1;  // Valor de error
    }
    
    // 1. Guardar referencia al nodo a eliminar
    struct Nodo* temp = *tope;
    int valor = temp->dato;  // Guardar el valor
    
    // 2. Actualizar tope al siguiente nodo
    *tope = (*tope)->siguiente;
    
    // 3. Liberar memoria del nodo eliminado
    free(temp);
    
    return valor;
}

// Función para mostrar la pila
void mostrarPila(struct Nodo* tope) {
    if (tope == NULL) {
        printf("Pila vacia\n");
        return;
    }
    
    struct Nodo* actual = tope;
    printf("Tope -> ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    struct Nodo* tope = NULL;  // Puntero al tope de la pila
    
    // Prueba de operaciones de la pila
    push(&tope, 10);
    push(&tope, 20);
    push(&tope, 30);
    
    printf("Pila inicial:\n");
    mostrarPila(tope);
    
    printf("\nElemento extraido: %d\n", pop(&tope));
    printf("Estado de la pila:\n");
    mostrarPila(tope);
    
    printf("\nElemento extraido: %d\n", pop(&tope));
    printf("Estado de la pila:\n");
    mostrarPila(tope);
    
    printf("\nElemento extraido: %d\n", pop(&tope));
    printf("Estado de la pila:\n");
    mostrarPila(tope);
    
    printf("\nIntento de extraer de pila vacia:\n");
    pop(&tope);
    
    return 0;
}