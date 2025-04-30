#include <stdio.h>

#define PASSOS_TORRE 3
#define PASSOS_BISPO 2
#define PASSOS_RAINHA 2
#define TAMANHO_TABULEIRO 8

// ---------------------------
// MOVIMENTO DA TORRE (RECUSIVO)
// ---------------------------

void moverTorreCima(int passos) {
    if (passos == 0) return;
    printf("Cima\n");
    moverTorreCima(passos - 1);
}

void moverTorreDireita(int passos) {
    if (passos == 0) return;
    printf("Direita\n");
    moverTorreDireita(passos - 1);
}

// ---------------------------
// MOVIMENTO DO BISPO (RECUSIVO + LOOPS ANINHADOS)
// ---------------------------

void moverBispo(int linhas, int colunas) {
    if (linhas == 0 || colunas == 0) return;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Diagonal superior direita\n");
        }
    }
    moverBispo(linhas - 1, colunas - 1);
}

// ---------------------------
// MOVIMENTO DA RAINHA (RECUSIVO)
// ---------------------------

void moverRainhaDiagonal(int passos) {
    if (passos == 0) return;
    printf("Diagonal superior esquerda\n");
    moverRainhaDiagonal(passos - 1);
}

void moverRainhaVertical(int passos) {
    if (passos == 0) return;
    printf("Baixo\n");
    moverRainhaVertical(passos - 1);
}

// ---------------------------
// MOVIMENTO DO CAVALO (LOOPS COMPLEXOS)
// ---------------------------

void moverCavalo() {
    printf("Movimentos do Cavalo (duas casas para cima e uma para a direita):\n");

    for (int i = TAMANHO_TABULEIRO - 1; i >= 2; i--) {
        for (int j = 0; j < TAMANHO_TABULEIRO - 1; j++) {
            if ((i - 2 >= 0) && (j + 1 < TAMANHO_TABULEIRO)) {
                if ((i + j) % 2 == 0) continue; // condição arbitrária para pular posições
                printf("Cavalo move para (%d, %d) -> (%d, %d)\n", i, j, i - 2, j + 1);
                break; // simula uma única jogada válida por iteração externa
            }
        }
    }
}

// ---------------------------
// FUNÇÃO PRINCIPAL
// ---------------------------

int main() {
    // Movimentação da Torre
    printf("Movimentos da Torre:\n");
    moverTorreCima(PASSOS_TORRE);
    moverTorreDireita(PASSOS_TORRE);

    printf("\n");

    // Movimentação do Bispo
    printf("Movimentos do Bispo:\n");
    moverBispo(PASSOS_BISPO, PASSOS_BISPO);

    printf("\n");

    // Movimentação da Rainha
    printf("Movimentos da Rainha:\n");
    moverRainhaDiagonal(PASSOS_RAINHA);
    moverRainhaVertical(PASSOS_RAINHA);

    printf("\n");

    // Movimentação do Cavalo
    moverCavalo();

    return 0;
}
