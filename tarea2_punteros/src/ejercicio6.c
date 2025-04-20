# include <stdio.h>



int main(){

    int filas, columnas;
    int fila, columna;


    printf("Ingrese el numero de filas que tendran las matrices: \n");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas que tendran las matrices: \n");
    scanf("%d", &columnas);

    float A[filas][columnas];
    float B[filas][columnas];
    float C[filas][columnas];
    
    //Ciclo para llenar la matriz A
    printf("\nA continuacion se le pedira que llene la matriz A\n\n");
    for (fila = 0; fila < filas; fila++){
        for (columna = 0; columna < columnas; columna ++){
            
            printf("Ingrese el valor de A[%d][%d] = ", fila, columna);
            scanf("%f", &A[fila][columna]);
        }
    }

    //Ciclo para llenar la matriz B
    printf("\nA continuacion se le pedira que llene la matriz B\n\n");
    for (fila = 0; fila < filas; fila++){
        for (columna = 0; columna < columnas; columna ++){
            
            printf("Ingrese el valor de B[%d][%d] = ", fila, columna);
            scanf("%f", &B[fila][columna]);
        }
    }
    //Ciclo para sumar la matriz C

    for (fila = 0; fila < filas; fila++){
        for (columna = 0; columna < columnas; columna ++){
            C[fila][columna] = A[fila][columna] + B[fila][columna];
            printf("El valor de C[%d][%d] = %2.f \n", fila, columna, C[fila][columna]);
        }
    }
    

    return 0;

}
