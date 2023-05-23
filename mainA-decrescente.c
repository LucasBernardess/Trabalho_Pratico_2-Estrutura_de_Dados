#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 10000
unsigned long comparacao[6], movimentacao[6];

// Seleção
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        comparacao[0]++;
        min_idx = i;
        for (j = i+1; j < n; j++) {
            comparacao[0]++;
            if (arr[j] < arr[min_idx]) {
                comparacao[0]++;
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        movimentacao[0]++;
        arr[min_idx] = arr[i];
        movimentacao[0]++;
        arr[i] = temp;
    }
}

// Inserção
void insertion_sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        comparacao[1]++;
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparacao[1]++;
            movimentacao[1]++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        movimentacao[1]++;
        arr[j + 1] = key;
    }
}

// Shell
void shell_sort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        comparacao[2]++;
        for (i = gap; i < n; i++) {
            comparacao[2]++;
            temp = arr[i];
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                comparacao[2]++;
                movimentacao[2]++;
                arr[j] = arr[j-gap];
            }
            movimentacao[2]++;
            arr[j] = temp;
        }
    }
}

// SWAP -> para o Quickshort e o Heapsort
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Quickshort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        comparacao[3]++;
        if (arr[j] < pivot) {
            comparacao[3]++;
            i++;
            swap(&arr[i], &arr[j]);
            movimentacao[3]++;
            movimentacao[3]++;
        }
    }
    swap(&arr[i+1], &arr[high]);
    movimentacao[3]++;
    movimentacao[3]++;
    return i+1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        comparacao[3]++;
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

// Heapsort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        comparacao[4]++;
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        comparacao[4]++;
        largest = r;
    }
    if (largest != i) {
        comparacao[4]++;
        swap(&arr[i], &arr[largest]);
        movimentacao[4]++;
        movimentacao[4]++;
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        comparacao[4]++;
        heapify(arr, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        comparacao[4]++;
        swap(&arr[0], &arr[i]);
        movimentacao[4]++;
        movimentacao[4]++;
        heapify(arr, i, 0);
    }
}

// Mergesort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        comparacao[5]++;
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        comparacao[5]++;
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparacao[5]++;
        if (L[i] <= R[j]) {
            movimentacao[5]++;
            arr[k] = L[i];
            i++;
        }
        else {
            movimentacao[5]++;
            arr[k] = R[j];
            j++;
        }
        comparacao[5]++;
        k++;
    }
    while (i < n1) {
        comparacao[5]++;
        movimentacao[5]++;
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        comparacao[5]++;
        movimentacao[5]++;
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        comparacao[5]++;
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Main
int main() {
    float time_total[6], start, end, cpu_time;
    int **matriz, *arr;

    matriz = (int**)malloc(10*sizeof(int*));
    arr = (int*)malloc(TAM*sizeof(int));
	for(int i = 0; i<10; i++){
		matriz[i] = (int*)malloc(TAM*sizeof(int));
	}
    for(int i = 0; i<6; i++){
        time_total[i] = 0;
        comparacao[i] = 0;
        movimentacao[i] = 0;
    }

    srand(time(NULL));
    int decrescente = TAM;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < TAM; j++, decrescente--) {
            matriz[i][j] = decrescente; 
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
        time_total[0] += cpu_time;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        insertion_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        time_total[1] += cpu_time;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        shell_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        time_total[2] += cpu_time;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        quick_sort(arr, 0, TAM-1);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        time_total[3] += cpu_time;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        heap_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        time_total[4] += cpu_time;

        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        merge_sort(arr, 0, TAM - 1);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        time_total[5] += cpu_time;
    }

    printf("\n\nNúmero de elementos --> %d\n", TAM);
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