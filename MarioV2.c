/*  1- Peça ao usuário o tamanho da altura.
    2- Se o tamanho da altura for menor que 1 ou maior que 8(ou não inteiro), fique nesse passo até que o usuário insira uma entrada válida.
    3- Itere a variável i até o tamanho da altura.
    4- Imprima os #. [Não se esqueça da quebra de linha!]
    5- Faça com escadas duplas
*/

#include <stdio.h>
int main(void)
{
    // Pega o valor da altura da escada com o usuário (entre 1 e 8, inclusivos)
    int altura_escada;
    do
    {
        printf("Digite um valor de altura para a escada (entre 1 e 8): ");
        scanf("%d", &altura_escada);
    }
    while (altura_escada < 1 || altura_escada > 8);

    // Imprime a escada de acordo com a altura especificada
    for (int i = 1; i <= altura_escada; i++){
        // Imprime espaços em branco à esquerda
        for (int j = altura_escada - i; j > 0; j--)
        {
            printf(" ");
        }

        // Imprime '#', onde o número de '#' em cada linha é igual ao número da linha
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        printf(" ");
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
