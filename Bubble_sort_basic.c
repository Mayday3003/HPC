
#include <stdio.h>

int main()
{
    int numeros[] = {4, 1, 2, 3, 5};
    int *dir_i, *dir_j;
    int i, j, aux;
    size_t size = sizeof(numeros) / sizeof(numeros[0]);
    
    dir_i = numeros;
    dir_j = numeros;
    
    for(i = 0; i < size; i++){
        for(j = 0; j < size - 1; j++){
            if(*dir_j > *(dir_j + 1)){ 
                aux = *dir_j;
                *dir_j = *(dir_j+1);
                *(dir_j+1) = aux;
            }
            dir_j = numeros + j; 
        }
    }
    
    dir_i = numeros;
    
    for(i=0; i < size; i++){
        printf("%d\n" , *dir_i);
        dir_i = dir_i + 1;
    }
    
    return 0;
}