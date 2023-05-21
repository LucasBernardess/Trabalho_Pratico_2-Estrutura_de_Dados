#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 1000

// Main
int main() {
    float time_total[6], start, end, cpu_time;
    for(int i = 0; i<6; i++){
        time_total[i] = 0;
    }

    int **matriz, *arr;
    matriz = (int**)malloc(10*sizeof(int*));
	for(int i = 0; i<10; i++){
		matriz[i] = (int*)malloc(TAM*sizeof(int));
	}
    arr = (int*)malloc(TAM*sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = rand() % TAM; 
        }
    }
  
    for(int i = 0; i<10; i++){
        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        selection_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        printf("\n\nSeleção : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        printf("\nTempo de execução --> %lf", cpu_time);
        time_total[0] += cpu_time;

        cpu_time = 0;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        insertion_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        printf("\n\nInserção : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        printf("\nTempo de execução --> %lf", cpu_time);
        time_total[1] += cpu_time;

        cpu_time = 0;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        shell_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        // printf("\n\nShellsort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[2] += cpu_time;

        cpu_time = 0;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        quick_sort(arr, 0, TAM-1);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        // printf("\n\nQuicksort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[3] += cpu_time;

        cpu_time = 0;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        heap_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        // printf("\n\nHeapsort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[4] += cpu_time;

        cpu_time = 0;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        merge_sort(arr, 0, TAM - 1);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        // printf("\n\nMergesort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[5] += cpu_time;

        cpu_time = 0;
    }

    printf("\n\nTamanho Total --> %d\n", TAM);
    printf("Total Seleção --> %lf\n", time_total[0]/10);

    printf("Total Inserção --> %lf\n", time_total[1]/10);
    
    printf("Total Shellsort --> %lf\n", time_total[2]/10);

    printf("Total Quicksort --> %lf\n", time_total[3]/10);

    printf("Total Heapsort --> %lf\n", time_total[4]/10);

    printf("Total Mergesort --> %lf\n", time_total[5]/10);

    return 0;
}