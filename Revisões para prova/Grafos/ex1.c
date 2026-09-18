#include "tad.c"

int na(TGrafo *g){
    if (g == NULL) return 0;
    int a = 0;
    while (g != NULL){
        TVizinho *v = g->primeiro_vizinho;
        while(v != NULL){
            a++;
            v = v->prox;
        }
        g = g->prox;
    }
    return a;
}