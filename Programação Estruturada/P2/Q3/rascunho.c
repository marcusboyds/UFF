#include <stdio.h>
#include <stdlib.h>

typedef struct lde{
  int info;
  struct lde *ant, *prox;
} TLDE;

struct LSE{
    int data;
    struct LSE* prox;
};

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

struct LSE *LSE_copia_apos(struct LSE *l, int x){
    
    //Trava de Segurança
    if(l == NULL){return NULL;}

    struct LSE* temp, *no = l;
    
    while(no->data != x)
    {
        temp = no;
        no = no->prox;
        free(temp);
    }
    
  return no;
}

TLDE *TLDE_copia_ant(TLDE *l, int x){
    
    //Trava de Segurança
    if(l == NULL){return NULL;} 

    TLDE *temp, *no = l;
    
    while (no->prox != NULL)
    {
        no = no->prox;
    }
    
    while(no->info != x)
    {
        temp = no;
        no = no->ant;
        free(temp);
    }
    
    return no;
}

int main(){

    struct LSE *cabeca = NULL;
    
    push(&cabeca, 1);
    push(&cabeca, 2);
    push(&cabeca, 3);
    push(&cabeca, 4);
    push(&cabeca, 5);
    push(&cabeca, 6);
    
    struct LSE* novaLista = NULL;
    
    //Criar TLDE
    TLDE *a,*b,*c,*d,*e,*f;
    
    a = (struct TLDE*) malloc(sizeof(TLDE));
    b = (struct TLDE*) malloc(sizeof(TLDE));
    c = (struct TLDE*) malloc(sizeof(TLDE));
    d = (struct TLDE*) malloc(sizeof(TLDE));
    e = (struct TLDE*) malloc(sizeof(TLDE));
    f = (struct TLDE*) malloc(sizeof(TLDE));
  
    a->info = 1;
    b->info = 2;
    c->info = 3;
    d->info = 4;
    e->info = 5;
    f->info = 6;
    
    a->ant = NULL;
    a->prox = b;
    b->ant = a;
    b->prox = c;
    c->ant = b;
    c->prox = d;
    d->ant = c;
    d->prox = e;
    e->ant = d;
    e->prox = f;
    f->ant = e;
    f->prox = NULL;
  
    struct LSE* vem = LSE_copia_apos(cabeca, 4);
    
    TLDE* sai = TLDE_copia_ant(a, 4);
  
    return 0;
}