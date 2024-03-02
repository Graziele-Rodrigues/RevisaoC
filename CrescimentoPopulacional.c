
/*  1- Solicite o valor inicial ao usuário
    2- Solicite o valor final ao usuário
    3- Calcule o número de anos até o limite
    4- Imprima o número de anos
    5- Considere  A cada ano, nascem n / 3 novas lhamas e n / 4 morrem.
*/

#include <stdio.h>

int main(void) {
    int valorInicial, valorFinal;

    // Solicite o valor inicial ao usuário
    do {
        printf("Digite um valor inicial (maior igual a 9): ");
        scanf("%d", &valorInicial);
    } while (valorInicial < 9);

    // Solicite o valor final ao usuário
    do {
        printf("Digite um valor final (maior que valor inicial): ");
        scanf("%d", &valorFinal);
    } while (valorFinal <= valorInicial);

    // Calcule o número de anos até o limite
    int anos = 0;
    int lhamas = valorInicial;
    while (lhamas < valorFinal) {
        // Considere que a cada ano, nascem n / 3 novas lhamas e n / 4 morrem
        lhamas += lhamas / 3; // nascimentos
        lhamas -= lhamas / 4; // mortes
        anos++;
    }

    // Imprima o número de anos
    printf("Número de anos necessários: %d\n", anos);

    return 0;
}


