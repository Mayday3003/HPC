# include <stdio.h>

int suma_numeros(int num_max){
    int suma_numeros = 0;
    int num = 0;
    while (num <= num_max){
        suma_numeros = suma_numeros + num;
        num ++;
    }

    return suma_numeros;
}

int main(){

    int cantidad_num_naturales, suma;

    printf("\nEste Programa realiza la suma de los primeros 'n' numeros naturales\n\nPor favor ingrese 'n': ");
    scanf("%d", &cantidad_num_naturales);
    printf("\n!!!ADVERTENCIA!!!\nSi ingreso un numero que no es entero el programa tomara la parte entera y botara los decimales\n");

    suma = suma_numeros(cantidad_num_naturales);
    printf("\n\nLa suma de los primeros %d numeros naturales es: %d", cantidad_num_naturales, suma);

    return 0;
}