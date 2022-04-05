#include <stdlib.h>
#include <stdio.h>
#include "Matriz.h"

int main(){
    int **matriz;
    int Tamanho_matriz, i;

    printf("Insira o tamanho da matriz (NxN): ");
    scanf("%d", &Tamanho_matriz);

    matriz = malloc(Tamanho_matriz*sizeof(int *));
    for(i = 0; i < Tamanho_matriz; i++){
        matriz[i]= malloc(Tamanho_matriz*sizeof(int *));
    }

    Cria_Matriz(Tamanho_matriz, matriz);
    Mostra_Matriz(Tamanho_matriz, matriz);
    Anda_pela_matriz(Tamanho_matriz, matriz);
}