# Sudoku-Game

Bem-vindo ao **Sudoku-Game**, um jogo de Sudoku desenvolvido como atividade para relembrar e treinar habilidades em programação na linguagem C.

Com esta aplicação, você pode desfrutar de partidas de Sudoku, explorando estratégias para completar o tabuleiro corretamente.

## Tecnologias

- **C**
- **Git**
- **GitHub**

## Funcionalidades

- Geração de tabuleiros aleatórios de Sudoku.
- Validação de movimentos feitos pelo jogador.
- Verificação de vitória ao completar o tabuleiro.
- Interface de texto interativa para o usuário.
- Níveis de dificuldade ajustáveis.

## Como Jogar

Para jogar, siga estas instruções:

1. Clone o repositório Git do projeto para o seu computador:
   ```bash
   git clone https://github.com/ggomes12/sudoKu-game.git
   ```

2. Compile o código-fonte em C:
   ```bash
   gcc main.c -o sudoku-game
   ```

3. Execute o programa para iniciar o jogo:
   ```bash
   ./sudoku-game
   ```

4. Durante o jogo:
   - O programa exibirá o tabuleiro de Sudoku atual.


### Estrutura do Código

O jogo é implementado em **C** utilizando uma estrutura bem organizada para gerenciar o tabuleiro e validar movimentos. Os principais elementos incluem:

- **Estruturas de Dados:**
  - O tabuleiro é representado por uma matriz 9x9.
  - Arrays auxiliares rastreiam os números usados em linhas, colunas e submatrizes 3x3.

## Interface do Jogo

A interface do jogo exibirá o tabuleiro de Sudoku, representado por uma matriz 9x9, com números que podem ser preenchidos de acordo com as regras do jogo. O jogador pode selecionar a célula e o número desejado para preencher.

### Exemplo de Exibição do Tabuleiro

```
```

- Cada número representa um valor preenchido no tabuleiro.
- Células vazias são indicadas por espaços em branco.


---

Com estas instruções, você está pronto para explorar e aprimorar o seu Sudoku-Game! Divirta-se programando e jogando!
