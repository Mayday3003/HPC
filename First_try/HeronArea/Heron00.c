#include <stdio.h>
#include <math.h>

// main function
int main(){     
    // definición de variables
    double lado_A, lado_B, lado_C, semip_p, area;
    //Lectura de datos
    printf("Ingrese el valor del lado A(cm): ");
    scanf("%lf", &lado_A);

    printf("Ingrese el valor del lado B(cm): ");
    scanf("%lf", &lado_B);

    printf("Ingrese el valor del lado C(cm): ");
    scanf("%lf", &lado_C);

    // verificación de los lados lado_A, lado_B, lado_C
    while ((lado_A + lado_B) <= lado_C || (lado_A + lado_C) <= lado_B || (lado_B + lado_C) <= lado_A){
        printf("Ingrese los lados nuevamente\n");
        printf("Ingrese el valor del lado A(cm): ");
        scanf("%lf", &lado_A);

        printf("Ingrese el valor del lado B(cm): ");
        scanf("%lf", &lado_B);
        if(lado_A <= 0 || lado_B <= 0 || lado_C <= 0){
            printf("Los lados deben ser mayores a cero, v\n");
            return 1;
        }
        printf("Ingrese el valor del lado C(cm): ");
        scanf("%lf", &lado_C);
    }
    
    // calculo semiperimetro
    semip_p = (lado_A + lado_B + lado_C) / 2.0;

    // calculo area
    area = sqrt(semip_p * (semip_p - lado_A)*(semip_p - lado_B)*(semip_p - lado_C));
    
    // impresion de resultados 
    printf("El área del triángulo es : %lf cm^2\n",area);

    // terminacion del programa 
    return 0;
}

