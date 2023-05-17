#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAM 10000

// Seleção
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

// Inserção
void insertion_sort(int arr[], int n) {
    int i, key, j;
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

// Shell
void shell_sort(int arr[], int n) {
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2) {
        for (i = gap; i < n; i++) {
            temp = arr[i];
            for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
                arr[j] = arr[j-gap];
            }
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
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
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
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n-1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
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
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// Main
int main() {
    int matriz[10][TAM];
    int arr[TAM];
    float Ttotal, start, end, cpu_time;

    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = rand() % 100; 
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
        Ttotal += cpu_time;
    }
    Ttotal = Ttotal/10;
    printf("\n\nTotal --> %lf\n", Ttotal);
    Ttotal = 0;


    for(int i = 0; i<10; i++){
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
        Ttotal += cpu_time;
    }
    Ttotal = Ttotal/10;
    printf("\n\nTotal --> %lf\n", Ttotal);
    Ttotal = 0;


    for(int i = 0; i<10; i++){
        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        shell_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        printf("\n\nShellsort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        printf("\nTempo de execução --> %lf", cpu_time);
        Ttotal += cpu_time;
    }
    Ttotal = Ttotal/10;
    printf("\n\nTotal --> %lf\n", Ttotal);
    Ttotal = 0;


    for(int i = 0; i<10; i++){
        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        quick_sort(arr, 0, TAM-1);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        printf("\n\nQuicksort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        printf("\nTempo de execução --> %lf", cpu_time);
        Ttotal += cpu_time;
    }
    Ttotal = Ttotal/10;
    printf("\n\nTotal --> %lf\n", Ttotal);
    Ttotal = 0;


    for(int i = 0; i<10; i++){
        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        heap_sort(arr, TAM);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        printf("\n\nHeapsort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        printf("\nTempo de execução --> %lf", cpu_time);
        Ttotal += cpu_time;
    }
    Ttotal = Ttotal/10;
    printf("\n\nTotal --> %lf\n", Ttotal);
    Ttotal = 0;


    for(int i = 0; i<10; i++){
        for(int j = 0; j<TAM; j++){
            arr[j] = matriz[i][j];
        }
        start = clock();
        merge_sort(arr, 0, TAM - 1);
        end = clock();
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC;
        printf("\n\nMergesort : %d", i);
        // printf("\nArray ordenado em ordem crescente : ");
        // for (int k = 0; k < TAM; k++) {
        //     printf("%d ", arr[k]);
        // }
        printf("\nTempo de execução --> %lf", cpu_time);
        Ttotal += cpu_time;
    }
    Ttotal = Ttotal/10;
    printf("\n\nTotal --> %lf\n", Ttotal);
    Ttotal = 0;

    return 0;
}