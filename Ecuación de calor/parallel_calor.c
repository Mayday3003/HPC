#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define NX 100          // Número de puntos en el espacio
#define NT 1000         // Número de pasos de tiempo
#define DX (1.0/(NX-1)) // Discretización espacial
#define DT 0.0001       // Paso de tiempo
#define ALPHA 0.01      // Difusividad térmica

int main() {
    int i, n;
    
    // Asignación dinámica de memoria
    double *u_old = (double *)malloc(NX * sizeof(double));
    double *u_new = (double *)malloc(NX * sizeof(double));

    if (u_old == NULL || u_new == NULL) {
        fprintf(stderr, "Error al asignar memoria.\n");
        free(u_old);
        free(u_new);
        return -1;
    }

    // Inicialización de la solución
    for (i = 0; i < NX; i++) {
        u_old[i] = 0.0;
    }

    // Condiciones de frontera
    u_old[0] = 100.0;
    u_old[NX - 1] = 50.0;

    // Ciclo temporal con paralelización
    #pragma omp parallel
    {
        for (n = 0; n < NT; n++) {
            // Aplicación de condiciones de frontera
            #pragma omp single
            {
                u_new[0] = 100.0;
                u_new[NX - 1] = 50.0;
            }

            // Actualización de la temperatura en la barra
            #pragma omp for
            for (i = 1; i < NX - 1; i++) {
                u_new[i] = u_old[i] + (ALPHA * DT / (DX * DX)) * 
                          (u_old[i + 1] - 2.0 * u_old[i] + u_old[i - 1]);
            }

            // Intercambio de punteros
            #pragma omp single
            {
                double *temp = u_old;
                u_old = u_new;
                u_new = temp;
            }
        }
    }

    // Impresión de la solución final
    for (i = 0; i < NX; i++) {
        printf("Punto %d: %f\n", i, u_old[i]);
    }

    // Liberar memoria correctamente
    free(u_old);
    free(u_new);

    return 0;
}
