#include "Matriz.h"

void Cria_Matriz(int Tamanho_matriz, int **matriz){
    srand(time(NULL));

    int i = 0, j = 0;
    for(i = 0; i < Tamanho_matriz; i++){
        for(j = 0; j < Tamanho_matriz; j++){
            matriz[i][j] = (rand() % 99);
        }
    }
    printf("Matriz gerada: ");
}

void Mostra_Matriz(int Tamanho_matriz, int **matriz){
    for(int i = 0; i < Tamanho_matriz; i++){
        printf("\n");
        for(int j = 0; j < Tamanho_matriz; j++){
            printf(" %d ", matriz[i][j]);
        }
    }
}

void Anda_pela_matriz(int Tamanho_matriz, int **matriz){
    int soma = 0, i = 0, j = 0;
    int invalido = - 1;
    soma = matriz[i][j];
    do{

        //CASO ESTEJA NA PRIMEIRA COLUNA//

        if(j == 0){
       
            //DIREITA MAIOR - PRIMEIRA COLUNA//

            if(matriz[i][j + 1] > matriz[i + 1][j]){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
                printf("\nDIREITA: %d", soma);
            }

            //BAIXO MAIOR - PRIMEIRA COLUNA

            else if(matriz[i + 1][j] > matriz[i][j + 1]){
                soma += matriz[i + 1][j];
                i++;
                matriz[i - 1][j] = invalido;
                printf("\nBAIXO: %d", soma);
            }

            //VIZINHOS IGUAIS - PRIMEIRA COLUNA

            else if(matriz[i][j + 1] == matriz[i + 1][j]){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
                printf("\nDIRETA: %d", soma);
            }

        }

        //ULTIMA LINHA//

        else if(i == Tamanho_matriz - 1 && j != Tamanho_matriz - 1){
            soma += matriz[i][j + 1];
            j++;
            matriz[i][j - 1] = invalido;
            printf("\nDIREITA: %d", soma);
        }

        //ULTIMA COLUNA//

        else if( i != Tamanho_matriz -1 && j == Tamanho_matriz -1){
            if(matriz[i + 1][j] > matriz[i][j - 1]){
                soma += matriz[i + 1][j];
                i++;
                matriz[i - 1][j] = invalido;
                printf("\nBAIXO: %d", soma);
            }else{
                soma += matriz[i][j - 1];
                j--;
                matriz[i][j + 1] = invalido;
                printf("\nESQUERDA: %d", soma);
            }
        }

        else{
            
            //ESQUERDA MAIOR QUE BAIXO E DIREITA//

            if(matriz[i][j - 1] > matriz[i + 1][j] && matriz[i][j - 1] > matriz[i][j + 1] ){
                soma += matriz[i][j - 1];
                j--;
                matriz[i][j + 1] = invalido;
                printf("\nESQUERDA: %d", soma);
            }

            //BAIXO MAIOR QUE ESQUERDA E DIREITA//

            else if(matriz[i + 1][j] > matriz[i][j - 1] && matriz[i + 1][j] > matriz[i][j + 1] ){
                soma += matriz[i + 1][j];
                i++;
                matriz[i - 1][j] = invalido;
                printf("\nBAIXO: %d", soma);
            }

            //DIREITA MAIOR QUE ESQUERDA E BAIXO//

            else if(matriz[i][j + 1] > matriz[i][j - 1] && matriz[i][j + 1] > matriz[i + 1][j] ){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
                printf("\nDIREITA: %d", soma);
            }

            //VIZINHOS IGUAIS //

            else if(matriz[i][j + 1] == matriz[i + 1][j]){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
                printf("\nDIRETA: %d", soma);
            }

            else if(matriz[i][j + 1] == matriz[i][j - 1]){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
                printf("\nDIRETA: %d", soma);
            }

        }

    }while(matriz[i][j] != matriz[Tamanho_matriz-1][Tamanho_matriz-1]);
    printf("\nSoma total: %d", soma);
    printf("\n");
}