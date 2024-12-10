#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa (int inicio, int fim, int v[]) {
    int pivo, j, k, aux;
    pivo = v[fim];
    j = inicio;
    for (k = inicio; k < fim; k++) {
        if (v[k] <= pivo) {
            aux = v[j];
            v[j] = v[k];
            v[k] = aux;
            j++;
        }
    }
    v[fim] = v[j];
    v[j] = pivo;
    return j;
}

void QuickSort (int inicio, int fim, int v[]){
    int pivo;
    if (inicio < fim) {
        pivo = Separa (inicio, fim, v);
        QuickSort (inicio, pivo - 1, v);
        QuickSort (pivo + 1, fim, v);
    }
}

int main() {
    const int tamBase = 20000;
    int i, j, k, contExec = 3, escala = 20;
    int v[tamBase * escala];
    clock_t inicio, fim;
    double tempoGasto = 0, tempoMedio = 0;

    srand(time(NULL));

    for (i = 0; i <= escala; i++) {
        printf("Tamanho: %d\n", (tamBase * i));

        for (j = 0; j < contExec; j++) {
            for (k = 0; k < (tamBase * i); k++) {
                v[k] = rand() % 101;
            }

            inicio = clock();

            QuickSort(0, (tamBase * i), v);

            fim = clock();

            tempoGasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
            tempoMedio += tempoGasto;

            printf("Tempo de execucao do vetor %d: %.2f\n", j + 1, tempoGasto);
        }

        tempoMedio /= contExec;

        printf("Media: %.2f\n\n", tempoMedio);

        tempoMedio = 0;
    }
}
