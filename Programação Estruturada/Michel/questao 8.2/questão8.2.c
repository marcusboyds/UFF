#include <stdio.h>
#include <stdlib.h>

typedef struct _ALUNO{
    char nome[81];
    float nota1, nota2;
} Aluno;


void calcularMedia(Aluno *alunos){

}

int main(){
    
    int qtd_alunos;

    printf("Quantos alunos você deseja guardar?: ");
    scanf("%d",&qtd_alunos);
    
    Aluno *alunos = (Aluno*) malloc(qtd_alunos * sizeof(Aluno*));
    
    //Preencher ponteiro de alunos
    for (int i = 0; i < qtd_alunos; i++)
    {
        printf("Digite o nome, nota1 e nota2: ");
        scanf("%s %f %f",(alunos+i)->nome, (alunos+i)->nota1, (alunos+i)->nota2);
    }
    
}