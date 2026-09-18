#include "tad.c"

    int testek(TGrafo* g, int k){
        if (g == NULL) return 1;
        TGrafo* raiz = g;
        while (g != NULL){
            int c=0;
            TGrafo* aux = raiz;
            TVizinho* v1 = g->primeiro_vizinho;
            while (v1!= NULL){
                c++;
                v1 = v1->prox;
            }
            while (aux != NULL){
                TVizinho* v2 = aux->primeiro_vizinho;
                while (v2 != NULL){
                    if (v2->id_vizinho == g->id){
                        c++;
                        break;
                    }
                    v2 = v2->prox;
                }
                aux = aux->prox;
            }
            if (c != k) return 0;
            g = g->prox;
        }
        return 1;
    }