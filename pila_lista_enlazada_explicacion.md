
# Pila Dinámica con Lista Enlazada en C: Explicación Profunda

## Estructura base

```c
typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} Nodo;
```

Cada nodo contiene un campo `dato` y un puntero al siguiente nodo (`siguiente`). Esta estructura permite representar la pila de manera dinámica y enlazada.

## Push (Apilar)

```c
void push(Nodo** tope, int valor) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (!nuevoNodo) {
        printf("Error al asignar memoria\n");
        return;
    }
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = *tope;
    *tope = nuevoNodo;
}
```

### Explicación detallada

En esta función recibimos un puntero doble al tope de la pila (`Nodo** tope`) y el valor que queremos insertar.

### ¿Por qué un puntero doble?

Un puntero doble (`Nodo**`) nos permite modificar directamente el puntero original en `main`. Es decir, si la pila está vacía (tope es `NULL`), con `*tope = nuevoNodo` establecemos el nuevo nodo como el primer elemento. Si usáramos solo un puntero simple, estaríamos modificando una copia local y la pila original no se actualizaría.

### Creación del nodo

Reservamos memoria en el heap usando `malloc`, lo que permite que el nodo siga existiendo incluso después de que termine la función `push`.

```c
Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
```

Esto garantiza que el nodo no se borra automáticamente al salir de la función (como pasaría con una variable local).

### Uso del operador `->`

```c
nuevoNodo->dato = valor;
nuevoNodo->siguiente = *tope;
```

- El operador `->` accede a los campos de una estructura apuntada por un puntero.
- Equivale a `(*nuevoNodo).dato`, pero es más legible.

### Lógica del enlace

Al decir `nuevoNodo->siguiente = *tope`, estamos diciendo:

“El nuevo nodo debe apuntar al nodo que antes era el tope”.

Finalmente, con `*tope = nuevoNodo`:

“Ahora el tope de la pila será este nuevo nodo”.

Este proceso simula colocar el nuevo valor "encima" de la pila.

## Pop (Desapilar)

```c
int pop(Nodo** tope) {
    if (*tope == NULL) {
        printf("Error: Pila vacía\n");
        return -1;
    }
    Nodo* temp = *tope;
    int valor = temp->dato;
    *tope = (*tope)->siguiente;
    free(temp);
    return valor;
}
```

### Explicación detallada

Aquí también usamos un puntero doble para modificar directamente el tope de la pila.

### ¿Cómo funciona?

1. Verificamos si la pila está vacía.
2. Creamos un puntero temporal `temp` que apunta al nodo actual del tope.
3. Guardamos el valor (`dato`) que vamos a retornar.
4. Actualizamos el tope con `*tope = (*tope)->siguiente`; es decir, “subimos un nivel en la pila”.
5. Liberamos la memoria del nodo que retiramos con `free(temp)`.

## Mostrar

```c
void mostrar(Nodo* tope) {
    if (tope == NULL) {
        printf("Pila vacía\n");
        return;
    }
    Nodo* actual = tope;
    while (actual != NULL) {
        printf("%d\n", actual->dato);
        actual = actual->siguiente;
    }
}
```

Aquí no necesitamos un puntero doble porque no modificamos la pila, solo la recorremos.

### El recorrido

1. Comenzamos con `actual = tope`.
2. Mientras `actual` no sea `NULL`, mostramos su contenido.
3. Luego hacemos `actual = actual->siguiente`.

El operador `->` aquí permite acceder al campo `siguiente` de cada nodo para avanzar en el recorrido.

## Gestión de Memoria

La alternancia entre `malloc` y `free` es crucial para evitar errores de memoria.

### ¿Qué pasa si no usamos `free`?

Cada llamada a `push` crea un nuevo nodo en el heap. Si no lo liberamos con `free` cuando hacemos `pop`, esos bloques de memoria se quedan ocupados, aunque ya no tengamos cómo acceder a ellos. A esto se le llama fuga de memoria (memory leak).

En programas de larga duración o que hacen muchas inserciones/eliminaciones, las fugas de memoria pueden causar que se agote la memoria dinámica (heap) del sistema, provocando fallos.

### ¿Qué se libera y qué no?

- Cuando hacemos `free(temp)`, liberamos solo el nodo que se quitó de la pila.
- La pila conserva los demás nodos intactos, porque sus direcciones no se ven afectadas.
- Nada queda “colgado” si actualizamos correctamente el puntero `*tope`.
