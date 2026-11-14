#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include "arvore_b_mais.h"

void imprime_arquivos() {
    int i;
    //Imprime arquivo de metadados
    FILE *arq_m = fopen("metadados.dat", "rb");
    TMetadados *m = le_metadados(arq_m);
    printf("*** Arquivo de Metadados ***\n");
    imprime_metadados(m);
    fclose(arq_m);

    //Imprime arquivo de índice (nós internos da árvore)
    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_i = fopen("indice.dat", "rb");
    printf("\n\n*** Arquivo de Indice ***\n");
    i = 0;
    TNoInterno *ni = le_no_interno(m->d, arq_i);
    while (ni != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_interno(m->d));
        imprime_no_interno(m->d, ni);
        ni = le_no_interno(m->d, arq_i);
        i += 1;
    }
    fclose(arq_i);

    //Imprime arquivo de dados (nós folha da árvore)
    //A leitura não segue ordem específica -- os nós são lidos na ordem em que foram gravados no arquivo
    FILE *arq_d = fopen("clientes.dat", "rb");
    printf("\n*** Arquivo de Dados ***\n");
    i = 0;
    TNoFolha *nf = le_no_folha(m->d, arq_d);
    while (nf != NULL) {
        printf("(((Endereco %d)))\n", i * tamanho_no_folha(m->d));
        imprime_no_folha(m->d, nf);
        nf = le_no_folha(m->d, arq_d);
        i += 1;
    }
    fclose(arq_d);
}

/*
 * Executa busca em Arquivos utilizando Arvore B+
 * Assumir que ponteiros para NULL têm valor -1
 *
 * chave: chave do cliente que esta sendo buscado
 * nome_arquivo_metadados: nome do arquivo binário que contem os metadados
 * nome_arquivo_indice: nome do arquivo binário de indice (que contem os nohs internos da arvore B+)
 * nome_arquivo_dados: nome do arquivo binário de dados (que contem as folhas da arvore B+)
 *
 * Retorna ponteiro para nó em que a chave está ou deveria estar
 */
int busca_indice(int chave, FILE* arq_indice, int d, int pt_no){
    fseek(arq_indice, pt_no, SEEK_SET);
    TNoInterno *no_interno = le_no_interno(d, arq_indice);
    imprime_no_interno(d, no_interno);

    int i=0;
    while (i < no_interno->m && chave > no_interno->chaves[i]){
        i++;
    }

    int novo_no;
    if (i < no_interno->m && chave == no_interno->chaves[i]){
        novo_no = no_interno->p[i+1];
        //imprime_no_interno(d, novo_no);
    } else{
        novo_no = no_interno->p[i];
        //imprime_no_interno(d, novo_no);
    }

    if (no_interno->aponta_folha == 1){
        libera_no_interno(no_interno);
        return novo_no;
    }
    libera_no_interno(no_interno);
    return busca_indice(chave, arq_indice, d, novo_no);
}

int busca_folha(int chave, FILE *arq_dados, int d, int pt_no){
    fseek(arq_dados, pt_no, SEEK_SET);
    TNoFolha *no_folha = le_no_folha(d, arq_dados);
    imprime_no_folha(d, no_folha);

    libera_no_folha(d, no_folha);
    return pt_no;
}


int busca(int chave, char *nome_arquivo_metadados, char *nome_arquivo_indice, char *nome_arquivo_dados)
{
	//TODO: Implementar essa função
    TMetadados* metadados = le_arq_metadados(nome_arquivo_metadados);
    int raiz = metadados->pont_raiz;
    if (raiz == -1){
        free(metadados);
        return -1;
    }
    int indice;
    if (metadados->raiz_folha == 1){
        indice = raiz;
    } else {
        FILE *arq_indice = fopen(nome_arquivo_indice, "rb");
        if (arq_indice == NULL){
            //printf("Erro ao abrir o arquivo de indice\n");
            free(metadados);
            return -1;
        }
        indice = busca_indice(chave, arq_indice, metadados->d, raiz);
        fclose(arq_indice);   
    }
    FILE *arq_dados = fopen(nome_arquivo_dados, "rb");
    if (arq_dados == NULL){
        //printf("Erro ao abrir o arquivo de dados\n");
        free(metadados);
        return -1;
    }
    int pt_no = busca_folha(chave, arq_dados, metadados->d, indice);
    fclose(arq_dados);
    free(metadados);
    return pt_no;
}

int main () {
    //Descomente essa linha de código caso deseje imprimir o conteúdo dos arquivos de entrada para analisar
    //o comportamento da sua implementação

    //imprime_arquivos();

    /* Le chave a ser buscada */
    int chave;

    scanf("%d", &chave);

    //Chama função de busca
    int pont = busca(chave, "metadados.dat", "indice.dat", "clientes.dat");

    //Imprime resultado da função
    printf("RESULTADO DA BUSCA: %d\n", pont);
}
