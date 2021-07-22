#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct aluno{
    int mat;
    char nome[40];
    float cr;
};

typedef int* PInt;


int modicar_cr(struct aluno *al){
    al->cr = al->cr+1.0;
}

int main(){
    struct aluno aluno1;
    struct aluno aluno2;

    char nome[40] = "anselmo";

    aluno1.mat = 11111;
    aluno1.cr = 7.0f;
    strcpy(aluno1.nome,"anselmo");

    printf("\naluno1: [nome: %s][mat: %d][cr: %f]\n",aluno1.nome,aluno1.mat,aluno1.cr);

    modicar_cr(&aluno1);

    printf("\naluno1: [nome: %s][mat: %d][cr: %f]\n",aluno1.nome,aluno1.mat,aluno1.cr);

    aluno2 = aluno1;

    printf("\naluno2: [nome: %s][mat: %d][cr: %f]\n",aluno2.nome,aluno2.mat,aluno2.cr);

    printf("End aluno1: %p %p %p\n",&aluno1.nome,&aluno1.mat,&aluno1.cr);
    printf("End aluno2: %p %p %p\n",&aluno2.nome,&aluno2.mat,&aluno2.cr);

    strcpy(aluno1.nome,"antunes");

    printf("\naluno1: [nome: %s][mat: %d][cr: %f]\n",aluno1.nome,aluno1.mat,aluno1.cr);
    printf("\naluno2: [nome: %s][mat: %d][cr: %f]\n",aluno2.nome,aluno2.mat,aluno2.cr);

    int  a = 10;
    int *v = &a;
    PInt u = v;

    printf("a = %d (*v) = %d (*u) = %d",a,*v,*u);


}