#include "tad.c"

int zz(TAB *a){
    if (a == NULL) return 1;
    TAB* aux = a;
    while (aux != NULL){
        if (aux->dir != NULL && aux->esq != NULL) return 0;
        if (aux->dir != NULL) aux = aux->dir;
        else aux = aux->esq;
    }
    return 1;
}