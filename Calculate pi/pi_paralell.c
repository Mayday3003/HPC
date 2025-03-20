#include <omp.h>
    #include <stdio.h>
    int main() {
        long long N = 10000000000;  // Número de intervalos (mayor N, más precisión)\n",
        double pi = 0.0;
        double delta_x = 1.0 / (double)N;
        double start_time = 0.0;
        
        double end_time = 0.0;  // Ancho de cada rectángulo\n",

        // Paralelizar la suma utilizando OpenMP

        #pragma omp parallel
        {
            double sum_local = 0.0;  // Variable local para cada hilo\n",
            start_time = omp_get_wtime();
            #pragma omp for
            for (long long i = 0; i < N; i++) {
                double x_i = (i + 0.5) * delta_x;  // Punto medio del intervalo\n",
                sum_local += 4.0 / (1.0 + x_i * x_i);
            }

            // Combinar resultados parciales en la variable global pi
            #pragma omp atomic
            pi += sum_local * delta_x;
        }
        end_time = omp_get_wtime();
        printf("Tiempo de ejecución: %.15f\n", end_time-start_time);
    
        printf("Valor aproximado de pi: %.15f\n", pi);
        return 0;
    }