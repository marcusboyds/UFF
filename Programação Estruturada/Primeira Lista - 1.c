#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // necessário p/ as funções rand() e srand()
#include<time.h> //necessário p/ função time()

int main(void){

    char start[2];
    int controle = 1;
    
    // Introdução do Jogo
    printf("Jogue Joken-pô: \n");
    printf("1. Pedra / 2. Papel / 3. Tesoura\n");
    printf("Digite 's' para começar: ");
    scanf("%s",start);

        printf("Aperte 0 para acabar o jogo\n");
        while (controle != 0) {

            srand(time(NULL));

            int c_usuario = 0;
            int c_maquina = 0;

            int usuario;
            int maquina = rand() % 3;

            printf("Escolha a sua ferramenta!: ");
            scanf("%d",&usuario);

            if (usuario == maquina) {
                printf("Empatou!");
            }
            else {
                rand()

                // Casos de Vitória ou Derrota

                if (usuario == 1 && maquina == 2) {
                    printf("Perdeu! Pedra foi enrolada pelo Papel\n");
                    c_maquina += 1;
                    printf("Placar = %d x %d\n",c_usuario,c_maquina);
                }
                if (usuario == 1 && maquina == 3) {
                    printf("Ganhou! Pedra amassou a Tesoura\n");
                    c_usuario += 1;
                    printf("Placar = %d x %d\n",c_usuario,c_maquina);
                }
                if (usuario == 2 && maquina == 1) {
                    printf("Ganhou! Papel enrolou a Pedra\n");
                    c_usuario += 1;
                    printf("Placar = %d x %d\n",c_usuario,c_maquina);
                }
                if (usuario == 2 && maquina == 3) {
                    printf("Ganhou! Papel amassou a Tesoura\n");
                    c_usuario += 1;
                    printf("Placar = %d x %d\n",c_usuario,c_maquina);
                }
                if (usuario == 3 && maquina == 1) {
                    printf("Perdeu! Tesoura foi amassada pela Pedra\n");
                    c_maquina += 1;
                    printf("Placar = %d x %d\n",c_usuario,c_maquina);
                }
                if (usuario == 3 && maquina == 2) {
                    printf("Perdeu! Tesoura cortou o Papel\n");
                    c_maquina += 1;
                    printf("Placar = %d x %d\n",c_usuario,c_maquina);
                }
            }
        

        
    }
    // Loop do jogo

}