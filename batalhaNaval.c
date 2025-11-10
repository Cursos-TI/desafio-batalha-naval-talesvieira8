#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
#define NAVIO 3
#define TAM_NAVIO 3
int main() {
    int tabuleiro[TAM][TAM];
    int i, j;
    srand(time(NULL));
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }
    
    int linha_horizontal, coluna_horizontal;
    do {
        linha_horizontal = rand() % TAM;
        coluna_horizontal = rand() % (TAM - TAM_NAVIO + 1);
    } while (0);

    for (j = coluna_horizontal; j < coluna_horizontal + TAM_NAVIO; j++) {
        tabuleiro[linha_horizontal][j] = NAVIO;
    }
    
    int linha_vertical, coluna_vertical;
    int valido;
    do {
        valido = 1; 
        linha_vertical = rand() % (TAM - TAM_NAVIO + 1);
        coluna_vertical = rand() % TAM;
        
        for (i = linha_vertical; i < linha_vertical + TAM_NAVIO; i++) {
            if (tabuleiro[i][coluna_vertical] == NAVIO) {
                valido = 0;
                break;
            }
        }
    } while (!valido);
    for (i = linha_vertical; i < linha_vertical + TAM_NAVIO; i++) {
        tabuleiro[i][coluna_vertical] = NAVIO;
    }
    int tiros = 0;
    int acertos = 0;
    int total_navio = TAM_NAVIO * 2;
    int linha_tiro, coluna_tiro;

    printf("BATALHA NAVAL\n");
    printf("Digite coordenadas (linha e coluna) de 0 a 9\n");
    printf("Tente acertar todos os navios!\n\n");
    while (acertos < total_navio) {
        
        printf("\nTabuleiro:\n");
        for (i = 0; i < TAM; i++) {
            for (j = 0; j < TAM; j++) {
                if (tabuleiro[i][j] == -1)
                    printf("X ");
                else if (tabuleiro[i][j] == -2)
                    printf("O ");
                else
                    printf("~ ");
            }
            printf("\n");
        }
        printf("Digite a linha: ");
        scanf("%d", &linha_tiro);
        printf("Digite a coluna: ");
        scanf("%d", &coluna_tiro);
        
        if (linha_tiro < 0 || linha_tiro >= TAM || coluna_tiro < 0 || coluna_tiro >= TAM) {
            printf("Coordenadas invalidas! Tente novamente.\n");
            continue;
        }
        if (tabuleiro[linha_tiro][coluna_tiro] == NAVIO) {
            printf(" ACERTOU!\n");
            tabuleiro[linha_tiro][coluna_tiro] = -2;
            acertos++;
        } else if (tabuleiro[linha_tiro][coluna_tiro] == 0) {
            printf(" Agua!\n");
            tabuleiro[linha_tiro][coluna_tiro] = -1;
        } else {
            printf(" Voce ja atirou aqui!\n");
        }

        tiros++;
    }
    printf("PARABENS! Voce afundou todos os navios em %d tiros!\n", tiros);
    printf("Tabuleiro final (navios revelados):\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == -1)
                printf("X");
            else if (tabuleiro[i][j] == -2)
                printf("O");
            else if (tabuleiro[i][j] == NAVIO)
                printf("3");
            else
                printf("~");
        }
        printf("\n");
    }
    printf("Legenda:\nO = Acerto | X = Agua | 3 = Navio (posicao original)\n");
    return 0;
}

