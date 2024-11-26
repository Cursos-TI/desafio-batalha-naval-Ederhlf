#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 10
int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

void navioHorizontal(int coluna, int startLinha) {
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

void exibirTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}


void limparTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

void habilidadeCone(int linha, int coluna) {
    int alcance = 2; // Alcance do cone
    for (int i = 0; i <= alcance; i++) {
        for (int j = -i; j <= i; j++) {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (novaLinha >= 0 && novaLinha < TAMANHO_TABULEIRO &&
                novaColuna >= 0 && novaColuna < TAMANHO_TABULEIRO) {
                tabuleiro[novaLinha][novaColuna] = 1;
            }
        }
    }
}

void habilidadeCruz(int linha, int coluna) {
    int alcance = 2; // Alcance da cruz
    for (int i = -alcance; i <= alcance; i++) {
        if (linha + i >= 0 && linha + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha + i][coluna] = 1; // Linha vertical
        }
        if (coluna + i >= 0 && coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha][coluna + i] = 1; // Linha horizontal
        }
    }
}

void habilidadeOctaedro(int linha, int coluna) {
    int alcance = 2; // Alcance do octaedro
    for (int i = -alcance; i <= alcance; i++) {
        for (int j = -alcance + abs(i); j <= alcance - abs(i); j++) {
            int novaLinha = linha + i;
            int novaColuna = coluna + j;
            if (novaLinha >= 0 && novaLinha < TAMANHO_TABULEIRO &&
                novaColuna >= 0 && novaColuna < TAMANHO_TABULEIRO) {
                tabuleiro[novaLinha][novaColuna] = 1;
            }
        }
    }
}


int main() {
    int direcao = 0;
    int linha, coluna;
    int escolha;
    char continuar;

 do {
        // Painel interativo
        printf("\nEscolha a direção do navio:\n");
        printf("1- Horizontal\n");
        printf("2- Vertical\n");
        printf("3- Diagonal\n");
        printf("4- Cone\n");
        printf("5- Cruz\n");
        printf("6- Octaedro\n");
        scanf("%d", &escolha);


              printf("Digite a linha inicial (0 a %d): ", TAMANHO_TABULEIRO - 1);
              scanf("%d", &linha);
              printf("Digite a coluna inicial (0 a %d): ", TAMANHO_TABULEIRO - 1);
              scanf("%d", &coluna);
        
      
          switch (escolha) {
            case 1:
                navioHorizontal(linha, coluna);
                break;
            case 2:
                navioVertical(linha, coluna);
                break;
            case 3:
                navioDiagonal(linha, coluna);
                break;

            case 4:
                habilidadeCone(linha, coluna);
                break;
            case 5:
                habilidadeCruz(linha, coluna);
                break;
            case 6:
                habilidadeOctaedro(linha, coluna);
                break;
            default:
                printf("Habilidade inválida.\n");
                break;
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
