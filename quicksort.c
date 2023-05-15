#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double Ttotal;

void insertionSort(int *arr, int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main() {
    int arr[200000];
    int tamanho = 200000; 
    srand(time(NULL));
    printf("\n");
    for(int i = 0; i<10; i++){
        double start = clock();
        for (int i = 0; i < tamanho; i++) {
            arr[i] = rand() % 200000  + 1;
        }

        int n = sizeof(arr) / sizeof(arr[0]);

        insertionSort(arr, 200000);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        double end = clock();
        double cpu_time_1 = ((double)end- start)/CLOCKS_PER_SEC;
        printf("TEMPO DE EXECUÇÃO --> %lf", cpu_time_1);
        printf("\n \n \n");
        Ttotal += cpu_time_1;
    }    

    Ttotal = Ttotal/10;
    printf("\n Total --> %lf\n", Ttotal);
    return 0;
}

