#include <stdio.h>

float suma(float x, float y) {
    return x + y;
}
float resta(float x, float y) {
    return x - y;
}
float multiplicacion(float x, float y) {
    return x * y;
}
float division(float x, float y) {
    if(y == 0){
        printf("Error: Division por 0");
        return 0;
    }
    return x / y;
}


float calculadora(char operador, float x, float y) {
    float (*operando)(float, float) = NULL;
    if (operador == '+') {
        operando = suma;
    } else if (operador == '-') {
        operando = resta;
    } else if (operador == '*') {
        operando = multiplicacion;
    } else if (operador == '/') {
        operando = division;
    } else {
        printf("Error: Operador no valido\n");
        return 0;
    }
    return operando(x, y);
    
}

int main (){

    float res = calculadora('+', 5, 3);
    
    printf("%.2lf", res);

    return 0;
}


