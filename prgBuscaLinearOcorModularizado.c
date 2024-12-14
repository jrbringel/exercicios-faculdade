#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define TAM 20

// Realizar busca linear (ou sequencial)
// de dados em um array analisando ocorrências

void preencherArray(int v[]) {
    int i;

    for (i = 0; i < TAM; i++) {
        v[i] = rand() % 30;
    }
}

void imprimirArray(int v[]) {
    int i;

    for (i = 0; i < TAM; i++) {
        printf("%3d", v[i]);
    }
}

int buscarOcorrenciasArray(int v[], int n, int * p1, int * p2) {
    bool achei = false;
    int qtdOcor = 0;
    int posUltOcor;
    int posPrimOcor = -1;
    int i;

    for (i = 0; i < TAM; i++) {
        if (v[i] == n) {
            qtdOcor++;
            posUltOcor = i;

            if (posPrimOcor == -1)
                posPrimOcor = i;
        }
    }

    *p1 = posPrimOcor;
    *p2 = posUltOcor;
    return qtdOcor;
}

int main(void) {
    int v[TAM], n, qtdOcor, posPrimOcor, posUltOcor;

    srand(time(NULL));

    preencherArray(v);
    imprimirArray(v);

    printf("\n\nEntre com o inteiro a ser pesquisado: ");
    scanf("%d", &n);

    qtdOcor = buscarOcorrenciasArray(v, n, &posPrimOcor, &posUltOcor);

    if (qtdOcor == 0) {
        printf("\nO numero %d NAO existe no array.", n);
    } else {
        printf("\nO numero %d aparece no array %d vezes.", n, qtdOcor);
        printf("\nO numero %d apareceu a primeira vez na posicao %d.", n, posPrimOcor);
        printf("\nO numero %d apareceu a ultima vez na posicao %d.\n\n", n, posUltOcor);
    }

    return 0;
}
