#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM 20

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

// Aleatório
void randomM(int arr[]){
    for(int i = 0; i<TAM; i++){
        arr[i] = rand() % 1000 + 1;
    }
}

// Main
int main() {
    int arr[TAM];

    randomM(arr);

    selection_sort(arr, TAM);
    printf("\n\nSeleção");
    printf("\nArray ordenado em ordem crescente: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }

    randomM(arr);

    insertion_sort(arr, TAM);
    printf("\n\nInserção");
    printf("\nArray ordenado em ordem crescente: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }

    randomM(arr);

    shell_sort(arr, TAM);
    printf("\n\nShellsort");
    printf("\nArray ordenado em ordem crescente: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }

    randomM(arr);

    quick_sort(arr, 0, TAM-1);
    printf("\n\nQuicksort");
    printf("\nArray ordenado em ordem crescente: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }

    randomM(arr);

    heap_sort(arr, TAM);
    printf("\n\nHeapsort");
    printf("\nArray ordenado em ordem crescente: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }

    randomM(arr);

    merge_sort(arr, 0, TAM - 1);
    printf("\n\nMergesort");
    printf("\nArray ordenado em ordem crescente: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}