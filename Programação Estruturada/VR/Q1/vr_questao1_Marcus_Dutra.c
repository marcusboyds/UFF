#include<stdio.h>
#include<stdlib.h>


float soma_elem(float *vetor, int tamanho){
    
        //Trava de Segurança
        if (tamanho == 0)
        {
            return 0;
        }
        else if (tamanho == 1)
        {
            return vetor[0];
        }
    
        //Algoritmo.
        
        //1. Descobrir o meio
        int meio = tamanho / 2;
        
        //2. Calcular o Reajuste
        int reajuste = tamanho - meio;
        //3. Somar a esquerda
        float soma_da_esquerda = soma_elem(vetor, meio);
        //4. Somar a direita
        float soma_da_direita = soma_elem(vetor + meio, reajuste);
        //5. Soma total
        return soma_da_esquerda + soma_da_direita;
}

void imprime_vet(float *vet, int n){
    for (int i=0;i<n;i++){
        printf("%5.2f ",vet[i]);
    }
    printf("\n");
}

int teste0(){
    float vet[8] = {1.0f,1.0f,1.0f,1.0f};
    imprime_vet(vet,4);
    printf("Soma total dos elementos de vet: %f\n",soma_elem(vet,4));  
}

int teste1(){
    float vet[8] = {1.0f,2.0f,3.0f,4.0f,5.0f,6.0f,7.0f,8.0f};
    imprime_vet(vet,8);
    printf("Soma total dos elementos de vet: %f\n",soma_elem(vet,8));
}

int main (){
    teste0();
    teste1();
    return 0;
}