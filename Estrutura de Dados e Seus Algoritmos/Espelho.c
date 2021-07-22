#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

TNoA* criarNo(value) {
  TNoA* newNode = malloc(sizeof(TNoA));
  newNode->info = value;
  newNode->esq = NULL;
  newNode->dir = NULL;

  return newNode;
}

// Insert on the left of the node
TNoA* inserirEsquerda(TNoA* root, int value) {
  root->esq = criarNo(value);
  return root->esq;
}

TNoA* inserirDireita(TNoA* root, int value) {
  root->dir = criarNo(value);
  return root->dir;
}

void espelho(TNoA *raiz) {
    //Setando o buffer
    char vz[1];
    *vz = raiz->esq->info;
    raiz->esq->info = raiz->dir->info;
    raiz->dir->info = *vz;
}

void imprimir(TNoA *raiz){
    printf("%c",raiz->info);
    printf("%c",raiz->esq->info);
    printf("%c",raiz->dir->info);
}


int main (void) {
    TNoA* raiz = NULL;
    raiz = criarNo('a');
    inserirDireita(raiz, 'c');
    inserirEsquerda(raiz, 'b');
    espelho(raiz);
    imprimir(raiz);

}

