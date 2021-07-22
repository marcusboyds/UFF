#include <stdio.h>

int geradorB(char **array_A[4][4], int **array_B[4][4],int i,int j);

int main(void){

    char array_A[4][4] = {{'*','0','*','*'},{'*','0','*','0'},{'*','*','0','*'},{'0','0','*','*'}};
    int i,j;
    i = 4;
    j = 4;
    int array_B[4][4];

    geradorB(array_A,array_B,i,j);

    for (int a = 0; a < i; a++)
    {
        for (int b = 0; b < j; b++)
        {
            printf("%d",array_B[a][b]);
        }
    }
}

int geradorB(char **array_A[4][4], int **array_B[4][4],int i,int j) {
        // Looping que irá passar por todos os elementos do array A
        for (int x = 0; x < i; x++)
        {
            for (int y = 0; y < j; y++)
            {
                // Looping que irá percorrer os pontos cardeais na vizinhaça de 8.
                for (int n = 0; n < j; n++) // 1. Oeste a Leste
                {
                    if (array_A[x][n] == '0') {
                        array_B[x][y]++;
                    } 
                }
                for (int m = 0; m < i; m++) // 1. Norte a Sul
                {
                    if (array_A[m][y] == '0'){
                        array_B[x][y]++;
                    } 
                }
            }
        }
        return array_B;
    }
    