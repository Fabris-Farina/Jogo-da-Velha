# Jogo da Velha em C
![Ícone Jogo da Velha](https://i.imgur.com/chc60oI.png)



## Descrição
Este projeto implementa um jogo da velha utilizando a linguagem C. O jogo é baseado em texto, onde dois jogadores alternam suas jogadas até que um vença ou ocorra um empate.

## Funcionalidades
- Interface baseada em texto.
- Validação de jogadas para evitar entradas inválidas.
- Exibição do tabuleiro atualizado após cada jogada.
- Detecção de vitória ou empate.

## Requisitos
- Compilador C (GCC, MinGW (pra uso no VScode) ou compiladores online e semelhantes)

## Compilação
Para compilar o programa, utilize o seguinte comando no terminal (Utilizando o GCC):

```bash
gcc jogo_da_velha.c -o jogo_da_velha
```

## Execução
Após a compilação, execute o programa com o comando:

```bash
./jogo_da_velha
```

## Como Jogar
1. Ao iniciar, um menu será exibido com as opções: (Desafio - 7)
   - **1** para iniciar um novo jogo.
   - **2** para sair.
2. Durante o jogo, os jogadores informam a linha e a coluna (valores de 1 a 3) onde desejam jogar.
3. O tabuleiro é atualizado a cada rodada.
4. O jogo termina quando um jogador vence ou ocorre um empate.

## Estrutura do Código
O código é modularizado e possui as seguintes funções:
- `jogar()`: Controla o fluxo principal do jogo.
- `inicializarTabuleiro()`: Define um tabuleiro vazio.
- `exibirTabuleiro()`: Exibe o estado atual do tabuleiro.
- `validarJogada()`: Verifica se a jogada é válida.
- `verificarVencedor()`: Analisa se houve um vencedor.

## Observação 

Este projeto é um jogo simples baseado em texto e pode ser expandido para incluir novas funcionalidades.

---
Projeto (TP01) desenvolvido como trabalho prático para a disciplina de Introdução a Ciência da Computação na Universidade Federal do Espírito Santo.

## Criador por : 
 - Lucas de Paula Tavares

 - Lucas Fabris Farina

 - Maria Luiza da Cruz Furtado

 - Matheus Lucas Klippel Tavares


