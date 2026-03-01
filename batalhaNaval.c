#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define TAMANHO_HABILIDADE 5

// =====================================================
// FUNÇÃO PARA IMPRIMIR O TABULEIRO
// ~ = água
// N = navio
// * = área de habilidade
// =====================================================
void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {

    printf("\nTABULEIRO FINAL:\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {

            if (tabuleiro[i][j] == 0)
                printf("~ ");
            else if (tabuleiro[i][j] == 3)
                printf("N ");
            else if (tabuleiro[i][j] == 5)
                printf("* ");

        }
        printf("\n");
    }
}

// =====================================================
// FUNÇÃO PARA SOBREPOR HABILIDADE AO TABULEIRO
// =====================================================
void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                       int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE],
                       int origemLinha, int origemColuna) {

    int meio = TAMANHO_HABILIDADE / 2;

    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (habilidade[i][j] == 1) {

                int linhaTab = origemLinha + (i - meio);
                int colunaTab = origemColuna + (j - meio);

                // Verifica se está dentro do tabuleiro
                if (linhaTab >= 0 && linhaTab < TAMANHO_TABULEIRO &&
                    colunaTab >= 0 && colunaTab < TAMANHO_TABULEIRO) {

                    // Marca como área afetada (não sobrescreve navio)
                    if (tabuleiro[linhaTab][colunaTab] == 0)
                        tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }
}

// =====================================================
// PROGRAMA PRINCIPAL
// =====================================================
int main() {

    // 1️⃣ Criar tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // 2️⃣ Posicionar alguns navios manualmente
    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[2][2 + i] = 3; // Horizontal

    for (int i = 0; i < TAMANHO_NAVIO; i++)
        tabuleiro[6 + i][7] = 3; // Vertical

    // =====================================================
    // 3️⃣ CRIAR MATRIZES DE HABILIDADE DINAMICAMENTE
    // =====================================================

    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE] = {0};

    int meio = TAMANHO_HABILIDADE / 2;

    // 🔺 CONE (apontando para baixo)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (j >= meio - i && j <= meio + i)
                cone[i][j] = 1;
        }
    }

    // ➕ CRUZ
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (i == meio || j == meio)
                cruz[i][j] = 1;
        }
    }

    // 🔷 OCTAEDRO (formato losango)
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {

            if (abs(i - meio) + abs(j - meio) <= meio)
                octaedro[i][j] = 1;
        }
    }

    // =====================================================
    // 4️⃣ APLICAR HABILIDADES NO TABULEIRO
    // =====================================================

    aplicarHabilidade(tabuleiro, cone, 1, 7);
    aplicarHabilidade(tabuleiro, cruz, 5, 3);
    aplicarHabilidade(tabuleiro, octaedro, 8, 1);

    // 5️⃣ Mostrar resultado final
    imprimirTabuleiro(tabuleiro);

    return 0;
}