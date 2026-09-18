#include "tad.c"

TAB* copia(TAB* a){
    if (a == NULL) return NULL;
    TAB* b = (TAB*) malloc(sizeof(TAB));
    b->info = a->info;
    b->esq = copia(a->esq);
    b->dir = copia(a->dir);

    return b;
}