#include <stdio.h>

// Tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro:\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para verificar se é possível posicionar um navio horizontalmente
int podePosicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Sai dos limites
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) {
            return 0; // Já tem algo na posição
        }
    }

    return 1; // Pode posicionar
}

// Função para verificar se é possível posicionar um navio verticalmente
int podePosicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        return 0; // Sai dos limites
    }

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) {
            return 0; // Já tem algo na posição
        }
    }

    return 1; // Pode posicionar
}

// Função para posicionar o navio horizontal
void posicionarHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar o navio vertical
void posicionarVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

int main() {
    // 1. Inicializar o tabuleiro com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // 2. Coordenadas dos navios (definidas diretamente)
    int linha_horizontal = 2;
    int coluna_horizontal = 4;

    int linha_vertical = 5;
    int coluna_vertical = 6;

    // 3. Validar e posicionar navio horizontal
    if (podePosicionarHorizontal(tabuleiro, linha_horizontal, coluna_horizontal)) {
        posicionarHorizontal(tabuleiro, linha_horizontal, coluna_horizontal);
    } else {
        printf("Não foi possível posicionar o navio horizontal nas coordenadas (%d, %d).\n", linha_horizontal, coluna_horizontal);
        return 1;
    }

    // 4. Validar e posicionar navio vertical
    if (podePosicionarVertical(tabuleiro, linha_vertical, coluna_vertical)) {
        posicionarVertical(tabuleiro, linha_vertical, coluna_vertical);
    } else {
        printf("Não foi possível posicionar o navio vertical nas coordenadas (%d, %d).\n", linha_vertical, coluna_vertical);
        return 1;
    }

    // 5. Mostrar o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}

