#include "Matriz.h"

void Cria_Matriz(int Tamanho_matriz, int **matriz){
    srand(time(NULL));

    int i = 0, j = 0;
    for(i = 0; i < Tamanho_matriz; i++){
        for(j = 0; j < Tamanho_matriz; j++){
            matriz[i][j] = (rand() % 99);
        }
    }
    printf("\nMatriz gerada: ");
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
    bool invalido = false;
    soma = matriz[i][j];

    while(i != Tamanho_matriz  && j != Tamanho_matriz  ){

        //CASO ESTEJA NA PRIMEIRA COLUNA//
        if(j == 0){

            //BAIXO MAIOR - PRIMEIRA COLUNA
            if(i < Tamanho_matriz - 1 && matriz[i + 1][j] >= matriz[i][j + 1]){
                soma += matriz[i + 1][j];
                i++;
                matriz[i - 1][j] = invalido;
            }

            //DIREITA MAIOR - PRIMEIRA COLUNA//
            else{
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
            }
        }

        //ULTIMA LINHA//
        else if(i == Tamanho_matriz - 1 && j <= Tamanho_matriz - 1){
            soma += matriz[i][j + 1];
            j++;
            matriz[i][j - 1] = invalido;
        }

        //ULTIMA COLUNA//
        else if( i != Tamanho_matriz -1 && j == Tamanho_matriz -1){
            if(matriz[i + 1][j] > matriz[i][j - 1]){
                soma += matriz[i + 1][j];
                i++;
                matriz[i - 1][j] = invalido;
            }else{
                soma += matriz[i][j - 1];
                j--;
                matriz[i][j + 1] = invalido;
            }
        }

        else{
            
            //ESQUERDA MAIOR QUE BAIXO E DIREITA//
            if(matriz[i][j - 1] > matriz[i + 1][j] && matriz[i][j - 1] > matriz[i][j + 1] ){
                soma += matriz[i][j - 1];
                j--;
                matriz[i][j + 1] = invalido;
            }

            //BAIXO MAIOR QUE ESQUERDA E DIREITA//
            else if(matriz[i + 1][j] > matriz[i][j - 1] && matriz[i + 1][j] > matriz[i][j + 1] ){
                soma += matriz[i + 1][j];
                i++;
                matriz[i - 1][j] = invalido;
            }

            //DIREITA MAIOR QUE ESQUERDA E BAIXO//
            else if(matriz[i][j + 1] > matriz[i][j - 1] && matriz[i][j + 1] > matriz[i + 1][j] ){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
            }

            //VIZINHOS IGUAIS //
            else if(matriz[i][j + 1] == matriz[i + 1][j]){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
            }

            else if(matriz[i][j + 1] == matriz[i][j - 1]){
                soma += matriz[i][j + 1];
                j++;
                matriz[i][j - 1] = invalido;
            }
        }
    };
    printf("\n--------------------------");
    printf("\nSoma total: %d\n", soma);
    printf("--------------------------");
    printf("\nCaminho percorrido: ");
    Mostra_Matriz(Tamanho_matriz, matriz);
}