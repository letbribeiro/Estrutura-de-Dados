#include "tad.c"

TAB* espelho(TAB* a){
    if (a == NULL) return NULL;

    TAB* e = (TAB*) malloc(sizeof(TAB));
    e->info = a->info;
    e->esq = espelho(a->dir);
    e->dir = espelho(a->esq);
    return e;    
}