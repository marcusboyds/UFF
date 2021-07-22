#include <stdio.h>

struct estudante {
    char nome[50];
    int idade;
    int id;
};


int main(){

    struct estudante estudantes;

    for (int i = 0; i < 5; i++)
    {
        
        printf("Nome: ");
        scanf("%s",estudantes[i].nome);

        printf("Idade: ");
        scanf("%d",&estudantes[i].idade);

        estudantes[i].id = i;
    }
     
    for (int i = 0; i < 5; i++){
    
        printf("NOME: %s\n",estudantes[i].nome);
        printf("IDADE: %d\n",estudantes[i].idade);
        printf("ID: %d\n",estudantes[i].id);
    }

    return 0;
}


    