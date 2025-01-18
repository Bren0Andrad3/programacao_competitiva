// SortingAlgorithms.h

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <vector>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void radixSort(std::vector<int>& arr);
void countingSort(std::vector<int>& arr);
void bucketSort(std::vector<int>& arr);

#endif // SORTING_ALGORITHMS_H




int main() {
    std::vector<int> arr = {3, 6, 4, 7, 8, 1, 5, 9, 2};

    // Radix Sort
    radixSort(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Counting Sort
    std::vector<int> arr2 = {3, 6, 4, 7, 8, 1, 5, 9, 2};
    countingSort(arr2);
    for (int num : arr2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Bucket Sort
    std::vector<int> arr3 = {3, 6, 4, 7, 8, 1, 5, 9, 2};
    bucketSort(arr3);
    for (int num : arr3) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
