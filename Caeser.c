
/*
    1- Seu programa deve solicitar ao usuário uma string de texto.
    2- Aplicar a criptografia de caeser     c i= (p i+ k)% 26
*/

#include <stdio.h>
#include <ctype.h> // Para usar as funções isalpha e isupper

#define TAM_ALFABETO 26

// Função para aplicar a cifra de César a uma única letra
char cifraCesar(char letra, int chave) {
    if (isalpha(letra)) {
        char base = isupper(letra) ? 'A' : 'a'; // Determina a base do alfabeto ('A' para maiúsculas, 'a' para minúsculas)
        return (letra - base + chave + TAM_ALFABETO) % TAM_ALFABETO + base; // Aplica a cifra de César
    } else {
        return letra; // Retorna caracteres não alfabéticos sem alteração
    }
}

// Função para aplicar a cifra de César a uma string inteira
void cifraCesarString(char *frase, int chave) {
    while (*frase) {
        *frase = cifraCesar(*frase, chave); // Aplica a cifra de César a cada caractere da string
        frase++; // Avança para o próximo caractere
    }
}

int main(void) {
    char frase[1000]; // Alocando espaço para armazenar a string
    int chave;

    printf("Texto: ");
    fgets(frase, sizeof(frase), stdin); // Lendo a string (seguro)

    printf("Chave de deslocamento: ");
    scanf("%d", &chave); // Lendo a chave de deslocamento

    cifraCesarString(frase, chave); // Aplica a cifra de César à frase

    printf("Texto criptografado: %s\n", frase); // Imprime a frase criptografada

    return 0;
}
