#include <stdio.h>

struct estudante {
    char nome[50];
    int idade;
}

//Prototipos das Funções
struct estudante coletarInformacao();

int main(){
    //Declarar a variável que vai conter a informação coleta
    struct estudante s;
    
    //Aqui em s como já foi declarado seu tipo (struct estudante)
    s = coletarInformacao();

    printf("Nome coletado: %s",s.nome);
    printf("Idade coletada: %d",s.idade);
}

struct estudante coletarInformacao(){

    struct estudante sample;

    printf("Nome: ");
    scanf("%s",&sample.nome);

    printf("Idade: ");
    scanf("%s",&sample.idade);

    return sample;
}