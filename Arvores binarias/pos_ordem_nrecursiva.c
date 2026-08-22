#include "arvore-binaria.c"

typedef struct No {
    TNoA* a;
    struct No *prox;
} TNoP;

typedef struct {
    TNoP* top;
} Pilha;

void iniciarPilha(Pilha* p){
    p->top = NULL;
}

void pushPilha(Pilha *p, TNoA* a){
    TNoP* novo = (TNoP*) malloc(sizeof(TNoP));
    novo->a = a;
    novo->prox = p->top;
    p->top = novo;
}

TNoA* popPilha(Pilha* p){
    if (p->top == NULL){
        printf("Pilha vazia!");
        return NULL;
    }
    TNoP *aux = p->top;
    TNoA* a = aux->a;
    p->top = aux->prox;
    free(aux);

    return a;
}

void pos_ordem(TNoA* a){
    if (a == NULL) return;
    Pilha p1, p2;
    iniciarPilha(&p1);
    iniciarPilha(&p2);

    pushPilha(&p1, a);
    while (p1.top != NULL) {
        TNoA* temp = popPilha(&p1);
        pushPilha(&p2, temp);
        if (temp->esq != NULL) {
            pushPilha(&p1, temp->esq);
        }
        if (temp->dir != NULL) {
            pushPilha(&p1, temp->dir);
        }
    }
    while (p2.top != NULL) {
        TNoA* temp = popPilha(&p2);
        printf("%c\n", temp->info);
    }
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
    pos_ordem(raiz);
};