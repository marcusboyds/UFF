#include <stdio.h>
#include <stdlib.h>

struct LSE{
    int data;
    struct LSE* prox;
};


//Função de Busca
struct LSE* buscarNo(struct LSE* cabeca, int x){
    while (cabeca->data != x)
    {
        cabeca = cabeca->prox;
    }
    return cabeca;
}

//Função de Inserção
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

//Funções de Remoção
struct LSE* removerNo(struct LSE* cabeca, int x){

    struct LSE* aux = cabeca;
    int contador = 0;

    while (cabeca->data != x)
    {
        cabeca = cabeca->prox;
        contador++;
    }
    
    //Fazer o ponteiro auxiliar andar até uma posição ANTES da cabeca.
    for (int i=0; i<contador-1; i++){
        aux = aux->prox;
      }
    aux->prox = cabeca->prox;
    
    free(cabeca);
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

    removerNo(cabeca, 5);

    return 0;
}