### Implementación de pila con listas enlazadas en C

En este ejercicio definimos una pila usando una lista enlazada. Primero, la estructura del nodo se declara así:

```c
typedef struct Nodo {
    int dato;                 // Valor almacenado en el nodo
    struct Nodo* siguiente;   // Puntero al siguiente nodo en la pila
} Nodo;
```

Aquí `siguiente` es un puntero que enlaza cada nodo con el que sigue, formando la pila.

### Apilar elementos (push)

La función `push` recibe la dirección del puntero que apunta al tope de la pila (`Nodo** tope`) y el valor a insertar. Con `malloc` reservamos memoria para un nuevo nodo y comprobamos que no sea `NULL`. Asignamos el dato y hacemos que el nuevo nodo apunte al antiguo tope, luego actualizamos el tope para que apunte al nodo recién creado:

```c
void push(Nodo** tope, int valor) {
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error: malloc falló
");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *tope;
    *tope = nuevoNodo;
}
```

La clave está en usar un doble puntero para modificar desde dentro de la función el puntero que guarda la cabeza de la lista.

### Desapilar elementos (pop)

En `pop` comprobamos primero si la pila está vacía accediendo a `*tope`. Si tiene contenido, guardamos en un puntero temporal el nodo actual, extraemos su dato y avanzamos el tope al siguiente nodo con `*tope = temp->siguiente`. Finalmente, liberamos la memoria del nodo desapilado y devolvemos el valor:

```c
int pop(Nodo** tope) {
    if (*tope == NULL) {
        fprintf(stderr, "Error: pila vacía
");
        return -1;
    }
    Nodo* temp = *tope;
    int valor = temp->dato;
    *tope = temp->siguiente;
    free(temp);
    return valor;
}
```

### Recorrer y mostrar la pila

Para imprimir el contenido de la pila definimos `mostrar` que recibe un puntero simple (`Nodo* tope`) y recorre la lista hasta `NULL`, mostrando cada dato:

```c
void mostrar(Nodo* tope) {
    if (tope == NULL) {
        printf("Pila vacía
");
        return;
    }
    printf("Contenido de la pila:
");
    for (Nodo* actual = tope; actual != NULL; actual = actual->siguiente) {
        printf("%d
", actual->dato);
    }
}
```

### Liberar toda la memoria (liberarPila)

La función `liberarPila` avanza el tope hasta que quede `NULL`, liberando cada nodo para evitar fugas de memoria:

```c
void liberarPila(Nodo** tope) {
    while (*tope != NULL) {
        Nodo* temp = *tope;
        *tope = temp->siguiente;
        free(temp);
    }
}
```

### Ejemplo de uso en main

En la función principal inicializamos la pila con `Nodo* pila = NULL`, luego llamamos a `push(&pila, valor)` para añadir elementos y a `pop(&pila)` para quitarlos, mostrando el estado en cada paso. Al final ejecutamos `liberarPila(&pila)` como buena práctica:

```c
int main() {
    Nodo* pila = NULL;
    push(&pila, 5);
    push(&pila, 10);
    push(&pila, 15);
    mostrar(pila);
    printf("Desapilado: %d
", pop(&pila));
    mostrar(pila);
    liberarPila(&pila);
    return 0;
}
```

### Punteros en acción

El puntero simple (`Nodo*`) permite recorrer o mostrar la lista sin modificarla. El doble puntero (`Nodo**`) es esencial cuando queremos cambiar en la función el puntero que almacena la cabeza de la lista. Cada llamada a `malloc` en `push` asigna memoria y cada `free` en `pop` o `liberarPila` la libera, garantizando un manejo correcto de la memoria dinámica.
