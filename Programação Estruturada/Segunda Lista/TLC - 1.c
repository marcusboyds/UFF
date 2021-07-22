#include <stdlib.h>
#include <stdio.h>

typedef struct lc{
int data;
struct lc *prox;
} TLC;

TLC* ins_fim(TLC *l, int x){

    TLC* aux = l;

    while (aux->prox != l)
    {
        aux = aux->prox;
    }

    //Criar novo nó
    TLC* novoNo;
    novoNo = (struct lc*) malloc(sizeof(struct lc));

    //Encaixar as peças
    aux->prox = novoNo;
    novoNo->prox = l;
    novoNo->data = x;

}

void imprime(TLC *l){

    TLC* aux = l;

    printf("%d",aux->data);

    while (aux->prox != l)
    {
        aux = aux->prox;
        printf("%d",aux->data);
    }

}

TLC* busca(TLC *l, int x){
    TLC* aux = l;
    
    while (aux->data != x)
    {
        aux = aux->prox;
    }
    
    return printf("O número %d foi achado",aux->data);
}

TLC* retira(TLC *l, int x){
    TLC* aux = l;
        
    while (aux->data != x)
    {
        aux = aux->prox;
    }

    
}
    
int main(){

    TLC *cabeca, *um, *dois, *tres;

    //ALOCAR MEMORIA!

    um = (struct lc*) malloc(sizeof(struct lc));
    dois = (struct lc*) malloc(sizeof(struct lc));
    tres = (struct lc*) malloc(sizeof(struct lc));
    //SETAR DADOS!
    um->data = 4;
    dois->data = 5;
    tres->data = 6;

    //CONECTAR GERAL!

    cabeca = um;
    um->prox = dois;
    dois->prox = tres;
    tres->prox = um;

    ins_fim(cabeca,4);
    imprime(cabeca);
    busca(cabeca, 6);

    return 0;
}