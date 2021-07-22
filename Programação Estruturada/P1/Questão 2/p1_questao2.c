#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct mat_char{int n_lin;
                        int n_col;
                        char **elems;}Mat_char;



Mat_char * alocar_matriz_char(int n_lin, int n_col){
     //A ser implementada
}

Mat_char * desalocar_matriz_char(Mat_char *m){
    //A ser implementada
}

Mat_char *le_imagem(char *nome_arq){
    int n_lin,n_col;
    FILE * f = fopen(nome_arq,"r");
    if (!f){
        return NULL;
    }

    fscanf(f,"%d %d",&n_lin,&n_col);
    fgetc(f);

    Mat_char *imagem = alocar_matriz_char(n_lin,n_col);


    for (int i=0;i<n_lin;i++){
        for (int j=0;j<n_col;j++){
            fscanf(f,"%c",&(imagem->elems[i][j]));
        }
        fgetc(f);    
    }

    fclose(f);
    return imagem;

}

void imprimir_matriz(Mat_char *m){
    
    for (int i=0;i<m->n_lin;i++){
        for (int j=0;j<m->n_col;j++){
            printf("%c ",m->elems[i][j]);
        }
        printf("\n");
    }
}



int flood_fill(Mat_char *imagem, int i, int j, char cor_atual, char nova_cor){

      //A ser implementada
}


int main()
{
    char nome_imagem[40];


    Mat_char * imagem = le_imagem("imagem.txt");

    if (!imagem){
        printf("Imagem nao pode ser lida\n");
        exit(1);
    }
    
    int i = 5;
    int j = 5;
    char cor_atual = imagem->elems[i][j];
    char nova_cor = '5';

    imprimir_matriz(imagem);

    printf("----------------------------------------------------------------------\n");
    flood_fill(imagem,i,j,cor_atual,nova_cor);  
    printf("----------------------------------------------------------------------\n"); 

    imprimir_matriz(imagem);
    desalocar_matriz_char(imagem);

}
