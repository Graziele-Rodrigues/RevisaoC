
/*  1- Usuario digita numero cartao credito
    2- Multiplique cada segundo digito por 2, começando com o penúltimo dígito do número e, em seguida, some os dígitos desses produtos.
    3- Adicione essa soma à soma dos dígitos que não foram multiplicados por 2.
    4- Se o último dígito do total for 0 (ou, mais formalmente, se o módulo total 10 for congruente com 0), o número é válido!
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    long int num_cartao;
    int soma = 0, multiplicador = 0;

    // Solicitar ao usuário que digite o número do cartão de crédito
    printf("Digite o numero do cartao de credito: ");
    scanf("%ld", &num_cartao);

    // Iterar pelo número do cartão de crédito da direita para a esquerda
    while (num_cartao > 0) {
        // Pega o último dígito
        int digito = num_cartao % 10;

        // Se é um dígito que deve ser multiplicado por 2
        if (multiplicador % 2 == 1) {
            digito *= 2;

            // Se o resultado da multiplicação for maior que 9, adicione os dígitos desse número
            if (digito > 9) {
                digito = (digito % 10) + (digito / 10);
            }
        }

        // Adicione o dígito à soma
        soma += digito;

        // Avança para o próximo dígito
        num_cartao /= 10;
        multiplicador++;
    }

    // Verificar se o número do cartão de crédito é válido
    if (soma % 10 == 0) {
        printf("O numero do cartao de credito eh valido.\n");
    } else {
        printf("O numero do cartao de credito nao eh valido.\n");
    }

    return 0;
}

