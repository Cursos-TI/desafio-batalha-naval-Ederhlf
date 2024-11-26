#include <stdio.h>

#define TAMANHO_TABULEIRO 10
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

void navioHorizontal(int coluna, int startLinha) {
        // Posicionando um navio verticalmente (3 partes) na coluna 1
        if (coluna >= 5) {
             printf("Menor que 5:\n");
            return;
        }
    coluna -= 1;
    startLinha -= 1;
    tabuleiro[startLinha][coluna] = 3;  // Parte 1
    tabuleiro[startLinha][coluna + 1] = 3;  // Parte 2
    tabuleiro[startLinha][coluna + 2] = 3;  // Parte 3
    tabuleiro[startLinha][coluna + 3] = 3;  // Parte 3
    tabuleiro[startLinha][coluna + 4] = 3;  // Parte 3

}

void navioVertical(int linha, int startcoluna) {
        // Posicionando um navio verticalmente (3 partes) na coluna 1
        if (startcoluna >= 5) {
             printf("Menor que 5:\n");
            return;
        }
        linha -= 1;
  // Posicionando um navio horizontalmente (4 partes) na linha 3
    tabuleiro[linha][startcoluna] = 3;  // Parte 1
    tabuleiro[linha + 1][startcoluna] = 3;  // Parte 2
    tabuleiro[linha + 2][startcoluna] = 3;  // Parte 3
    tabuleiro[linha + 3][startcoluna] = 3;  // Parte 4

}

// Função para posicionar navio diagonalmente
void navioDiagonal(int linha, int coluna) {
    if (linha + 4 >= TAMANHO_TABULEIRO || coluna + 4 >= TAMANHO_TABULEIRO) {
        printf("Erro: O navio ultrapassa os limites diagonalmente.\n");
        return;
    }
    linha -= 1;
    tabuleiro[linha][coluna] = 3;         // Parte 1
    tabuleiro[linha + 1][coluna + 1] = 3; // Parte 2
    tabuleiro[linha + 2][coluna + 2] = 3; // Parte 3
    tabuleiro[linha + 3][coluna + 3] = 3; // Parte 4
    tabuleiro[linha + 4][coluna + 4] = 3; // Parte 5
}

// Função para exibir o tabuleiro
void exibirTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int direcao = 0;
    int linha, coluna;
    char continuar;

 do {
        // Painel interativo
        printf("\nEscolha a direção do navio:\n");
        printf("1- Horizontal\n");
        printf("2- Vertical\n");
        printf("3- Diagonal\n");
        scanf("%d", &direcao);

        printf("Digite a linha inicial (0 a %d): ", TAMANHO_TABULEIRO - 1);
        scanf("%d", &linha);
        printf("Digite a coluna inicial (0 a %d): ", TAMANHO_TABULEIRO - 1);
        scanf("%d", &coluna);

        // Chama a função de posicionamento correspondente
        if (direcao == 1) {
            navioHorizontal(linha, coluna);
        } else if (direcao == 2) {
            navioVertical(linha, coluna);
        } else if (direcao == 3) {
            navioDiagonal(linha, coluna);
        } else {
            printf("Direção inválida.\n");
        }

        // Exibe o tabuleiro atualizado
        printf("\nTabuleiro atualizado:\n");
        exibirTabuleiro();

        // Pergunta se o jogador deseja continuar
        printf("\nDeseja posicionar outro navio? (s/n): ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\nTabuleiro final:\n");
    exibirTabuleiro();

    return 0;
}
