
/*
    1- No jogo Scrabble, os jogadores criam palavras para marcar pontos, e o número de pontos é a soma dos valores dos pontos de cada letra da palavra.
    2- Em main() , o programa pede aos dois jogadores suas palavras usando a função get_string(). Esses valores são armazenados dentro de variáveis ​​chamadas word1 e word2.
    3 - Em compute_score() , seu programa deve calcular, usando o array POINTS , e retornar a pontuação para o argumento string. Os caracteres que não são letras devem receber zero pontos, e as letras maiúsculas e minúsculas devem receber os mesmos valores de pontos.
    4- Em main(), seu programa deve imprimir, dependendo da pontuação dos jogadores, Player 1 wins!, Player 2 wins!, ou Tie!.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char nome[50]; // Nome do candidato
    int votos;     // Número de votos
} candidato;

candidato candidatos[MAX];
bool locked[MAX][MAX]; // Matriz de adjacência representando o grafo de preferências
int ranks[MAX][MAX];   // Matriz representando as preferências dos eleitores
int pair_count = 0;
int candidate_count;

typedef struct
{
    int candidato1;
    int candidato2;
} par_candidatos;

par_candidatos pairs[MAX * (MAX - 1) / 2];

bool vote(int rank[], char *name, int ranks[][MAX]);
void record_preferences(int ranks[][MAX]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main()
{
    // Definição dos nomes dos candidatos
    candidate_count = 3; // Defina o número total de candidatos aqui
    strcpy(candidatos[0].nome, "lula"); // Defina os nomes dos candidatos aqui
    strcpy(candidatos[1].nome, "bolsonaro");
    strcpy(candidatos[2].nome, "marina");

    // Definição das preferências dos eleitores
    int preferencias_eleitores[MAX][MAX] = {
        {0, 1, 2}, // Preferências do primeiro eleitor
        {1, 0, 2}, // Preferências do segundo eleitor
        {1, 2, 0}  // Preferências do terceiro eleitor
    };

    for (int i = 0; i < candidate_count; i++)
    {
        if (!vote(preferencias_eleitores[i], candidatos[i].nome, ranks))
        {
            printf("Erro ao registrar voto.\n");
            return 1;
        }
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

bool vote(int rank[], char *name, int ranks[][MAX])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidatos[i].nome, name) == 0)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                ranks[i][j] = rank[j];
            }
            return true;
        }
    }
    return false;
}

void record_preferences(int ranks[][MAX])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            for (int k = 0; k < candidate_count; k++)
            {
                if (ranks[i][k] < ranks[i][j] && ranks[k][j] < ranks[i][j])
                {
                    locked[i][j] = true;
                    break;
                }
            }
        }
    }
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i != j && !locked[i][j])
            {
                pairs[pair_count].candidato1 = i;
                pairs[pair_count].candidato2 = j;
                pair_count++;
            }
        }
    }
}

void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int margin1 = candidatos[pairs[j].candidato1].votos - candidatos[pairs[j].candidato2].votos;
            int margin2 = candidatos[pairs[j + 1].candidato1].votos - candidatos[pairs[j + 1].candidato2].votos;
            if (margin1 < margin2)
            {
                par_candidatos temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
            }
        }
    }
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!creates_cycle(pairs[i].candidato1, pairs[i].candidato2))
        {
            locked[pairs[i].candidato1][pairs[i].candidato2] = true;
        }
    }
}

int creates_cycle(int winner, int loser)
{
    if (winner == loser)
    {
        return 1;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i] && creates_cycle(winner, i))
        {
            return 1;
        }
    }
    return 0;
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        bool winner = true;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                winner = false;
                break;
            }
        }
        if (winner)
        {
            printf("Vencedor: %s\n", candidatos[i].nome);
            return;
        }
    }
}
