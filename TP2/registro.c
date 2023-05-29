#include "registro.h"
#include <stdio.h> 
#include <stdlib.h>
#include <time.h>




// Seleção
void selection_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao){
    int i, j, minInd, temp;
    for (i = 0; i < n - 1; i++) {
        minInd = i;
        for (j = i + 1; j < n; j++) {
            comparacao[0]++;
            if (arr[j].chave < arr[minInd].chave) {
                minInd = j;
            }
        }
        temp = arr[i].chave;
        movimentacao[0]++;
        arr[i].chave = arr[minInd].chave;
        movimentacao[0]++;
        arr[minInd].chave = temp;
        movimentacao[0]++;
    }
}

// Inserção
void insertion_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        comparacao[1]++;
        key = arr[i].chave;
        movimentacao[1]++;
        j = i - 1;
        while (j >= 0 && arr[j].chave > key) {
            comparacao[1]++;
            movimentacao[1]++;
            arr[j + 1].chave = arr[j].chave;
            j = j - 1;
        }
        movimentacao[1]++;
        arr[j + 1].chave = key;
    }
}

// Shell
void shell_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao) {
    int i, j, k, tmp;
    for (i = n / 2; i > 0; i = i / 2) {
        for (j = i; j < n; j++) {
            for(k = j - i; k >= 0; k = k - i) {
                comparacao[2]++;
                if (arr[k+i].chave >= arr[k].chave)
                    break;
                else {
                    tmp = arr[k].chave;
                    movimentacao[2]++;
                    arr[k].chave = arr[k+i].chave;
                    movimentacao[2]++;
                    arr[k+i].chave = tmp;
                    movimentacao[2]++;
                }
            }
        }
    }
}

// SWAP -> para o Quickshort e o Heapsort
void swap(int *a, int *b, unsigned long *comparacao, unsigned long *movimentacao) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/*
// Quicksort
int partition(Registro *arr, int low, int high, unsigned long *comparacao, unsigned long *movimentacao) {
    int pivot = arr[high].chave;
    int i = (low - 1);
    for (int j = low; j <= high-1; j++) {
        comparacao[3]++;
        if (arr[j].chave < pivot) {
            comparacao[3]++;
            i++;
            swap(&arr[i].chave, &arr[j].chave, comparacao, movimentacao);
            movimentacao[3]++;
            movimentacao[3]++;
        }
    }
    swap(&arr[i+1].chave, &arr[high].chave, comparacao, movimentacao);
    movimentacao[3]++;
    movimentacao[3]++;
    return i+1;
}

void quick_sort(Registro *arr, int low, int high, unsigned long *comparacao, unsigned long *movimentacao) {
    if (low < high) {
        comparacao[3]++;
        int pi = partition(arr, low, high, comparacao, movimentacao);
        quick_sort(arr, low, pi - 1, comparacao, movimentacao);
        quick_sort(arr, pi + 1, high, comparacao, movimentacao);
    }
} */

void troca(Registro vet[], int i, int j, unsigned long *comparacao, unsigned long *movimentacao)
{
	int aux = vet[i].chave;
    movimentacao[3]++;
	vet[i].chave = vet[j].chave;
    movimentacao[3]++;
	vet[j].chave = aux;
    movimentacao[3]++;

}

// particiona e retorna o índice do pivô
int particiona(Registro vet[], int inicio, int fim, unsigned long *comparacao, unsigned long *movimentacao)
{
	int pivo, pivo_indice, i;
	
	pivo = vet[fim].chave; // o pivô é sempre o último elemento
    movimentacao[3]++;
	pivo_indice = inicio;
    movimentacao[3]++;
	
	for(i = inicio; i < fim; i++)
	{
		// verifica se o elemento é <= ao pivô
        comparacao[3]++;
		if(vet[i].chave <= pivo)
		{
			// realiza a troca
			troca(vet, i, pivo_indice, comparacao, movimentacao);
			// incrementa o pivo_indice
			pivo_indice++;
		}
	}
	
	// troca o pivô
	troca(vet, pivo_indice, fim, comparacao, movimentacao);
	
	// retorna o índice do pivô
	return pivo_indice;
}

// escolhe um pivô aleatório para evitar o pior caso do quicksort
int particiona_random(Registro vet[], int inicio, int fim, unsigned long *comparacao, unsigned long *movimentacao)
{
	// seleciona um número entre fim (inclusive) e inicio (inclusive)
	int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
	
	// faz a troca para colocar o pivô no fim
	troca(vet, pivo_indice, fim, comparacao, movimentacao);
	// chama a particiona
	return particiona(vet, inicio, fim, comparacao, movimentacao);
}

void quick_sort(Registro vet[], int inicio, int fim, unsigned long *comparacao, unsigned long *movimentacao)
{
	if(inicio < fim)
	{
		// função particionar retorna o índice do pivô
		int pivo_indice = particiona_random(vet, inicio, fim, comparacao, movimentacao);
		
		// chamadas recursivas quick_sort
		quick_sort(vet, inicio, pivo_indice - 1, comparacao, movimentacao);
		quick_sort(vet, pivo_indice + 1, fim, comparacao, movimentacao);
	}
}

// Heapsort
void heapify(Registro *arr, int n, int i, unsigned long *comparacao, unsigned long *movimentacao) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l].chave > arr[largest].chave) {
        comparacao[4]++;
        largest = l;
    }
    if (r < n && arr[r].chave > arr[largest].chave) {
        comparacao[4]++;
        largest = r;
    }
    if (largest != i) {
        comparacao[4]++;
        swap(&arr[i].chave, &arr[largest].chave, comparacao, movimentacao);
        movimentacao[4]++;
        movimentacao[4]++;
        heapify(arr, n, largest, comparacao, movimentacao);
    }
}

void heap_sort(Registro *arr, int n, unsigned long *comparacao, unsigned long *movimentacao) {
    for (int i = n/2 - 1; i >= 0; i--) {
        comparacao[4]++;
        heapify(arr, n, i, comparacao, movimentacao);
    }
    for (int i = n-1; i >= 0; i--) {
        comparacao[4]++;
        swap(&arr[0].chave, &arr[i].chave, comparacao, movimentacao);
        movimentacao[4]++;
        movimentacao[4]++;
        heapify(arr, i, 0, comparacao, movimentacao);
    }
}

// Mergesort
void merge(Registro *arr, int l, int m, int r, unsigned long *comparacao, unsigned long *movimentacao) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) {
        comparacao[5]++;
        L[i] = arr[l + i].chave;
    }
    for (j = 0; j < n2; j++) {
        comparacao[5]++;
        R[j] = arr[m + 1 + j].chave;
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        comparacao[5]++;
        if (L[i] <= R[j]) {
            movimentacao[5]++;
            arr[k].chave = L[i];
            i++;
        }
        else {
            movimentacao[5]++;
            arr[k].chave = R[j];
            j++;
        }
        comparacao[5]++;
        k++;
    }
    while (i < n1) {
        comparacao[5]++;
        movimentacao[5]++;
        arr[k].chave = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        comparacao[5]++;
        movimentacao[5]++;
        arr[k].chave = R[j];
        j++;
        k++;
    }
}

void merge_sort(Registro *arr, int l, int r, unsigned long *comparacao, unsigned long *movimentacao) {
    if (l < r) {
        comparacao[5]++;
        int m = l + (r - l) / 2;
        merge_sort(arr, l, m, comparacao, movimentacao);
        merge_sort(arr, m + 1, r, comparacao, movimentacao);
        merge(arr, l, m, r, comparacao, movimentacao);
    }
}