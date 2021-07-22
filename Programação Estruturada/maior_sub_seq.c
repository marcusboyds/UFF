#include <stdio.h>

int analiseSub(int *lista, int n){

  int maior_sub_seq = 1;
  int sub_seq_atual = 0;  

    for (int i = 0; i < n; i++){
      if (lista[i] == lista[i+1]){
        sub_seq_atual++;
        maior_sub_seq = sub_seq_atual +1;
      }
      else{
        sub_seq_atual = 0;
      }
    }
  return maior_sub_seq;
}

int main(void) {
    int lista[] = {1,2,3,4,4,4,4,5,7};
    printf("%d \n",analiseSub(lista, 9));
}