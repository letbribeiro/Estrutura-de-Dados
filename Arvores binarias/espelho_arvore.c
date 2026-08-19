#include "arvore-binaria.c"

void espelho(TNoA* a){
    if (a != NULL){
        espelho(a->esq);
        espelho(a->dir);
        TNoA* aux = a->esq;
        a->esq = a->dir;
        a->dir = aux;
    }
}