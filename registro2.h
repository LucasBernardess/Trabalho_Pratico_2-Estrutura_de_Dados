#ifndef REGISTRO_H
#define REGISTRO_H

typedef int chave;
typedef char vetor;

typedef struct{
    chave chave;
    char vetor[50][50];
}Registro;

void selection_sort(int arr[], int n);
// Inserção
void insertion_sort(int arr[], int n);
// Shell
void shell_sort(int arr[], int n);
// SWAP -> para o Quickshort e o Heapsort
void swap(int *a, int *b);
// Quickshort
int partition(int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);
// Heapsort
void heapify(int arr[], int n, int i);
void heap_sort(int arr[], int n);
// Mergesort
void merge(int arr[], int l, int m, int r);
void merge_sort(int arr[], int l, int r);

#endif