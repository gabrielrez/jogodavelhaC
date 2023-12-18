#include <stdio.h>

int main(void) {
  char jogo[3][3];
  int linha, coluna, jogador, ganhou, jogadas, opcao;

  printf("-----------------\n");
  printf("| JOGO DA VELHA |\n");
  printf("-----------------\n\n");

  // ESTRUTURA DE DADOS
  do {
    jogador = 1;
    ganhou = 0;
    jogadas = 0;

    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        jogo[i][j] = ' ';
      }
    }

    // IMPRIMIR ESTRUTURA
    do {
      printf("\n   0   1   2\n\n");
      for (int i = 0; i < 3; i++) {
        printf("  ");
        for (int j = 0; j < 3; j++) {
          printf(" %c ", jogo[i][j]);
          if (j < 2) {
            printf("|");
          }
          if (j >= 2) {
            printf("  %d", i);
          }
        }
        if (i < 2) {
          printf("\n  -----------");
        }
        printf("\n");
      }

      // LER COORDENADAS
      do {
        printf("\n\nJogar na posicao: ");
        scanf("%d%d", &linha, &coluna);
      } while (linha < 0 || linha > 2 || coluna < 0 || coluna > 2 ||
               jogo[linha][coluna] != ' ');

      // SALVAR COORDENADAS
      if (jogador == 1) {
        jogo[linha][coluna] = 'X';
        jogador++;
      } else {
        jogo[linha][coluna] = '0';
        jogador--;
      }

      jogadas++;

      // ALGUEM GANHOU LINHA
      if (jogo[0][0] == '0' && jogo[0][1] == '0' && jogo[0][2] == '0' ||
          jogo[1][0] == '0' && jogo[1][1] == '0' && jogo[1][2] ||
          jogo[2][0] == '0' && jogo[2][1] == '0' && jogo[2][2] == '0') {
        printf("\nJogador 0 ganhou!\n");
        ganhou = 1;
      }

      if (jogo[0][0] == 'X' && jogo[0][1] == 'X' && jogo[0][2] == 'X' ||
          jogo[1][0] == 'X' && jogo[1][1] == 'X' && jogo[1][2] ||
          jogo[2][0] == 'X' && jogo[2][1] == 'X' && jogo[2][2] == 'X') {
        printf("\nJogador X ganhou!\n");
        ganhou = 1;
      }

      // ALGUEM GANHOU COLUNA
      if (jogo[0][0] == '0' && jogo[1][0] == '0' && jogo[2][0] == '0' ||
          jogo[0][1] == '0' && jogo[1][1] == '0' && jogo[2][1] == '0' ||
          jogo[0][2] == '0' && jogo[1][2] == '0' && jogo[2][2] == '0') {
        printf("\nJogador 0 ganhou!\n");
        ganhou = 1;
      }

      if (jogo[0][0] == 'X' && jogo[1][0] == 'X' && jogo[2][0] == 'X' ||
          jogo[0][1] == 'X' && jogo[1][1] == 'X' && jogo[2][1] == 'X' ||
          jogo[0][2] == 'X' && jogo[1][2] == 'X' && jogo[2][2] == 'X') {
        printf("\nJogador X ganhou!\n");
        ganhou = 1;
      }

      // ALGUEM GANHOU DIAGONAL PRINCIPAL
      if (jogo[0][0] == '0' && jogo[1][1] == '0' && jogo[2][2] == '0') {
        printf("\nJogador 0 ganhou!\n");
        ganhou = 1;
      }

      if (jogo[0][0] == 'X' && jogo[1][1] == 'X' && jogo[2][2] == 'X') {
        printf("\nJogador X ganhou!\n");
        ganhou = 1;
      }

      // ALGUEM GANHOU DIAGONAL PRINCIPAL
      if (jogo[0][2] == '0' && jogo[1][1] == '0' && jogo[3][0] == '0') {
        printf("\nJogador 0 ganhou!\n");
        ganhou = 1;
      }

      if (jogo[0][2] == 'X' && jogo[1][1] == 'X' && jogo[3][0] == 'X') {
        printf("\nJogador X ganhou!\n");
        ganhou = 1;
      }
    } while (ganhou == 0 && jogadas < 9);

    if (ganhou == 0) {
      printf("\nDeu velha!\n");
    }

    printf("\nDigite 1 para jogar novamente\n");
    scanf("%d", &opcao);

  } while (opcao == 1);

  return 0;
}
