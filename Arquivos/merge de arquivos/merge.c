#include <stdio.h>

void imprime_arquivo(char *nomeArq){
    FILE *arq; //declara ponteiro para arquivo
    //abre arquivo para leitura
    arq = fopen(nomeArq, "r");
    if (arq != NULL){// checa se não deu erro na abertura do arquivo
        char s[10];
        fscanf(arq, "%s", s);
        while (!feof(arq)) {//testa se chegou ao final do arquivo
            printf("%s\n", s);
            fscanf(arq, "%s", s);
        }
        fclose(arq); //fecha arquivo
    }
    else printf("Erro ao abrir arquivo\n");
}

void merge(char *nomeArq1, char *nomeArq2, char *nomeArqMerge) {
    //TODO: Implementar essa função
    FILE *arq1 = fopen(nomeArq1, "r");
    FILE *arq2 = fopen(nomeArq2, "r");
    FILE *arq3 = fopen(nomeArqMerge, "w");
    if (arq1 == NULL || arq2 == NULL || arq3 == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        if (arq1 != NULL) fclose(arq1);
        if (arq2 != NULL) fclose(arq2);
        if (arq3 != NULL) fclose(arq3);
        return;
    }
    int n, m;
    int cursor1 = fscanf(arq1, "%d", &n);
    int cursor2 = fscanf(arq2, "%d", &m);
    while (cursor1 == 1 && cursor2 == 1){
        if (n == m){
            fprintf(arq3, "%d\n", n);
            cursor1 = fscanf(arq1, "%d", &n);
            cursor2 = fscanf(arq2, "%d", &m);
        }
        else if (n < m){
            fprintf(arq3, "%d\n", n);
            cursor1 = fscanf(arq1, "%d", &n);
        } else {
            fprintf(arq3, "%d\n", m);
            cursor2 = fscanf(arq2, "%d", &m);
        }
    }
    while (cursor1==1){
        fprintf(arq3, "%d\n", n);
        cursor1 = fscanf(arq1, "%d", &n);
    }
    while (cursor2==1){
        fprintf(arq3, "%d\n", m);
        cursor2 = fscanf(arq2, "%d", &m);
    }
    fclose(arq1);
    fclose(arq2);
    fclose(arq3);
}

int main(int argc, char **argv) {
    merge("numeros1.txt", "numeros2.txt", "merge.txt");
    imprime_arquivo("merge.txt");
}