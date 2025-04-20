#include <stdio.h>
#include <stdlib.h>

// Definición estructura para la lista enlazada
typedef struct lista {
    int dato;
    struct lista* siguiente;
} Lista;