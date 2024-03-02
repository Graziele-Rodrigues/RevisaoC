
/*  1- Peça ao usuário digitar o valor do troco.
    2- Imprima a quantidade de moedas considerando os valores: 25, 10,5,1 centavos
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
    float troco=0.0;
    int centavos=0, n_moedas=0;
    printf("Digite o valor de troco: ");
    scanf("%f", &troco);
    centavos = round(troco * 100);
    if(centavos>25){
       n_moedas = centavos / 25;
       centavos %= 25; //pega restante centavos divido por 25
       n_moedas = n_moedas + centavos / 10;
       centavos %= 10; //pega restante centavos divido por 10
       n_moedas = n_moedas + centavos / 5;
       centavos %= 5; //pega restante centavos divido por 5
       n_moedas = n_moedas + centavos / 1;
       printf("Qtd moedas: %d\n", n_moedas);
       return;
    }
    else if(centavos>10){
       n_moedas = n_moedas + centavos / 10;
       centavos %= 10; //pega restante centavos divido por 10
       n_moedas = n_moedas + centavos / 5;
       centavos %= 5; //pega restante centavos divido por 5
       n_moedas = n_moedas + centavos / 1;
       printf("Qtd moedas: %d\n", n_moedas);
       return;
    }
    else if(centavos>5){
       n_moedas = n_moedas + centavos / 5;
       centavos %= 5; //pega restante centavos divido por 5
       n_moedas = n_moedas + centavos / 1;
       printf("Qtd moedas: %d\n", n_moedas);
       return;
    }
    else{
       n_moedas = centavos / 1;
       printf("Qtd moedas: %d\n", n_moedas);
       return;
    }

    return 0;
}

