#include "tad.c"

int eh_par(int n){
    if (n % 2 == 0) return 1;
    return 0;
}

TAB* retira_pares(TAB* a) {
    if (a == NULL) return NULL;

    a->esq = retira_pares(a->esq);
    a->dir = retira_pares(a->dir);
    if (eh_par(a->info)) {
        if (a->esq == NULL && a->dir == NULL) {
            free(a);
            return NULL;
        }
        if (a->esq == NULL) {
            TAB* temp = a->dir;
            free(a);
            return temp;
        }
        if (a->dir == NULL) {
            TAB* temp = a->esq;
            free(a);
            return temp;
        }
        TAB* temp = a->dir;
        TAB* aux = temp;
        while (aux->esq != NULL) {
            aux = aux->esq;
        }
        aux->esq = a->esq;
        free(a);
        return temp;
    }
    return a;
}