#include <iostream>
#include <vector>
#include <algorithm>


// Função principal de Counting Sort
void countingSort(std::vector<int>& arr) {
    int n = arr.size();
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());

    // Tamanho do intervalo de números
    int range = maxVal - minVal + 1;

    // Inicializa o array de contagem
    std::vector<int> count(range), output(n);

    // Armazena a contagem de ocorrências de cada número
    for (int i = 0; i < n; i++) {
        count[arr[i] - minVal]++;
    }

    // Modifica o array de contagem para que cada posição contenha o índice de cada número
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Preenche o array de saída com os números ordenados
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i] - minVal] - 1] = arr[i];
        count[arr[i] - minVal]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}
