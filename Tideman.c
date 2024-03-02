
/*
   1- A selection sort itera através das partes não classificadas de uma lista, selecionando o menor elemento a cada vez e movendo-o para seu local correto.
   2- A bubble sort compara pares de valores adjacentes, um de cada vez, e os troca se estiverem na ordem incorreta. Isso continua até que a lista seja classificada.
   3- A merge sort divide recursivamente a lista em duas repetidamente e, em seguida, mescla as listas menores de volta em uma maior na ordem correta.
*/

#include <stdio.h>

// Função para trocar dois elementos em um array
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Implementação do Selection Sort
void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        trocar(&arr[min_idx], &arr[i]);
    }
}

// Implementação do Bubble Sort
void bubble_sort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                trocar(&arr[j], &arr[j+1]);
            }
        }
    }
}

// Implementação do Merge Sort
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Arrays temporários
    int L[n1], R[n2];

    // Copiar dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    // Mesclar os arrays temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        // Encontra o ponto médio
        int m = l + (r - l) / 2;

        // Ordena a primeira metade
        merge_sort(arr, l, m);

        // Ordena a segunda metade
        merge_sort(arr, m + 1, r);

        // Mescla as duas metades ordenadas
        merge(arr, l, m, r);
    }
}

// Função para imprimir um array
void imprimir_array(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: \n");
    imprimir_array(arr, n);

    printf("\nAplicando Selection Sort: \n");
    selection_sort(arr, n);
    imprimir_array(arr, n);

    printf("\nAplicando Bubble Sort: \n");
    bubble_sort(arr, n);
    imprimir_array(arr, n);

    printf("\nAplicando Merge Sort: \n");
    merge_sort(arr, 0, n - 1);
    imprimir_array(arr, n);

    return 0;
}

