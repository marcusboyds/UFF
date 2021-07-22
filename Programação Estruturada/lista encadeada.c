#include <stdio.h>
#include <stdlib.h>

struct node{
    int informacao;
    struct node* prox;
};

void printarLista(struct node* cabeca){
  while (cabeca != NULL){
    printf("%d, ",cabeca->informacao);
    cabeca = cabeca->prox;
    }
}


int main(){

    //Declarar a lista encadeada.
    
    struct node * cabeca; 
    struct node * primeiro = NULL;
    struct node * segundo = NULL;
    struct node * terceiro = NULL;

    //Alocar memoria pra lista.

    primeiro = (struct node*) malloc(sizeof(struct node));
    segundo = (struct node*) malloc(sizeof(struct node));
    terceiro = (struct node*) malloc(sizeof(struct node));

    //Preencher o conteudo de cada lista.
    primeiro->informacao = 3;
    segundo->informacao = 6;
    terceiro->informacao = 9;

    //Linkar as listas
    primeiro->prox = segundo;
    segundo->prox = terceiro;
    terceiro->prox = NULL;
    
    //Atualizar a cabeça da lista
    cabeca = primeiro;
    
    printf("Primeira Lista: ");
    printarLista(cabeca);
    
    
    
    
    //# Adicionar elementos
    
    //1. Adicionar novo nó no inicio
    struct node * novoNo;
    novoNo = (struct node*) malloc(sizeof(struct node));
    novoNo->informacao = 7;
    novoNo->prox = cabeca;
    
    //Atualizar a cabeça da lista
    cabeca = novoNo;

    //2. Adicionar novo nó no final
    struct node * velhoNo;
    velhoNo = (struct node*) malloc(sizeof(struct node));
    velhoNo->informacao = 8;
    velhoNo->prox = NULL;
    
    //3. Achar o ultimo elemento da lista encadeada e linkar ele no velhoNO
    struct node* temp = cabeca;
    while (temp->prox != NULL){ 
      temp = temp->prox;
      }
    temp->prox = velhoNo;
    
    printf("Nova Lista: ");
    printarLista(cabeca);

    //Adicionar elemento no meio da lista.
    struct node* outroNo = (struct node*) malloc(sizeof(struct node));
    outroNo->informacao = 20;
    
    struct node* te = cabeca;
    for (int i=0; i < 2; i++){
      if (te->prox != NULL){
          te = te->prox;
        }
    }
    
    outroNo->prox = te->prox;
    te->prox = outroNo; 

    printf("Nova Lista: ");
    printarLista(cabeca);



    //# Deletar elementos
    
    //Deletar o primeiro
    cabeca = cabeca->prox;

    //Deletar o ultimo
    struct node* tem = cabeca;
    while(tem->prox->prox != NULL){
        tem = tem->prox;
      }

    tem->prox = NULL;
    
    //Deletar no meio da lista
    struct node* tempo = cabeca;
    for(int i=0; i< 2; i++) {
    if(tempo->prox!=NULL) {
        tempo = tempo->prox;
        }
     }

    tempo->prox = tempo->prox->prox;

    return 0;
}