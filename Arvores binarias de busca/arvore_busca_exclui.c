#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNoA {
    int chave;
    struct sNoA *esq;
    struct sNoA *dir;
} TNoA;

TNoA *exclui(TNoA *raiz, int chave) {
    //TODO: Implementar essa função
    //Ela recebe a raiz da árvore e a chave a ser excluída
    //Ela retorna ponteiro para a nova raiz
    if (raiz == NULL){
        printf("Não foi possível fazer a exclusão (raiz é nula)");
        return NULL;
    }
    TNoA* aux = raiz;
    TNoA* ant = aux;
    while (aux != NULL && aux->chave != chave){ //percorre ate o no da chave
        ant = aux;
        if (chave < aux->chave){
            aux = aux->esq;
        } else {
            aux = aux->dir;
        }
    }
    if (aux == NULL){ //caso a chave seja inválida
        printf("A chave nao foi encontrada");
        return raiz;
    }
    if (aux->dir == NULL && aux->esq == NULL){ //caso 1
        if (ant == aux) { //se o no excluido for a raiz, retorna null
            free(aux);
            return NULL;
        }
        if (ant->esq == aux){ //desconexão do no anterior
            ant->esq = NULL;
        } else {
            ant->dir = NULL;
        }
        free(aux);
        return raiz;
    } else if (aux->dir == NULL || aux->esq == NULL){ //caso 2
        if (aux == ant){
            if (aux->esq == NULL) raiz = aux->dir;
            else raiz = aux->esq;
            free(aux);
            return raiz;
        }
        if (aux->esq == NULL){
            if (ant->esq == aux){
                ant->esq = aux->dir;
            } else {
                ant->dir = aux->dir;
            }
        } else{
            if (ant->esq == aux){
                ant->esq = aux->esq;
            } else {
                ant->dir = aux->esq;
            }
        }
        free(aux);
        return raiz;
    } else{ //caso 3
        TNoA* maior_esq = aux->esq;
        while (maior_esq->dir != NULL){
            maior_esq = maior_esq->dir;
        }
        aux->chave = maior_esq->chave;
        aux->esq = exclui(aux->esq, maior_esq->chave);
        return raiz;
    }

}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%d\n", nodo->chave);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *insere(TNoA *no, int chave) {
    if (no == NULL) {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->esq = NULL;
        no->dir = NULL;
    } else if (chave < (no->chave))
        no->esq = insere(no->esq, chave);
    else if (chave > (no->chave)) {
        no->dir = insere(no->dir, chave);
    } else {
        printf("Inserção inválida! ");
        exit(1);
    }
    return no;
}

int main(void) {

    /* A função main lê os dados de entrada, cria a árvore e chama a função solicitada no problema
     * depois imprime o resultado solicitado
     * ELA NÃO DEVE SER MODIFICADA
     * */
    TNoA *raiz;
    raiz = NULL;

    char l[100];
    char delimitador[] = "-";
    char *ptr;
    int valor;

    /* lê valores para criar a arvore
     * valores devem ser informados separados por traço
     * exemplo: 1-3-5-2-7-9-21-6 */
    scanf("%s", l);
    //quebra a string de entrada
    ptr = strtok(l, delimitador);
    while(ptr != NULL) {
        valor = atoi(ptr);
        raiz = insere(raiz, valor);
        ptr = strtok(NULL, delimitador);
    }

    //le valor a ser excluido
    scanf("%d", &valor);
    //Chama função
    raiz = exclui(raiz, valor);
    imprime(raiz, 0);
};