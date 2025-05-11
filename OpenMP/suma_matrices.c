#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    const int M = 2000;   
    const int N = 2000;   
    int i, j;
    double *A, *B, *C;
    double t0, t1, t2;

    A = (double*)malloc(sizeof(double) * M * N);
    B = (double*)malloc(sizeof(double) * M * N);
    C = (double*)malloc(sizeof(double) * M * N);
    if (!A || !B || !C) {
        printf("Error al asignar memoria\n");
        return 1;
    }

    t0 = omp_get_wtime();
    #pragma omp parallel for collapse(2) schedule(static)
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            A[i*N + j] = 1.0;
            B[i*N + j] = 2.0;
        }
    }
    t1 = omp_get_wtime();

    #pragma omp parallel for collapse(2) schedule(static)
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            C[i*N + j] = A[i*N + j] + B[i*N + j];
        }
    }
    t2 = omp_get_wtime();

    printf("C[0,0]=%.1f  init=%.6f s  add=%.6f s  total=%.6f s\n",
           C[0], t1-t0, t2-t1, t2-t0);


    // Imprimir la matriz C 
    printf("Matriz C:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            printf("%.1f ", C[i*N + j]);
        }
        printf("\n");
    }
    


    free(A); free(B); free(C);
    return 0;
}
