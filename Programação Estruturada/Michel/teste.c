#include <stdio.h>
#include <stdlib.h>

int main(){


    // Declaramos um ponteiro(link para o endereço da memória) para o arquivo de nome: 'pf'
    FILE *pf;
    int *lista;
    int qtd_numeros = 5;

    lista = (int*) malloc(qtd_numeros * sizeof(int));

    //Abre o arquivo novamente para leitura
    pf = fopen("numeros.txt", "rb");

    // Le em conteudo o valor da variável armazenada anteriormente pf
    for (int i = 0; i < qtd_numeros; i++)
    {
        fread((ptr+i), sizeof(int), 5,pf);
    }
    
    
    // Imprime o conteúdo, se existir, do arquivo informado
    printf("\nO CONTEEDO DO ARQUIVO eh:\n %s \n", conteudo);

    fclose(pf);
    
    return(0);
}