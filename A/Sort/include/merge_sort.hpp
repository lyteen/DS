#ifndef MERGE_SORT
#define MERGE_SORT
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
template <typename T>
void merge(std::vector<T>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    std::copy(arr.begin() + left, arr.begin() + middle + 1, L.begin());
    std::copy(arr.begin() + middle + 1, arr.begin() + right + 1, R.begin());

    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = left; // Initial index of merged subarray

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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(std::vector<T>& arr, int left, int right) {
    if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
#endif //MERGE_SORT