#include <stdio.h>
#include <math.h>


int main(){

    float lado_a, lado_b, lado_c, semip_p, area;
    int datos_correctos= 0;


    while(datos_correctos == 0){
        
        printf("Ingrese el valor del lado A(cm): ");
        scanf("%f", &lado_a);

        printf("Ingrese el valor del lado B(cm): ");
        scanf("%f", &lado_b);

        printf("Ingrese el valor del lado C(cm): ");
        scanf("%f", &lado_c);

        //Comprobación de la desigualdad triangular
        if (lado_a + lado_b < lado_c || lado_b + lado_c < lado_a || lado_c + lado_a < lado_b){
            printf("Los lados no cumplen con la desigualdad triangular\n");
            printf("Vuelva a ingresar los datos\n");
            datos_correctos = 0;
        }
        // Los lados de un triangulo deben ser mayores que 0
        else if (lado_a <= 0 || lado_b <= 0 || lado_c <= 0){
            printf("\nLos lados deben ser mayores a cero\n");
            printf("Vuelva a ingresar los datos\n");
            datos_correctos = 0;
        }
        else{
            datos_correctos = 1;
        }
        
    }

    // Calculo del semiperimetro
    semip_p = (lado_a + lado_b + lado_c) / 2.0;

    // Calculo del area
    area = sqrt(semip_p * (semip_p - lado_a)*(semip_p - lado_b)*(semip_p - lado_c));
    
    printf("El area del triangulo es: %.2f cm^2\n", area);
    

    return 0;
}