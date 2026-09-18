#include "tad.c"

TABB* retira_impares(TABB* a){
    if (a == NULL) return NULL;
    
    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);

    if (a->info % 2 != 0){
        if (a->esq == NULL){
            TABB* temp = a->dir;
            free(a);
            return temp;
        }
        if (a->dir == NULL){
            TABB* temp = a->esq;
            free(a);
            return temp;
        }
        TABB* ant = a;
        TABB* aux = a->esq;
        while (aux != NULL){
            ant = aux;
            aux = aux->dir;
        }
        ant->info = aux->info;
        if (ant != a){
            ant->dir = aux->esq;
        } else {
            ant->esq = aux->dir;
        }
        free(aux);
    }
    return a;
}