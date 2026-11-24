/**
 * @file MergeSort.h
 * @brief Szablonowa klasa realizująca algorytm sortowania przez scalanie (Merge Sort).
 */


#pragma once
#include <vector>

/**
 * @class MergeSort
 * @brief Uniwersalna klasa sortująca oparta na paradygmacie dziel i zwyciężaj.
 * @tparam T Typ sortowanych elementów (musi wspierać operator porównania <=).
 */


template <typename T>
class MergeSort {
public:

/**
     * @brief Sortuje rosnąco podany wektor elementów.
     * @param data Wektor danych wejściowych modyfikowany w miejscu.
     */

    void sort(std::vector<T>& arr);
    void sort(T* arr, int size);

private:

/**
     * @brief Rekurencyjnie dzieli zakres tablicy i scala posortowane połowy.
     * @param data Wektor przetwarzanych danych.
     * @param left Indeks początkowy zakresu.
     * @param right Indeks końcowy zakresu.
     */

    void mergeSort(std::vector<T>& arr, int left, int right);


/**
     * @brief Scala dwa sąsiednie, posortowane podzakresy w jeden uporządkowany fragment.
     * @param data Wektor przetwarzanych danych.
     * @param left Indeks początku lewej podtablicy.
     * @param mid Indeks końca lewej podtablicy.
     * @param right Indeks końca prawej podtablicy.
      */


    void merge(std::vector<T>& arr, int left, int mid, int right);
};

// --- Definicje metod poniżej deklaracji klasy ---

template <typename T>
void MergeSort<T>::sort(std::vector<T>& arr) {
    if (arr.size() <= 1) {
        return; // Obsługa pustej i 1-elementowej tablicy bez rzucania wyjątku
    }
    mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
}

template <typename T>
void MergeSort<T>::sort(T* arr, int size) {
    if (arr == nullptr || size <= 1) {
        return;
    }
    std::vector<T> temp(arr, arr + size);
    sort(temp);
    for (int i = 0; i < size; ++i) {
        arr[i] = temp[i];
    }
}

template <typename T>
void MergeSort<T>::mergeSort(std::vector<T>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
void MergeSort<T>::merge(std::vector<T>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<T> leftArr(n1);
    std::vector<T> rightArr(n2);

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) { // <= zachowuje stabilność dla duplikatów
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}