#include <stdio.h>

// Función para intercambiar dos valores usando punteros
void intercambiar(int *x, int *y) {
    int temporal = *x;  // Guardamos el valor de *x en una variable temporal
    *x = *y;           // Asignamos el valor de *y a *x
    *y = temporal;     // Asignamos el valor temporal (original de *x) a *y
}

// Función para ordenar un array usando el algoritmo de burbuja con punteros
void ordenarBurbuja(int *arr, int size) {
    int bandera;  // Bandera para optimizar el algoritmo
    for (int i = 0; i < size - 1; i++) {
        bandera = 0;  // Inicializamos la bandera en 0 (falso) al inicio de cada pasada
        for (int j = 0; j < size - i - 1; j++) {
            // Usamos aritmética de punteros para comparar elementos adyacentes
            if (*(arr + j) > *(arr + j + 1)) {
                intercambiar(arr + j, arr + j + 1);  // Intercambiamos si están en el orden incorrecto
                bandera = 1;  // Marcamos la bandera como 1 (verdadero) porque hubo un intercambio
            }
        }
        // Si no hubo intercambios en la pasada, el arreglo ya está ordenado
        if (bandera == 0) {
            break;  // Terminamos el bucle externo
        }
    }
}

int main() {
    int size;  // Variable para almacenar el tamaño del arreglo

    // Solicitar al usuario el tamaño del arreglo
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &size);

    // Verificar si el tamaño es válido
    if (size <= 0) {
        printf("El tamaño del arreglo debe ser mayor que 0.\n");
        return 1;  // Terminar el programa con código de error
    }

    int array[size];  // Declarar el arreglo con el tamaño ingresado

    // Solicitar al usuario que ingrese los elementos del arreglo
    printf("Ingrese los elementos del arreglo, separados por espacios:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &array[i]);  // Leer cada elemento y almacenarlo en el arreglo
    }

    // Imprimir el arreglo original
    printf("Array original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));  // Usamos punteros para imprimir
    }
    printf("\n");

    // Ordenar el arreglo usando la función ordenarBurbuja
    ordenarBurbuja(array, size);

    // Imprimir el arreglo ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));  // Usamos punteros para imprimir
    }
    printf("\n");

    return 0;  // Terminar el programa con éxito
}