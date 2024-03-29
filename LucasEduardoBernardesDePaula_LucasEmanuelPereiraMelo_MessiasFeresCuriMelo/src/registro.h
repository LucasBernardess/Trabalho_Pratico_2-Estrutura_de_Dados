#ifndef REGISTRO_H
#define REGISTRO_H

#define TAM 10000 // Altere o TAM para mais ou menos números de execução

typedef int chave;
typedef char mensagem;

typedef struct{
    chave chave;
    //mensagem mensagem[50][50]; // Comente ou descomente para ativar a chave grande
}Registro;

// Seleção
void selection_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao);

// Inserção
void insertion_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao);

// Shell
void shell_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao);

// SWAP -> para o Quickshort e o Heapsort
void swap(int *a, int *b, unsigned long *comparacao, unsigned long *movimentacao);

// Quickshort
int particiona_random(Registro vet[], int inicio, int fim, unsigned long *comparacao, unsigned long *movimentacao);
int particiona(Registro vet[], int inicio, int fim, unsigned long *comparacao, unsigned long *movimentacao);
void troca(Registro vet[], int i, int j, unsigned long *comparacao, unsigned long *movimentacao);
void quick_sort(Registro vet[], int low, int high, unsigned long *comparacao, unsigned long *movimentacao);

// Heapsort
void heapify(Registro *arr, int n, int i, unsigned long *comparacao, unsigned long *movimentacao);
void heap_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao);

// Mergesort
void merge(Registro *arr, int l, int m, int r, unsigned long *comparacao, unsigned long *movimentacao);
void merge_sort(Registro *arr, int l, int r, unsigned long *comparacao, unsigned long *movimentacao);

#endif