// Program to add two distances (feet-inch)
#include <stdio.h>

struct Aluno
{
    float notas_t1[10] = {3.4, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 10};
    float notas_t2[10] = {5.5, 6.6, 7.7, 8.8, 9.9, 8.8, 7.7, 10};
    float media;
} alunos[10]



int *premiados(int qtd_de_participantes, int *inscricoes, float *notas_t1, int peso_t1, float *notas_t2, int peso_t2, int *os_picas){

    //Obter a média das notas
    int soma_dos_pesos = int peso_notas1 + peso_notas2;
    int soma_notas1 = 0;
    int soma_notas2 = 0;

    for (int i=0; i<qtd_de_participantes; i++){
        soma_notas1 += notas_teste1[i];
        soma_notas2 += notate2[i];
    }

    int media = ((soma_notas1 * peso_t1) + (soma_notas2 * peso_notast2))/ soma_dos_pesos;

    //Obter a media de cada aluno
    int media_do_participante = 0;
    float *alunos = (float *) malloc(qtd_de_participantes * sizeof(float));