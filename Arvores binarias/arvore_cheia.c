#include "arvore-binaria.c"

int nivel_folhas(TNoA* no, int nivel, int nivel_esperado){
    if (no == NULL){
        return 1;
    }
    if (no->esq == NULL && no->dir == NULL){
        return nivel == nivel_esperado;
    }    
    return nivel_folhas(no->esq, nivel + 1, nivel_esperado) && nivel_folhas(no->dir, nivel + 1, nivel_esperado);
}

int arvore_cheia(TNoA* no){
    if (no == NULL){
        return 1;
    }

    TNoA* aux = no;
    int nivel = 0;
    
    while (aux->esq != NULL){
        aux = aux->esq;
        nivel++;
    }

    return nivel_folhas(no, 0, nivel);    
}