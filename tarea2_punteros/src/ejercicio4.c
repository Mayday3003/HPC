# include <stdio.h>
# include <math.h>


char *es_primo(int numero){
    char *resultado;
    if (numero <= 1){
        resultado = "no es";
    }
    else if (numero == 2 || numero == 3){
        resultado = "es";
    }

    else if (numero % 2 == 0 || numero % 3 == 0){
        resultado = "no es";
    }
    else{
        float num_max = sqrt(numero);
        resultado = "es";
        for (int divisor = 2; divisor <= num_max; divisor ++){  
            if (numero % divisor == 0){
                resultado = "no es";
                break;
            }
        }
    }

    return resultado;
}

int main(){

    int numero;
    char *resultado;

    printf("\nIngrese un numero NATURAL para determinar si es un numero primo o no: ");
    scanf("%d", &numero);

    resultado = es_primo(numero);
    printf("\nEl numero ingresado %s un numero primo\n\n", resultado);
    return 0;
}