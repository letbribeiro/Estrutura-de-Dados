#include "tad.c"

int conta_menores(TABB* a, int N){
    if (a == NULL) return 0;
    if (a->info < N){
        return 1+ conta_menores(a->dir, N) + conta_menores(a->esq, N);
    }
    return conta_menores(a->esq, N);
}

void preenche_vetor(TABB* a, int N, int* v, int* idx){
    if (a == NULL) return;

    preenche_vetor(a->esq, N, v, idx);
    if (a->info < N){
        v[*idx] = a->info;
        (*idx)++;
        preenche_vetor(a->dir, N, v, idx);
    }
}

int* mN(TABB* a, int N){
    if (a == NULL) return NULL;

    int qtd = conta_menores(a, N);
    if (qtd == 0) return NULL;

    int* v = (int*) malloc(sizeof(int) * qtd);
    int idx = 0;
    preenche_vetor(a, N, v, idx);
    return v;
}