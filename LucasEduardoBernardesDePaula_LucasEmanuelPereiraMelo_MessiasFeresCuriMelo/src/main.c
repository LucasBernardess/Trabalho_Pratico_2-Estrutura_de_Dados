#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "registro.h"

// Main
int main() {
    // Variavéis utilizadas ao decorrer do projeto
    int crescente, decrescente;
    float time_total[6], start, end, cpu_time; // Variáveis relacionadas a medição do tempo
    unsigned long comparacao[6], movimentacao[6];

    // Instanciando a Struct Registro
    Registro *arr = (Registro*)malloc(TAM*sizeof(Registro)); // Struct geral
    Registro *temp = (Registro*)malloc(TAM*sizeof(Registro)); // Struct temporária

    // Inicializando as variáveis com valor 0
    for(int i = 0; i<6; i++){
        time_total[i] = 0;
        comparacao[i] = 0;
        movimentacao[i] = 0;
    }

    srand(time(NULL)); // Faz a função rand gerar novos valores sempre que executado

    for (int i = 0; i < 10; i++) {
        switch (3) { // Definir através do número qual ordem deseja executar
            case 1: // Ordem Aleatório
                for (int j = 0; j < TAM; j++) {
                    temp[j].chave = rand() % TAM; 
                }
                break;
            case 2: // Ordem Crescente
                crescente = rand() % TAM;
                for (int j = 0; j < TAM; j++, crescente++) {
                    temp[j].chave = crescente; 
                }
                break;
            case 3: // Ordem Decrescente
                decrescente = rand() % 10*TAM;
                for (int j = 0; j < TAM; j++, decrescente--) {
                    temp[j].chave = decrescente; 
                }
                break;
            default:
                printf("Números não definidos\n");
                break;
        }
        
    // Funções de Ordenação
    // Seleção
        for(int j = 0; j<TAM; j++){ // Resetando valores
            arr[j].chave = temp[j].chave;
        }
        start = clock(); // Início clock
        selection_sort(arr, TAM, comparacao, movimentacao);
        end = clock(); // Fim clock
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC; // Tempo de execução
        time_total[0] += cpu_time;

    // Inserção
        for(int j = 0; j<TAM; j++){ // Resetando valores
            arr[j].chave = temp[j].chave;
        }
        start = clock(); // Início clock
        insertion_sort(arr, TAM, comparacao, movimentacao);
        end = clock(); // Fim clock
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC; // Tempo de execução
        time_total[1] += cpu_time;

    // Shellsort
        for(int j = 0; j<TAM; j++){ // Resetando valores
            arr[j].chave = temp[j].chave;
        }
        start = clock(); // Início clock
        shell_sort(arr, TAM, comparacao, movimentacao);
        end = clock(); // Fim clock
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC; // Tempo de execução
        time_total[2] += cpu_time;

    // Quicksort
        for(int j = 0; j<TAM; j++){ // Resetando valores
            arr[j].chave = temp[j].chave;
        }
        start = clock(); // Início clock
        quick_sort(arr, 0, TAM - 1, comparacao, movimentacao);
        end = clock(); // Fim clock
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC; // Tempo de execução
        time_total[3] += cpu_time;

    // Heapsort
        for(int j = 0; j<TAM; j++){ // Resetando valores
            arr[j].chave = temp[j].chave;
        }
        start = clock(); // Início clock
        heap_sort(arr, TAM, comparacao, movimentacao);
        end = clock(); // Fim clock
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC; // Tempo de execução
        time_total[4] += cpu_time;

    // Mergesort
        for(int j = 0; j<TAM; j++){ // Resetando valores
            arr[j].chave = temp[j].chave;
        }
        start = clock(); // Início clock
        merge_sort(arr, 0, TAM - 1, comparacao, movimentacao);
        end = clock(); // Fim clock
        cpu_time = ((double)end- start)/CLOCKS_PER_SEC; // Tempo de execução
        time_total[5] += cpu_time;
    }

    // Exibição dos dados coletados
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