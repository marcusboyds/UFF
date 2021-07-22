#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ALUNOS 50

typedef struct aluno{
    int mat;
    char nome[40];
    float cr;
}Aluno;



int comp_cr(const void *elem_0, const void *elem_1){
    //A ser implementada
}

int comp_mat(const void *elem_0, const void *elem_1){
    //A ser implementada
}

int comp_nome(const void *elem_0, const void *elem_1){
     //A ser implementada
}

int comp_cr_nome(const void *elem_0, const void *elem_1){
      //A ser implementada
}


void qs(Aluno *v, int n, int (*comp)(const void * elem_0,const void *elem_1)){
    //A ser implementada

}

Aluno criar_aluno(char nome[], int mat, float cr){
    Aluno aluno;
    strcpy(aluno.nome,nome);
    aluno.mat = mat;
    aluno.cr = cr;

    return aluno;
}

void imprimir_aluno(Aluno aluno){
    printf("Nome: %15s, matricula: %d , cr: %5.2f\n",aluno.nome,aluno.mat,aluno.cr);
}

void imprimir_alunos(Aluno *alunos, int num_alunos){
    for (int i=0;i<num_alunos;i++){
        imprimir_aluno(alunos[i]);
    }

}

int main (){

    Aluno *alunos = (Aluno*)malloc(MAX_ALUNOS*sizeof(Aluno));
    int num_alunos = 0;

    alunos[0] = criar_aluno("Joao", 1111, 8.6 );
    alunos[1] = criar_aluno("Maria", 2222, 8.9);
    alunos[2] = criar_aluno("Jose", 3333, 6.2);
    alunos[3] = criar_aluno("Marcos", 4444, 8.6);
    alunos[4] = criar_aluno("Carla", 5555, 9.7);
    alunos[5] = criar_aluno("Barbara", 6666, 8.0);
    alunos[6] = criar_aluno("Roger", 7777, 8.0);
    alunos[7] = criar_aluno("Fabio",8888, 6.2);
    alunos[8] = criar_aluno("Hugo",9999, 8.9);
    num_alunos = 9;

    printf("\nLista de alunos\n");
    imprimir_alunos(alunos,num_alunos);

    printf("\nLista de alunos ordenado por nome\n");
    qs(alunos, num_alunos, comp_nome);
    imprimir_alunos(alunos,num_alunos);

    printf("\nLista de alunos ordenada por cr\n");
    qs(alunos, num_alunos, comp_cr);
    imprimir_alunos(alunos,num_alunos);

    printf("\nLista de alunos ordenada por matricula\n");
    qs(alunos, num_alunos, comp_mat);
    imprimir_alunos(alunos,num_alunos);

    printf("\nLista de alunos ordenada por cr e depois nome \n");
    qs(alunos, num_alunos, comp_cr_nome);
    imprimir_alunos(alunos,num_alunos);



    free(alunos);

}