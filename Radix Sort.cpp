#include <iostream>
#include <vector>
#include <algorithm>

// Função para obter o maior número da lista
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Função para realizar a contagem de dígitos de cada posição
void countSort(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    int count[10] = {0};

    // Armazena a contagem de ocorrências de cada dígito
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Modifica o count[] para que ele contenha posições reais de cada dígito
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Preenche o array de saída com os números ordenados de acordo com o dígito atual
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array de saída para o array original
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Função principal de Radix Sort
void radixSort(std::vector<int>& arr) {
    int maxVal = getMax(arr);

    // Faz a contagem de cada dígito começando da unidade e indo até o maior dígito
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countSort(arr, exp);
    }
}
