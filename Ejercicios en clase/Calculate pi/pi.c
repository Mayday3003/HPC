#include <stdio.h>
#include <time.h>

int main() {
    long long N = 10000000000;  // Número de intervalos (mayor N, más precisión)
    double pi = 0.0;
    double delta_x = 1.0 / (double)N;  // Ancho de cada rectángulo

    clock_t start, end;  
    start = clock();  // Iniciar medición

    // Bucle para sumar las áreas de los rectángulos
    for (long long i = 0; i < N; i++) {
        double x_i = (i + 0.5) * delta_x;  // Punto medio del intervalo
        pi += 4.0 / (1.0 + x_i * x_i);     // Añadir altura del rectángulo a la suma
    }

    pi *= delta_x;  // Multiplicar por el ancho del rectángulo para obtener el área total

    end = clock();  // Finalizar medición
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;  // Convertir a segundos

    printf("Valor aproximado de pi: %.15f\n", pi);
    printf("Tiempo de ejecución: %f segundos\n", time_taken);

    return 0;
}
