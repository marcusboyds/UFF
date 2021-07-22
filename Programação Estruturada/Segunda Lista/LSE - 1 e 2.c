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

    struct LSE* ponteiro = buscarNo(cabeca, 5);

    return 0;
}