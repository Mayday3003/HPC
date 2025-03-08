#include <stdio.h>
#include "triangulo.h"

// main function
int main(){

   // definición de variables
   double lado_A, lado_B, lado_C, semiperimetro, area;
   
   // ingreso de datos
   ingreso_datos(&lado_A, &lado_B, &lado_C);

    // calculo semiperimetro
    semiperimetro = calculo_semiperimetro(lado_A, lado_B, lado_C);

    // calculo area
    area = calculo_area(semiperimetro, lado_A, lado_B, lado_C);

    // impresion de resultados
    imprimir_resultados(area);

    // terminacion del programa
    return 0;
  
}