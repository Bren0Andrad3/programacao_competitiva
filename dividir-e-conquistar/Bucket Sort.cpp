#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Função para ordenar os elementos dentro de cada bucket usando Insertion Sort
void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função principal de Bucket Sort
void bucketSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return;

    int minVal = *std::min_element(arr.begin(), arr.end());
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int bucketCount = std::sqrt(n);  // Usamos a raiz quadrada para o número de buckets
    int range = maxVal - minVal + 1;
    int bucketSize = std::ceil(static_cast<float>(range) / bucketCount);

    // Cria os buckets
    std::vector<std::vector<int>> buckets(bucketCount);

    // Distribui os elementos nos buckets
    for (int i = 0; i < n; i++) {
        int index = (arr[i] - minVal) / bucketSize;
        if (index == bucketCount) index--; // Para garantir que o maior valor caia no último bucket
        buckets[index].push_back(arr[i]);
    }

    // Ordena cada bucket usando Insertion Sort
    for (int i = 0; i < bucketCount; i++) {
        insertionSort(buckets[i]);
    }

    // Junta os buckets ordenados de volta no array original
    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        for (int j = 0; j < buckets[i].size(); j++) {
            arr[index++] = buckets[i][j];
        }
    }
}
