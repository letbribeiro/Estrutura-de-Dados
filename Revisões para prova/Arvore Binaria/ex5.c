#include "tad.c"

int igual(TAB* a1, TAB* a2){
    if (a1 == NULL && a2 == NULL) return 1;
    if (a1 == NULL || a2 == NULL) return 0;
    if (a1->info != a2->info) return 0;
    int igual_esq = igual(a1->esq, a2->esq);
    int igual_dir = igual(a1->dir, a2->dir);
    if (igual_esq == 1 && igual_dir == 1) return 1;
    return 0;
}