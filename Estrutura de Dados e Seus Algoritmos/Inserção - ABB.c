#include <stdio.h>
#include <stdlib.h>

typedef struct sNoA {
int chave;
struct sNoA* esq;
struct sNoA* dir;
} TNoA;

TNoA* insere(TNoA *no, int chave){
    // Se o no estiver vazio
    if (no == NULL)
    {
        no = (TNoA *) malloc(sizeof(TNoA));
        no->chave = chave;
        no->dir = NULL;
        no->esq = NULL;
    } 
    else if (chave < no->chave) {no->esq = insere(no->esq, chave);}
    else if (chave > no->chave) {no->dir = insere(no->dir, chave);}
    else
    {
        printf("Insercao Invalida!"); //Chave já existe
        exit(1);
    }
    
    return no;
}

int main(){

    //Exercício 1
    TNoA *arvore1;
    arvore1 = NULL;

    arvore1 = insere(arvore1, 25);
    arvore1 = insere(arvore1, 22);
    arvore1 = insere(arvore1, 40);
    arvore1 = insere(arvore1, 30);
    arvore1 = insere(arvore1, 45);
    arvore1 = insere(arvore1, 27);
    arvore1 = insere(arvore1, 20);
    arvore1 = insere(arvore1, 21);
    arvore1 = insere(arvore1, 48);

    //Exercicio 2
    TNoA *arvore2;
    arvore2 = NULL;

    arvore2 = insere(arvore2, 40);
    arvore2 = insere(arvore2, 25);
    arvore2 = insere(arvore2, 20);
    arvore2 = insere(arvore2, 30);
    arvore2 = insere(arvore2, 45);
    arvore2 = insere(arvore2, 27);
    arvore2 = insere(arvore2, 22);
    arvore2 = insere(arvore2, 21);
    arvore2 = insere(arvore2, 48);
      

    return 0;
}