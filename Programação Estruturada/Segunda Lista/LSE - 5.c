#include <stdio.h>
#include <stdlib.h>

struct LSE{
    int data;
    struct LSE* prox;
};

void append(struct LSE* cabeca, int x){
    struct LSE* novoNo;
    novoNo = (struct LSE*) malloc(sizeof(struct LSE));
    
    while (cabeca->prox != NULL)
    {
        cabeca = cabeca->prox;
    }
    
    cabeca->prox = novoNo;
    novoNo->data = x;
    novoNo->prox = NULL;

}

void push(struct LSE** cabeca_ref, int x){
    
    //1. Criar novo nó
    struct LSE* novoNo;
    novoNo = (struct LSE*) malloc(sizeof(struct LSE));
    //2. Setar dados
    novoNo->data = x;

    //3. Botar o proximo como a referencia da cabeça
    novoNo->prox = (*cabeca_ref);

    //4. Atualizar a cabeça da lista
    (*cabeca_ref) = novoNo;
}

struct LSE* copiarLista(struct LSE* cabeca){
   struct LSE* novaLista;

   while (cabeca != NULL)
   {
      push(&novaLista, cabeca->data);
      cabeca = cabeca->prox;
   }
   return novaLista;
}

int main(){

    struct LSE *cabeca = NULL;
    
    push(&cabeca, 4);
    push(&cabeca, 10);
    push(&cabeca, 7);
    
    struct LSE* novaLista = NULL;
    novaLista = copiarLista(cabeca);
    
    return 0;
}