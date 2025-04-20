# include <stdio.h>

float conversion_farenheit(float celsius){
    return ((9.0 / 5.0) * celsius) + 32.0;
}

float conversion_kelvin(float celsius){
    return (celsius + 273.15);
}

int main(){

    float temperatura_celsius, temperatura_farenheit, temperatura_kelvin;

    printf("Por favor ingrese una temperatura en Grados Celsius:\n");
    scanf("%f", &temperatura_celsius);

    temperatura_farenheit = conversion_farenheit(temperatura_celsius);
    temperatura_kelvin = conversion_kelvin(temperatura_celsius);

    printf("La temperatura ingresada fue de %.2f grados celsius. \nEn Grados Farenheit es: %.2f\nEn grados Kelvin es: %.2f\n",
        temperatura_celsius, temperatura_farenheit, temperatura_kelvin);

    return 0;
}