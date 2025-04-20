
# Ejercicio 10: Implementación de una Pila con Lista Enlazada en C

## Introducción

Una **pila (stack)** es una estructura de datos LIFO (Last In, First Out), en la que el último elemento en entrar es el primero en salir. En C, las pilas se pueden implementar con arreglos (de tamaño fijo) o con listas enlazadas dinámicas. En este ejercicio optamos por la segunda opción, aprovechando punteros y memoria dinámica.

## Estructura del Nodo

Cada nodo de la pila contiene un valor entero y un puntero al siguiente nodo:

```c
typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;
```

## Operaciones Básicas

### Push (Apilar un elemento)

Esta función inserta un nuevo nodo en el tope de la pila.

```c
void push(Nodo** pila, int valor) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->valor = valor;
    nuevo->siguiente = *pila;
    *pila = nuevo;
}
```

**Explicación:**  
- Se reserva memoria para un nuevo nodo.
- El campo `valor` se asigna al valor ingresado.
- `nuevo->siguiente` apunta al nodo que era previamente el tope.
- Finalmente, el nuevo nodo se convierte en el nuevo tope.

### Pop (Desapilar un elemento)

Esta función elimina el nodo del tope y devuelve su valor.

```c
int pop(Nodo** pila) {
    if (*pila == NULL) {
        printf("Error: Pila vacía\n");
        return -1;
    }
    Nodo* temp = *pila;
    int valor = temp->valor;
    *pila = temp->siguiente;
    free(temp);
    return valor;
}
```

**Explicación:**  
- Se verifica si la pila está vacía.
- Se guarda el valor del nodo a eliminar.
- Se actualiza el tope de la pila al siguiente nodo.
- Se libera la memoria del nodo anterior.

### Mostrar (Imprimir la pila)

```c
void mostrar(Nodo* pila) {
    if (pila == NULL) {
        printf("Pila vacía\n");
        return;
    }
    Nodo* actual = pila;
    while (actual != NULL) {
        printf("%d\n", actual->valor);
        actual = actual->siguiente;
    }
}
```

**Explicación:**  
Se recorre la pila desde el tope hasta el último nodo (`NULL`) imprimiendo cada valor.

## Función Principal

```c
int main() {
    Nodo* pila = NULL;

    push(&pila, 5);
    push(&pila, 10);
    push(&pila, 15);

    printf("Estado actual de la pila:\n");
    mostrar(pila);

    printf("\nDesapilando elementos:\n");
    printf("Elemento desapilado: %d\n", pop(&pila));
    printf("Elemento desapilado: %d\n", pop(&pila));

    printf("\nEstado actual de la pila:\n");
    mostrar(pila);

    return 0;
}
```

## Uso de Memoria

- **`malloc()`** permite crear nodos dinámicamente sin límite fijo de tamaño.
- **`free()`** evita fugas de memoria al eliminar nodos.

## Representación Visual

Después de los `push(5)`, `push(10)`, `push(15)`:

```
[15 | *] → [10 | *] → [5 | NULL]
```

Luego de dos `pop()`:

```
[5 | NULL]
```

## Complejidad Temporal

| Operación | Complejidad |
|-----------|-------------|
| Push      | O(1)        |
| Pop       | O(1)        |
| Mostrar   | O(n)        |

## Conclusión

Esta implementación aprovecha el uso de punteros para representar una pila dinámica eficiente. Con `push()` y `pop()` en tiempo constante, se convierte en una solución ideal para estructuras que requieren retroceso como evaluación de expresiones, navegación, backtracking, etc.
