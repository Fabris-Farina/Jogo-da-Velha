//Bibliotecas Utilizadas
#include <stdio.h>
#include <stdlib.h>

//Constante e Funções Utilizadas 
#define TAMANHO 3
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]);
int validarJogada(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna);
int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO]);
void jogar();

//Parte do Menu do Jogo da Velha (DESAFIO)
int main() {
    
    int opcao;
    do {
        printf("***************\n");
        printf(" JOGO DA VELHA\n");
        printf("***************\n");
        printf("1 - Novo Jogo\n");
        printf("2 - Sair\n");
        printf("***************\n");
        printf("Escolha uma opcao: ");
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite um numero.\n");
            while (getchar() != '\n');
            continue;
        }
        
        switch (opcao) {
            case 1:
                jogar();
                break;
            case 2:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 2);
    return 0;
}

//Parte Principal do Jogo da Velha (JOGO)
void jogar() {
    char tabuleiro[TAMANHO][TAMANHO];
    int jogador = 1, linha, coluna, jogadas = 0;
    int resultado;
    inicializarTabuleiro(tabuleiro);
    
    while (1) {
        exibirTabuleiro(tabuleiro);
        printf("Jogador %d, informe a linha e a coluna (1-3): ", jogador);
        if (scanf("%d %d", &linha, &coluna) != 2) {
            printf("Entrada inválida! Digite dois números entre 1 e 3.\n");
            while (getchar() != '\n'); 
            continue;
        }
    
        if (linha < 1 || linha > 3 || coluna < 1 || coluna > 3) {
            printf("Coordenadas fora do intervalo! Tente novamente.\n");
            continue;
        }

        if (validarJogada(tabuleiro, linha - 1, coluna - 1)) {
            tabuleiro[linha - 1][coluna - 1] = (jogador == 1) ? 'X' : 'O';
            jogadas++;
            resultado = verificarVencedor(tabuleiro);
            
            if (resultado == 1) {
                exibirTabuleiro(tabuleiro);
                printf("Jogador %d venceu!\n", jogador);
                break;
            } else if (jogadas == 9) {
                exibirTabuleiro(tabuleiro);
                printf("Empate!\n");
                break;
            }
            jogador = (jogador == 1) ? 2 : 1;
        } else {
            printf("Jogada invalida! Tente novamente.\n");
        }
    }
}

//Parte da Inicialização do Tabuleiro (TABULEIRO VAZIO)
void inicializarTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

//Parte das Divisórias do Tabuleiro do Jogo da Velha
void exibirTabuleiro(char tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n");
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < TAMANHO - 1) printf("|");
        }
        printf("\n");
        if (i < TAMANHO - 1) printf("---+---+---\n");
    }
    printf("\n");
}

//Parte da Validação de Jogadas
int validarJogada(char tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha >= 0 && linha < TAMANHO && coluna >= 0 && coluna < TAMANHO && tabuleiro[linha][coluna] == ' ') {
        return 1;
    }
    return 0;
}

//Parte da Verificação de um Vencedor da Partida
int verificarVencedor(char tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2])
            return 1;
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i])
            return 1;
    }
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }
    return 0;
}