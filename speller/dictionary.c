// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Calcule o índice (hash) da palavra
    unsigned int index = hash(word);

    // Percorra a lista vinculada correspondente ao índice calculado
    for (node *cursor = table[index]; cursor != NULL; cursor = cursor->next)
    {
        // Compare a palavra atual com a palavra procurada
        if (strcasecmp(cursor->word, word) == 0)
        {
            // Palavra encontrada no dicionário
            return true;
        }
    }
    
    // Palavra não encontrada no dicionário
    return false;
}


unsigned int hash(const char *word)
{
    // Algoritmo de hash simples: soma dos valores ASCII dos caracteres da palavra
    unsigned int hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value += tolower(word[i]);
    }

    // Mapeie o valor hash para um índice válido na tabela hash
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Abra o arquivo do dicionário
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // Variável para armazenar cada palavra lida
    char word[LENGTH + 1];

    // Leia cada palavra do arquivo e insira-a na tabela hash
    while (fscanf(file, "%s", word) != EOF)
    {
        // Aloque memória para o novo nó
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false;
        }

        // Copie a palavra para o nó
        strcpy(new_node->word, word);

        // Calcule o índice (hash) da palavra e insira-a na lista vinculada correspondente
        unsigned int index = hash(word);
        new_node->next = table[index];
        table[index] = new_node;
    }

    // Feche o arquivo
    fclose(file);

    // Indique sucesso
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Variável para contar o número de palavras
    unsigned int count = 0;

    // Percorra cada lista vinculada na tabela hash e conte o número de elementos
    for (int i = 0; i < N; i++)
    {
        for (node *cursor = table[i]; cursor != NULL; cursor = cursor->next)
        {
            count++;
        }
    }

    // Retorne o número total de palavras
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Percorra cada lista vinculada na tabela hash e libere a memória de cada nó
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            // Salve o próximo nó
            node *temp = cursor->next;

            // Libere a memória do nó atual
            free(cursor);

            // Avance para o próximo nó
            cursor = temp;
        }
    }

    // Indique sucesso
    return true;
}
