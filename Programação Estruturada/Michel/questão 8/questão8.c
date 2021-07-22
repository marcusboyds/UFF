#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int len(char *nome_Arquivo){
    FILE *arquivo;
    int tamanho = 0;

    char c, letra = "\n";

    arquivo = fopen(nome_Arquivo, "r");

    while (fread(&c, sizeof(char), 1, arq))
    {
        if (c == letra)
        {
            tamanho++
        }
    }

    fclose(arquivo);
    
    return tamanho;
}

int main(){

    FILE *ptr_arquivo;
    int numero;
    int *lista;
    int qtd_numeros = len("numeros.txt");

    //1. Abrir arquivo
    ptr_arquivo = fopen("numeros.txt","r");
   
    //2. Criar e alocar lista onde vão estar os números
    lista = (int*) malloc(qtd_numeros * sizeof(int));

    //3. Colocar os números na lista
    for (int i=0; i < qtd_numeros; i++)
    {
        fscanf(ptr_arquivo, "%d", &numero);
        (lista+i) = numero;
    }
    

    // Fechar arquivo
    fclose(ptr_arquivo);

    return 0;
}