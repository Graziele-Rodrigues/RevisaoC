
/*
    1- Seu programa deve solicitar ao usuário uma string de texto.
    2- Seu programa deve contar o número de letras, palavras e frases do texto. Você pode assumir que uma letra é qualquer caractere minúsculo de a a z ou qualquer caractere maiúsculo de A a Z ,
    qualquer sequência de caracteres separados por espaços deve contar como uma palavra e que qualquer ocorrência de um ponto final, ponto de exclamação ou ponto de interrogação indica o final de uma frase.
    3- Seu programa deve imprimir como saída "Grade X", onde X é o nível de grau calculado pela fórmula de Coleman-Liau, arredondado para o número inteiro mais próximo.
    4- Se o número do índice resultante for 16 ou superior (equivalente ou superior ao nível de leitura de graduação sênior), seu programa deve produzir
    "Grade 16+" em vez de fornecer o número do índice exato. Se o número do índice for menor que 1, seu programa deve imprimir "Before Grade 1" .
    5- índice = 0,0588L - 0,296S - 15,8, L é o número médio de letras por 100 palavras no texto e S é o número médio de sentenças por 100 palavras no texto.
*/

#include <stdio.h>

int contarPalavras(const char *frase) {
    int contadorPalavras = 0;
    int dentroDaPalavra = 0;

    // Iterar pela string
    while (*frase) {
        // Verificar se o caractere atual não é espaço, tabulação, nova linha ou retorno de carro e não estamos dentro de uma palavra
        if ((*frase != ' ' && *frase != '\t' && *frase != '\n' && *frase != '\r') && !dentroDaPalavra) {
            contadorPalavras++;
            dentroDaPalavra = 1;
        }
        // Se o caractere atual for espaço, tabulação, nova linha ou retorno de carro, indicamos que não estamos mais dentro de uma palavra.
        else if (*frase == ' ' || *frase == '\t' || *frase == '\n' || *frase == '\r') {
            dentroDaPalavra = 0;
        }

        frase++; // Avançar para o próximo caractere
    }

    return contadorPalavras;
}

int contarLetras(const char *frase) {
    int contadorLetras = 0;

    // Iterar pela string
    while (*frase) {
        // Verificar se o caractere atual é uma letra (maiúscula ou minúscula)
        if ((*frase >= 'a' && *frase <= 'z') || (*frase >= 'A' && *frase <= 'Z')) {
            contadorLetras++;
        }

        frase++; // Avançar para o próximo caractere
    }

    return contadorLetras;
}

int contarSentencas(const char *frase) {
    int contadorSentencas = 0;

    // Iterar pela string
    while (*frase) {
        // Verificar se o caractere atual é um ponto final, ponto de exclamação ou ponto de interrogação
        if (*frase == '.' || *frase == '!' || *frase == '?') {
            contadorSentencas++;
        }

        frase++; // Avançar para o próximo caractere
    }

    return contadorSentencas;
}

int main(void) {
    char frase[1000]; // Alocando espaço para armazenar a string

    printf("Texto: ");
    fgets(frase, sizeof(frase), stdin); // Lendo a string (seguro)

    int numPalavras = contarPalavras(frase);
    int numLetras = contarLetras(frase);
    int numSentencas = contarSentencas(frase);

    // Calcular L (número médio de letras por 100 palavras)
    float L = (float) numLetras / numPalavras * 100;

    // Calcular S (número médio de sentenças por 100 palavras)
    float S = (float) numSentencas / numPalavras * 100;

    // Calcular o índice Coleman-Liau
    int indice = (int)(0.0588 * L - 0.296 * S - 15.8 + 0.5); // Arredondamento para o inteiro mais próximo

    // Imprimir o resultado
    if (indice >= 16) {
        printf("Grade 16+\n");
    } else if (indice < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %d\n", indice);
    }

    return 0;
}

