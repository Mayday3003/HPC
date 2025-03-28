#include <stdio.h>
#include <stdlib.h>

int main() {
    double* Celcius;
    double Fahrenheit;
    double Kelvin;

    Celcius = (double*)(malloc(sizeof(double)));

    printf("Ingrese la temperatura en Celcius: \n");
    scanf("%lf", Celcius); 


    Fahrenheit = (9.0/5)*(*Celcius) + 32;
    printf("La temperatura en  Fahrenheit es %lf \n", Fahrenheit);

    Kelvin = *Celcius + 273.15;
    printf("La temperatura en Kelvin es %lf \n", Kelvin);

    free(Celcius);
    return 0;
}