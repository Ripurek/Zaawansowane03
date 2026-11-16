#pragma once
#include <vector>

template <typename T>
class MergeSort {
public:
    void sort(std::vector<T>& arr);
    void sort(T* arr, int size);

private:
    void mergeSort(std::vector<T>& arr, int left, int right);
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