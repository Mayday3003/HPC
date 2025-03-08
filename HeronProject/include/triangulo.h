#ifndef triangulo_H
#define triangulo_H

//declaracion de funciones
void ingreso_datos(double *lado_A, double *lado_B, double *lado_C);
double calculo_semiperimetro(double lado_A, double lado_B, double lado_C);
double calculo_area(double semiperimetro, double lado_A, double lado_B, double lado_C);
void imprimir_resultados(double area);

#endif