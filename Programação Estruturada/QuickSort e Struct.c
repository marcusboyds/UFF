#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct estudante
{
    float nota;
    char nome[50];
    int idade;
};

int compararNota(const void* a, const void* b){
    float primeiro = ((struct estudante*)a)->nota;
    float segundo = ((struct estudante*)b)->nota;
    return (primeiro-segundo);
}

int compararIdade(const void* a, const void* b){
    return ( ((struct estudante*)a)->idade - ((struct estudante*)b)->idade );
}

int compararNome(const void* a, const void* b){
    return strcmp(((struct estudante*)a)->nome, ((struct estudante*)b)->nome);
}

int main(){

    struct estudante estudantes[5];

    int idade[5] = {17,18,15,19,16};
    float nota[5] = {9.0, 9.5, 10.0, 6.5, 8.5};
    char nomes[][50] = {"Marcus","Joao","Maria","Eduardo","Jose"};

    //Preencher a struct estudante com dados e imprimir a lista dos estudantes
    printf("Lista Original: \n");
    printf("Aluno       Nota      Idade");
    for (int i = 0; i < 5; i++)
    {
        estudantes[i].idade = idade[i];
        estudantes[i].nota = nota[i];
        strcpy(estudantes[i].nome, nomes[i]);
        printf("%s       %f      %d",estudantes[i].nome, estudantes[i].nota, estudantes[i].idade);
    }
    
    //Ordernar por idade
    qsort(estudantes,  5, sizeof(int), compararIdade);
    printf("Lista Ordenada por IDADE: \n");
    printf("Aluno       Nota      Idade");
    for (int i = 0; i < 5; i++)
    {
        printf("%s       %f      %d",estudantes[i].nome, estudantes[i].nota, estudantes[i].idade);
    }
    
    //Ordernar por nota
    qsort(estudantes,  5, sizeof(float), compararNota);
    printf("Lista Ordenada por NOTA: \n");
    printf("Aluno       Nota      Idade");
    for (int i = 0; i < 5; i++)
    {
        printf("%s       %f      %d",estudantes[i].nome, estudantes[i].nota, estudantes[i].idade);
    }

    //Ordernar por nome
    qsort(estudantes,  5, sizeof(char), compararNome);
    printf("Lista Ordenada por NOME: \n");
    printf("Aluno       Nota      Idade");
    for (int i = 0; i < 5; i++)
    {
        printf("%s       %f      %d",estudantes[i].nome, estudantes[i].nota, estudantes[i].idade);
    }

    return 0;
}