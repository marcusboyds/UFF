#include <stdio.h>
#include <stdlib.h>

struct cidades{
        char nome[50];
        int populacao;
        char tipo[1];
    };

int main(){

    int qnt;

    printf("Quantas cidades?: ");
    scanf("%d",&qnt);

    struct cidades * ptrCidades;
    ptrCidades = (struct cidades*)malloc(qnt * sizeof(struct cidades));

    for (int i = 0; i < qnt; i++)
    {
        printf("Nome: ");
        scanf("%s",(ptrCidades + i)->nome);

        printf("Populacao: ");
        scanf("%d",&(ptrCidades + i)->populacao);

        printf("Tipo: ");
        scanf("%s",(ptrCidades + i)->tipo);
    }
    
    for (int i = 0; i < qnt; i++){
        printf("NOME: %s\n",(ptrCidades+i)->nome);
        printf("POPULACAO: %d\n",(ptrCidades+i)->populacao);
        printf("TIPO: %s\n",(ptrCidades+i)->tipo);
    }
    
    free(ptrCidades);

    return 0;
}