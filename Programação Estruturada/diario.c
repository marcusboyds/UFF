#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int fechadura;
    char humor[2];
    char descricao[25];
    int dia;
    int id;
}diario;

int gerarChave(){
    int chave;
    printf("Escolha sua senha númerica: ");
    scanf("%d",&chave);
    return chave;
}

mostrarEntrada(int n_entrada, diario *ptr){

    int numero_de_busca = n_entrada;
    int contador = 0;
    int endereco_da_entrada = 0;
    
    //buscar entrada
    for(int i=0; numero_de_busca != (ptr+i)->id; i++){ 
        contador++;
        endereco_da_entrada = i;
        if(contador==2){
            printf("Não foi encontrado essa entrada. Digite outra: ");
            scanf("%d", &numero_de_busca);
            contador=0;
            i=0;
        }
    }

    //Pedir senha 
    int senha = 0;
    printf("Entrada encontrada! Digite a senha da entrada %d: ",numero_de_busca);
    scanf("%d",&senha);

    //Verificar senha
    while (senha != (ptr+endereco_da_entrada)->fechadura){
        printf("Senha errada, digite outra: ");
        scanf("%d",&senha);
    }
    
    //Mostrar informações
    printf("Entrada do Diário %d:\n",n_entrada);
    printf("1. Humor: %s\n",(ptr+endereco_da_entrada)->humor);
    printf("2. Dia: %d\n",(ptr+endereco_da_entrada)->dia);
    printf("3. Descricao: %s",(ptr+endereco_da_entrada)->descricao);

}

  
diario setEntradaDoDiario(char *humor, char *descricao, int dia, int id){
    diario dados;
    dados.dia = dia;
    dados.id = id;
    strcpy(dados.humor, humor);
    strcpy(dados.descricao, descricao);
    return dados;
}


//Programa Principal
int main(){
    //Informações do diário.
    int numero_de_entradas;
    struct diario* entradas = malloc(numero_de_entradas * sizeof(struct diario))

    //Introdução do programa
    printf("Seja bem vindo ao diario, quantas entradas deseja alocar? \n");
    scanf("%d",&numero_de_entradas)
    
    //Gerar chave e guardar na fechadura 
    int chave = gerarChave();
    entradas[0].fechadura = chave;  //mesma chave pras duas fechaduras!!
    entradas[1].fechadura = chave;

    //Mostrar a informação da entrada pedida
    int n_entrada;
    printf("Deseja abrir o diário em qual entrada?: ");
    scanf("%d",&n_entrada);

    mostrarEntrada(n_entrada, entradas);
    
    return 0;
}