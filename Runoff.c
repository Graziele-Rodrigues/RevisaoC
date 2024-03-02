
/*
    1- eleicao rankeada, cada pessoa pode escolher 3 preferencias
    2- vote leva um único argumento, uma string chamada name , que representa o nome do candidato que foi votado.
    3- se o name corresponder a um dos nomes dos candidatos na eleição, atualize o total de votos desse candidato para contabilizar a nova votação.
    4- se o name não corresponder ao nome de nenhum dos candidatos na eleição, nenhum total de votos deve mudar e a função de voto(vote) deve retornar false para indicar uma cédula inválida.
    5- deve imprimir o nome do candidato que recebeu mais votos na eleição e, em seguida, imprimir uma nova linha.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 9
#define MAX_PREFS 3

typedef struct
{
    char nome[50]; // Nome do candidato
    int votos;     // Número de votos
} candidato;

candidato candidatos[MAX];
int total_candidatos;

bool votar(char *prefs[]);
void imprimir_vencedor(void);

int main()
{
    // Definição dos nomes dos candidatos
    total_candidatos = 3; // Defina o número total de candidatos aqui
    strcpy(candidatos[0].nome, "lula"); // Defina os nomes dos candidatos aqui
    strcpy(candidatos[1].nome, "bolsonaro");
    strcpy(candidatos[2].nome, "marina");

    int total_votantes;
    printf("Numero de eleitores: ");
    scanf("%d", &total_votantes);

    char prefs[MAX_PREFS][50];

    for (int i = 0; i < total_votantes; i++)
    {
        printf("Voto %d: ", i + 1);
        for (int j = 0; j < MAX_PREFS; j++)
        {
            scanf("%s", prefs[j]);
        }

        if (!votar(prefs))
        {
            printf("Voto invalido.\n");
        }
    }

    imprimir_vencedor();
}

bool votar(char *prefs[])
{
    int pontos = MAX_PREFS;
    for (int i = 0; i < MAX_PREFS; i++)
    {
        for (int j = 0; j < total_candidatos; j++)
        {
            if (strcmp(candidatos[j].nome, prefs[i]) == 0)
            {
                candidatos[j].votos += pontos;
            }
        }
        pontos--;
    }
    return true;
}

void imprimir_vencedor(void)
{
    int max_votos = 0;
    candidato vencedor;

    for (int i = 0; i < total_candidatos; i++)
    {
        if (candidatos[i].votos > max_votos)
        {
            max_votos = candidatos[i].votos;
            vencedor = candidatos[i];
        }
    }

    printf("Vencedor: %s\n", vencedor.nome);
}




