#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Parámetros de la ecuación del calor
#define L 1.0       // Longitud de la barra
#define ALPHA 0.01  // Difusividad térmica
#define NX 100      // Número de puntos espaciales
#define NT 1000     // Número de pasos de tiempo

// Declaraciones de funciones
void inicializar_condicion_inicial(double* u, int nx, double dx);
void aplicar_condiciones_frontera(double* u, int nx);
void resolver_ecuacion_calor(double* u, double* u_nueva, int nx, int nt, double dx, double dt);

int main() {
    double dx = L / (NX - 1);  // Tamaño del paso espacial
    double dt = 0.5 / NT;      // Tamaño del paso temporal

    // Crear arrays dinámicamente
    double* u = (double*) malloc(NX * sizeof(double));
    double* u_nueva = (double*) malloc(NX * sizeof(double));
    if (!u || !u_nueva) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    // Inicializar y aplicar condiciones de frontera
    inicializar_condicion_inicial(u, NX, dx);
    aplicar_condiciones_frontera(u, NX);

    // Resolver la ecuación del calor
    resolver_ecuacion_calor(u, u_nueva, NX, NT, dx, dt);

    // Imprimir resultados finales
    printf("Resultados al tiempo T = 0.5:\n");
    for (int i = 0; i < NX; i++) {
        printf("u(%f) = %f\n", i * dx, u[i]);
    }

    // Liberar memoria
    free(u);
    free(u_nueva);
    return 0;
}

void inicializar_condicion_inicial(double* u, int nx, double dx) {
    for (int i = 0; i < nx; i++) {
        u[i] = sin(M_PI * i * dx / L);
    }
}

void aplicar_condiciones_frontera(double* u, int nx) {
    u[0] = 0.0;
    u[nx - 1] = 0.0;
}

void resolver_ecuacion_calor(double* u, double* u_nueva, int nx, int nt, double dx, double dt) {
    double coef = ALPHA * dt / (dx * dx);
    for (int t = 0; t < nt; t++) {
        for (int i = 1; i < nx - 1; i++) {
            u_nueva[i] = u[i] + coef * (u[i+1] - 2 * u[i] + u[i-1]);
        }
        aplicar_condiciones_frontera(u_nueva, nx);
        memcpy(u, u_nueva, nx * sizeof(double));
    }
}
