#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercalar(int inicio, int meio, int fim, int v[]) {
    int contInicio, contMeio, cont, *vTemp;

    vTemp = (int*)malloc(sizeof(int) * (fim - inicio));

    contInicio = inicio;
    contMeio = meio;
    cont = 0;

    while (contInicio < meio && contMeio < fim) {
        if (v[contInicio] < v[contMeio]) {
            vTemp[cont++] = v[contInicio++];
        } else {
            vTemp[cont++] = v[contMeio++];
        }
    }

    while (contInicio < meio) {
        vTemp[cont++] = v[contInicio++];
    }

    while (contMeio < fim) {
        vTemp[cont++] = v[contMeio++];
    }

    for (contInicio = inicio; contInicio < fim; contInicio++) {
        v[contInicio] = vTemp[contInicio - inicio];
    }

    free(vTemp);
}

void mergeSort(int inicio, int fim, int v[]) {
    if (inicio < fim - 1) {
        int meio = (inicio + fim) / 2;

        mergeSort(inicio, meio, v);
        mergeSort(meio, fim, v);
        intercalar(inicio, meio, fim, v);
    }
}

int main() {
    int tamBase = 20000, i, j, k, contExec = 3, escala = 20;
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

            mergeSort(0, (tamBase * i), v);

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
