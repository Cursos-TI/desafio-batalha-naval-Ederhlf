#include <stdio.h>

#define TAMANHO_TABULEIRO 5

int main() {
    // Tabuleiro representado como uma matriz 5x5
    char tabuleiro[10][10] = { {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'},
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'},
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'},
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'},
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'}, 
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'},
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'},
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'}, 
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'}, 
                               {'~', '~', '~', '~', '~','~', '~', '~', '~', '~'} 
                             };

    // Posicionando um navio verticalmente (3 partes) na coluna 1
    tabuleiro[0][5] = 'N';  // Parte 1
    tabuleiro[1][5] = 'N';  // Parte 2
    tabuleiro[2][5] = 'N';  // Parte 3
    tabuleiro[3][5] = 'N';  // Parte 3

    // Posicionando um navio horizontalmente (4 partes) na linha 3
    tabuleiro[7][0] = 'N';  // Parte 1
    tabuleiro[7][1] = 'N';  // Parte 2
    tabuleiro[7][2] = 'N';  // Parte 3
    tabuleiro[7][3] = 'N';  // Parte 4

    // Exibindo o tabuleiro no console
    printf("Tabuleiro de Batalha Naval:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

   
    return 0;
}
