#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Seleção
int selection_sort(int arr1[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr1[j] < arr1[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr1[min_idx];
        arr1[min_idx] = arr1[i];
        arr1[i] = temp;

        return arr1;
    }
}

// Inserção
int insertion_sort(int arr[], int n) {
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
int shell_sort(int arr[], int n) {
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


int main() {
    int MAXTAM = 20;
    double Ttotal;
    int arr[MAXTAM];
    int tamanho = MAXTAM; 
    srand(time(NULL));
    printf("\n");
    double Ttotal1, Ttotal2, Ttotal3;
    for(int i = 0; i<10; i++){
        double start = clock();
        for (int i = 0; i < tamanho; i++) {
            arr[i] = rand() % MAXTAM  + 1;
        }

        int n = sizeof(arr) / sizeof(arr[0]);

        insertion_sort(arr, MAXTAM);
        printf("Sorted array: ");

        for (int i = 0; i < n; i++) {
            printf("%d ", arr1[i]);
        }
        double end = clock();

        double cpu_time_1 = ((double)end- start)/CLOCKS_PER_SEC;
        printf("TEMPO DE EXECUÇÃO --> %lf", cpu_time_1);
        printf("\n \n \n");
        Ttotal1 += cpu_time_1;

        start = 0;
        end = 0;

        //selection sort

        start = clock();

        int arr1 = selection_sort(arr, MAXTAM);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr1[i]);
        }
        double end = clock();
        double cpu_time_2 = ((double)end- start)/CLOCKS_PER_SEC;
        printf("TEMPO DE EXECUÇÃO --> %lf", cpu_time_2);
        printf("\n \n \n");
        Ttotal2 += cpu_time_2;


        start = 0;
        end = 0;

        //shell


        start = clock();


        int arr2 = shell_sort(arr, MAXTAM);
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr2[i]);
        }
        end = clock();
        double cpu_time_3 = ((double)end- start)/CLOCKS_PER_SEC;
        printf("TEMPO DE EXECUÇÃO --> %lf", cpu_time_3);
        printf("\n \n \n");
        Ttotal2 += cpu_time_3;


        





    }    

    Ttotal = Ttotal/10;
    printf("\n Total para 20 elementos  --> %lf\n", Ttotal);
}