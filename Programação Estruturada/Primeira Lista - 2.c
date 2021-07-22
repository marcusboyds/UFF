#include <stdio.h>

int main(void) {

    int vetorA[5];
    int vetorB[5];
    int intercessao[5];

    // Preencher vetor A
    for (int i = 0; i <= 3; i++)
    {
        printf("Preencher vetor A\n");
        scanf("%d",&vetorA[i]);
    }
    // Preencher vetor B
    for (int i = 0; i <= 3; i++)
    {
        printf("Preencher vetor B\n");
        scanf("%d",&vetorB[i]);
    }

    //Função que entra duas arrays e sai a intercessão 
    for (int i, k = 0; i <= 5; i++)
    {
        for (int j = 0; j < 5; i++)
        {
            if (vetorA[i] == vetorB[j])
            {
                intercessao[i] = vetorA[i];
                k++;
            }
            
        }
        
    }
    printf("A intercessao é: %d",intercessao[5]);
}