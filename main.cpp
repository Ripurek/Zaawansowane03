#include <iostream>
#include <vector>
#include "MergeSort.h"

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. Instancja dla liczb int
    MergeSort<int> intSorter;
    std::vector<int> intArray = { 38, -5, 27, 43, 3, -12, 9, 82, 10,2,37 };

    std::cout << "Tablica int przed sortowaniem: ";
    printArray(intArray);

    intSorter.sort(intArray);

    std::cout << "Tablica int po sortowaniu:    ";
    printArray(intArray);
    std::cout << "\n";

    // 2. Instancja dla liczb double
    MergeSort<double> doubleSorter;
    std::vector<double> doubleArray = { 12.5, -3.14, 0.0, 99.99, -45.2, 3.14, 7.8 };

    std::cout << "Tablica double przed sortowaniem: ";
    printArray(doubleArray);

    doubleSorter.sort(doubleArray);

    std::cout << "Tablica double po sortowaniu:    ";
    printArray(doubleArray);

    return 0;
}