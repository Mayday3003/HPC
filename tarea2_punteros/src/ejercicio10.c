#include <stdio.h>
#include <stdlib.h>

// Estructura del nodo de la pila
typedef struct Nodo {
    int dato;                 // Dato almacenado en el nodo
    struct Nodo* siguiente;   // Puntero al siguiente nodo
} Nodo;

// Función para apilar (push)
void push(Nodo** tope, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para un nuevo nodo.\n");
        exit(EXIT_FAILURE);  // Finaliza el programa si malloc falla
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *tope;  // El nuevo nodo apunta al anterior tope
    *tope = nuevoNodo;             // El nuevo nodo ahora es el tope
}

// Función para desapilar (pop)
int pop(Nodo** tope) {
    if (*tope == NULL) {
        fprintf(stderr, "Error: No se puede desapilar porque la pila está vacía.\n");
        return -1;  // Indicador de error
    }
    Nodo* temp = *tope;         // Nodo temporal para liberar
    int valor = temp->dato;     // Guarda el valor antes de liberar
    *tope = (*tope)->siguiente; // Mueve el tope al siguiente nodo
    free(temp);                 // Libera memoria del nodo desapilado
    return valor;
}

// Función para mostrar la pila
void mostrar(Nodo* tope) {
    if (tope == NULL) {
        printf("Pila vacía\n");
        return;
    }
    printf("Contenido de la pila:\n");
    Nodo* actual = tope;
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}

// Función para liberar toda la memoria de la pila
void liberarPila(Nodo** tope) {
    while (*tope != NULL) {
        Nodo* temp = *tope;
        *tope = (*tope)->siguiente;
        free(temp);
    }
}

// Función principal
int main() {
    Nodo* pila = NULL;  // Inicializa la pila vacía

    // Insertamos elementos en la pila
    push(&pila, 5);
    push(&pila, 10);
    push(&pila, 15);

    mostrar(pila);  // Mostramos la pila

    // Desapilamos elementos uno a uno y mostramos el estado de la pila
    printf("Elemento desapilado: %d\n", pop(&pila));
    mostrar(pila);

    printf("Elemento desapilado: %d\n", pop(&pila));
    mostrar(pila);

    printf("Elemento desapilado: %d\n", pop(&pila));
    mostrar(pila);

    // Intentamos desapilar cuando la pila ya está vacía
    printf("Intento extra: %d\n", pop(&pila));

    // Liberamos la pila por completo (aunque ya está vacía, por buenas prácticas)
    liberarPila(&pila);

    return 0;
}
