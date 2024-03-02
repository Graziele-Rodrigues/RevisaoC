
/*
    1- No jogo Scrabble, os jogadores criam palavras para marcar pontos, e o número de pontos é a soma dos valores dos pontos de cada letra da palavra.
    2- Em main() , o programa pede aos dois jogadores suas palavras usando a função get_string(). Esses valores são armazenados dentro de variáveis ​​chamadas word1 e word2.
    3 - Em compute_score() , seu programa deve calcular, usando o array POINTS , e retornar a pontuação para o argumento string. Os caracteres que não são letras devem receber zero pontos, e as letras maiúsculas e minúsculas devem receber os mesmos valores de pontos.
    4- Em main(), seu programa deve imprimir, dependendo da pontuação dos jogadores, Player 1 wins!, Player 2 wins!, ou Tie!.
*/

#include <stdio.h>
#include <ctype.h> // Para usar as funções isalpha e isupper

#include <ctype.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char *word);

int main(void)
{
    // Get input words from both players
    char word1[50], word2[50];

    printf("Player 1: ");
    scanf("%s", word1);

    printf("Player 2: ");
    scanf("%s", word2);

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2) {
        printf("Player 1 vence!\n");
    } else if (score2 > score1) {
        printf("Player 2 vence!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}

int compute_score(const char *word)
{
    int score = 0;

    // Compute and return score for string
    for (int i = 0; word[i] != '\0'; i++) {
        char c = toupper(word[i]); // Convertendo para maiúscula para facilitar a busca nos pontos
        if (isalpha(c)) { // Verificar se o caractere é uma letra com isalpha
            score += POINTS[c - 'A']; // Adicionando os pontos correspondentes à letra ao total da pontuação
        }
    }

    return score;
}
