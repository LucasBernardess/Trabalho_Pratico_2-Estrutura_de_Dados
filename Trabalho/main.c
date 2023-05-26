#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "registro.h"

// Main
int main() {
    float time_total[6], start, end, cpu_time;
    unsigned long comparacao[6], movimentacao[6];
    int **matriz;

    Registro *arr = (Registro*)malloc(TAM*sizeof(Registro));
    matriz = (int**)malloc(10*sizeof(int*));
	for(int i = 0; i<10; i++){
		matriz[i] = (int*)malloc(TAM*sizeof(int));
	}

    for(int i = 0; i<6; i++){
        time_total[i] = 0;
        comparacao[i] = 0;
        movimentacao[i] = 0;
    }

    srand(time(NULL));

    switch (1) {
    case 1: // random
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < TAM; j++) {
                matriz[i][j] = rand() % TAM; 
            }
        }
        break;
    case 2: // Crescente
        for (int i = 0; i < 10; i++) {
            int crescente = rand() % TAM;
            for (int j = 0; j < TAM; j++, crescente++) {
                matriz[i][j] = crescente; 
            }
        }
        break;
    case 3: // Decrescente
        for (int i = 0; i < 10; i++) {
            int decrescente = rand() % 10*TAM;
            for (int j = 0; j < TAM; j++, decrescente--) {
                matriz[i][j] = decrescente; 
            }
        }
        break;
    default:
        printf("Números não definidos\n");
        break;
    }
  
    for(int i = 0; i<10; i++){
        // Seleção
        for(int j = 0; j<TAM; j++){
            arr[j].chave = matriz[i][j];
        }
        start = clock();
        selection_sort(arr, TAM, comparacao, movimentacao);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
            // printf("\n\nSeleção : %d", i);
            // printf("\nArray ordenado em ordem crescente : ");
            // for (int k = 0; k < TAM; k++) {
            //     printf("%d ", arr[k].chave);
            // }
            // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[0] += cpu_time;

        // Inserção
        for(int j = 0; j<TAM; j++){
            arr[j].chave = matriz[i][j];
        }
        start = clock();
        insertion_sort(arr, TAM, comparacao, movimentacao);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
            // printf("\n\nInserção : %d", i);
            // printf("\nArray ordenado em ordem crescente : ");
            // for (int k = 0; k < TAM; k++) {
            //     printf("%d ", arr[k].chave);
            // }
            // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[1] += cpu_time;

        // Shell
        for(int j = 0; j<TAM; j++){
            arr[j].chave = matriz[i][j];
        }
        start = clock();
        shell_sort(arr, TAM, comparacao, movimentacao);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
            // printf("\n\nShellsort : %d", i);
            // printf("\nArray ordenado em ordem crescente : ");
            // for (int k = 0; k < TAM; k++) {
            //     printf("%d ", arr[k].chave);
            // }
            // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[2] += cpu_time;

        // Quicksort
        for(int j = 0; j<TAM; j++){
            arr[j].chave = matriz[i][j];
        }
        start = clock();
        quick_sort(arr, 0, TAM - 1, comparacao, movimentacao);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
            // printf("\n\nQuicksort : %d", i);
            // printf("\nArray ordenado em ordem crescente : ");
            // for (int k = 0; k < TAM; k++) {
            //     printf("%d ", arr[k].chave);
            // }
            // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[3] += cpu_time;

        // Heapsort
        for(int j = 0; j<TAM; j++){
            arr[j].chave = matriz[i][j];
        }
        start = clock();
        heap_sort(arr, TAM, comparacao, movimentacao);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
            // printf("\n\nHeapsort : %d", i);
            // printf("\nArray ordenado em ordem crescente : ");
            // for (int k = 0; k < TAM; k++) {
            //     printf("%d ", arr[k].chave);
            // }
            // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[4] += cpu_time;

        // Mergesort
        for(int j = 0; j<TAM; j++){
            arr[j].chave = matriz[i][j];
        }
        start = clock();
        merge_sort(arr, 0, TAM - 1, comparacao, movimentacao);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
            // printf("\n\nMergesort : %d", i);
            // printf("\nArray ordenado em ordem crescente : ");
            // for (int k = 0; k < TAM; k++) {
            //     printf("%d ", arr[k].chave);
            // }
            // printf("\nTempo de execução --> %lf", cpu_time);
        time_total[5] += cpu_time;
    }

    printf("\n\nNúmero de elementos --> %d\n\n", TAM);
    printf("Seleção\n");
    printf("Tempo médio --> %lf\n", time_total[0]/10);
    printf("Média de comparações --> %lu\n", comparacao[0]/10);
    printf("Média de movimentações --> %lu\n\n", movimentacao[0]/10);

    printf("Inserção\n");
    printf("Tempo médio --> %lf\n", time_total[1]/10);
    printf("Média de comparações --> %lu\n", comparacao[1]/10);
    printf("Média de movimentações --> %lu\n\n", movimentacao[1]/10);
    
    printf("Shellsort\n");
    printf("Tempo médio --> %lf\n", time_total[2]/10);
    printf("Média de comparações --> %lu\n", comparacao[2]/10);
    printf("Média de movimentações--> %lu\n\n", movimentacao[2]/10);

    printf("Quicksort\n");
    printf("Tempo médio --> %lf\n", time_total[3]/10);
    printf("Média de comparações --> %lu\n", comparacao[3]/10);
    printf("Média de movimentações --> %lu\n\n", movimentacao[3]/10);

    printf("Heapsort\n");
    printf("Tempo médio --> %lf\n", time_total[4]/10);
    printf("Média de comparações --> %lu\n", comparacao[4]/10);
    printf("Média de movimentações--> %lu\n\n", movimentacao[4]/10);

    printf("Mergesort\n");
    printf("Tempo médio --> %lf\n", time_total[5]/10);
    printf("Média de comparações --> %lu\n", comparacao[5]/10);
    printf("Média de movimentações --> %lu\n", movimentacao[5]/10);

    return 0;
}