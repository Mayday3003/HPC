#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sortArray(int *arr, int size) {
    for (int i = 0; i < arr + size - 1; i++) {
        for (int *j = arr; j < arr + size - (i - arr) - 1; j++) {
            if (*j > *(j + 1)) {
                swap(j, j + 1);
            }
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");

    sortArray(arr, size);

    printf("Array ordenado: ");
    for (int *ptr = arr; ptr < arr + size; ptr++) {
        printf("%d ", *ptr);
    }
    printf("\n");

    return 0;
}
