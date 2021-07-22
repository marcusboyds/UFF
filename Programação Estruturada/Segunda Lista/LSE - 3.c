#include <stdio.h>
#include <stdlib.h>

struct LSE{
    int data;
    struct LSE* prox;
};

struct LSE* buscarNo(struct LSE* cabeca, int x){
    while (cabeca->data != x)
    {
        cabeca = cabeca->prox;
    }
    return cabeca;
}

void inserirInicio(struct LSE* cabeca, int x);{
    struct LSE *novoNo = (struct LSE*) malloc(sizeof(struct LSE));
    novoNo->data = x;
    novoNo->prox = cabeca;
}

void inserirFinal(struct LSE* cabeca, int x);{
    while (cabeca->prox != NULL)
    {
        cabeca = cabeca->prox;
    }
    struct LSE *novoNo = (struct LSE*) malloc(sizeof(struct LSE));
    cabeca->prox = novoNo
    novoNo->prox = NULL;
    novoNo->data = x;
}

void inserirMeio(struct LSE* cabeca, int x, int ordem);{
    //Inserir um numero na posição da fila que você desejar.
    for (int i = 1; i < ordem; i++)
    {
        cabeca = cabeca->prox;
    }
    struct LSE *novoNo = (struct LSE*) malloc(sizeof(struct LSE));
    novoNo->data = x;
    novoNo->prox = cabeca->prox;
    cabeca->prox = novoNo;
}

int main(){

    struct LSE *cabeca;
    struct LSE *um,*dois,*tres;

    //Alocar memoria
    um = (struct LSE*) malloc(sizeof(struct LSE));
    dois = (struct LSE*) malloc(sizeof(struct LSE));
    tres = (struct LSE*) malloc(sizeof(struct LSE));

    //Arranjar informação
    um->data = 3;
    dois->data = 4;
    tres->data = 5;

    //Conectar nós
    cabeca = um;
    um->prox = dois;
    dois->prox = tres;
    tres->prox = NULL;

    inserirInicio(cabeca, 5);
    inserirFinal(cabeca, 8);
    inserirMeio(cabeca, 9, 3);
    
    return 0;
}