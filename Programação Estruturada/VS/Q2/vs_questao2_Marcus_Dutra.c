#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lc{
  char info[31];
  struct lc *prox;
} TLC;

TLC* TLC_cria();
TLC* TLC_insere(TLC *l, char *info);
TLC* TLC_insere_rec(TLC *l, char *info);
TLC* TLC_retira(TLC *l, char *info);
TLC* TLC_retira_rec(TLC *l, char *info);
void TLC_imprime(TLC *l);
void TLC_libera(TLC *l);
void TLC_executa(TLC *l, void (*visita)(const TLC *antes));

TLC * circulo_de_josephus(TLC **l,int n, int m){
    TLC *antes, *proximo;
    int i;
 
    proximo = antes = *l;
    while (antes->prox != antes)
    {
        for (i = 0; i < m - 1; i++)
        {
            proximo = antes;
            antes = antes->prox;
        }
        proximo->prox = antes->prox;
        printf("Removido o candidato: %s.\n", antes->info);
        free(antes);
        antes = proximo->prox;
    }
    *l = antes;
 
    return (antes);
}

int main(){
    TLC * l = TLC_cria();

    l = TLC_insere(l,"Maria");
    l = TLC_insere(l,"Joao");
    l = TLC_insere(l,"Paulo");
    l = TLC_insere(l,"Claudio");
    l = TLC_insere(l,"Carla");
    l = TLC_insere(l,"Pedro");
    l = TLC_insere(l,"Bruna");
    l = TLC_insere(l,"Marcio");
    l = TLC_insere(l,"Jose");
    l = TLC_insere(l,"Francisco");
    TLC_imprime(l);
    
    l = circulo_de_josephus(&l,10,5);

    printf("*********************************\n",l->info);
    printf("Vencedor: %s                     \n",l->info);
    printf("*********************************\n",l->info);
    

    TLC_libera(l);

}

TLC* TLC_cria(){
  return NULL;
}

TLC* _retira_rec(TLC *l, TLC * antes, char *info){

  // Se o nó foi encontrado
  if (strcmp(antes->info,info)==0){
        TLC * aux = antes->prox;
        free(antes);
        return aux;
  }
  // Se não for o último elemento da lista, tentar remover o elemento da lista começando
  // do elemento seguinte e atribua o endereço da lista resultante
  // ao campo próximo do elemento atual (antes) para garantir o encadeamento
  else if (antes!=l){
    antes->prox = _retira_rec(l,antes->prox,info);
    return antes;
  }
  else{
    return antes;
  }// É o ultimo elemento e devemos retornar a lista atual;
}


TLC * TLC_retira_rec(TLC *l,char *info){
  if (!l) {//Se a lista for vazia, nada deve ser feito
    return NULL;
  }
  else if (strcmp(l->info,info)==0){//Se o primeiro nó e o procurado
    if (l==l->prox){ //Se ele for único remover
        free(l);
        return NULL;
    }
    else{ //senão, a nova lista de sua remoção como último nó
          //da busca
        l = _retira_rec(l,l->prox,info);
    }
  }
  else{ // caso contrário, a lista a ser retornada é a cabeça concatenada com a remoção na cauda da lista
        l->prox = _retira_rec(l,l->prox,info);
  }
  return l;
}

TLC* _insere_rec(TLC *l, TLC * antes, char *info){

  if (antes == l){ //Inserção após o último elemento
    TLC* novo = (TLC*) malloc (sizeof(TLC));
    strcpy(novo->info, info);
    novo->prox = l;
    return novo;
  }
  else{
    // O nó atual deve ter como próximo a lista resultante da inserção na cauda
    antes->prox = _insere_rec(l,antes->prox,info);
    //Retornar a cabeça da lista atual
    return antes;
  }
}

TLC*  TLC_insere_rec(TLC * l, char *info){
  if (!l){//Inserção em lista vazia
    TLC* novo = (TLC*) malloc (sizeof(TLC));
    strcpy(novo->info, info);
    novo->prox = novo;
    return novo;
  }
  else{
    l->prox = _insere_rec(l,l->prox,info);
    return l;
  }
}

TLC* TLC_insere(TLC *l, char *info){
  TLC* novo = (TLC*) malloc (sizeof(TLC));
  strcpy(novo->info, info);
  if(!l){
    novo->prox = novo;
    return novo;
  }
  TLC *antes = l->prox, *ant = l;
  while(antes != l){
    ant = antes;
    antes = antes->prox;
  }
  novo->prox = l;
  ant->prox = novo;
  return l;
}

TLC* TLC_retira(TLC *l, char *info){
  //Se existir uma lista
  if (l){
    //Procurar  o elemento na lista e seu anterior caso existam
    TLC *ant = l, *antes = l->prox;
    while ( (antes!=l) && (strcmp(antes->info, info)!=0)){
      ant = antes;
      antes = antes->prox;
    } 
    //Se o elemento foi encontrado
    if (strcmp(antes->info, info)==0){
      //Se houver mais de um nó, aux recebe o próximo, caso contrário é permanece NULL
      if (antes!=antes->prox){
        ant->prox = antes->prox;
        if (antes==l){
          l = l->prox;
        }
      }
      else{ // (antes==antes->prox)
        l = NULL;
      }
      free(antes);
    }
  } 

  return l;

}
 
void TLC_imprime(TLC *l){
  printf("---------------------------\n");
  printf("Lista de candidatos\n");
  printf("---------------------------\n");
  if(l){
    printf("%s\n", l->info);
    TLC *antes = l->prox;
    while(antes != l){
      printf("%s\n", antes->info);
      antes = antes->prox;
    }
  }
  printf("---------------------------\n\n");
}

void TLC_libera(TLC *l){
  if(l){
    TLC *antes = l->prox;
    while(antes != l){
      TLC *temp = antes;
      antes = antes->prox;
      free(temp);
    }
    free(l);
  }
}