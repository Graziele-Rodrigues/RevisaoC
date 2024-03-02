
/*
    1- vote leva um único argumento, uma string chamada name , que representa o nome do candidato que foi votado.
    2- se o name corresponder a um dos nomes dos candidatos na eleição, atualize o total de votos desse candidato para contabilizar a nova votação.
    3- se o name não corresponder ao nome de nenhum dos candidatos na eleição, nenhum total de votos deve mudar e a função de voto(vote) deve retornar false para indicar uma cédula inválida.
    2- deve imprimir o nome do candidato que recebeu mais votos na eleição e, em seguida, imprimir uma nova linha.
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
int total_candidatos;

bool votar(char *nome);
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

    for (int i = 0; i < total_votantes; i++)
    {
        char nome[50];
        printf("Voto: ");
        scanf("%s", nome);

        if (!votar(nome))
        {
            printf("Voto invalido.\n");
        }
    }

    imprimir_vencedor();
}

bool votar(char *nome)
{
    for (int i = 0; i < total_candidatos; i++)
    {
        if (strcmp(candidatos[i].nome, nome) == 0)
        {
            candidatos[i].votos++;
            return true;
        }
    }
    return false;
}

void imprimir_vencedor(void)
{
    int max_votos = 0;

    for (int i = 0; i < total_candidatos; i++)
    {
        if (candidatos[i].votos > max_votos)
        {
            max_votos = candidatos[i].votos;
        }
    }

    for (int i = 0; i < total_candidatos; i++)
    {
        if (candidatos[i].votos == max_votos)
        {
            printf("Vencedor: %s\n", candidatos[i].nome);
        }
    }
}



