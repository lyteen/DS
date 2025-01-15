#ifndef QUICK_SORT
#define QUICK_SORT
#include <iostream>
#include <vector> // use vector Test sort
#include <algorithm>

using namespace std;
template<typename T, typename Container = vector<T>> // use less Test quick_sort
class Quick_Sort{
private:
    Container arr;
    int partition(Container& arr, int low, int high){
        T pivot = arr[low];
        int i = low, j = high + 1;
        while (true) {
            do {
                i++;
            } while (i <= high && arr[i] < pivot); // check left element.key < pivot.key

            do {
                j--;
            } while (arr[j] > pivot); // check right element.key > pivot.key

            if (i >= j) {
                break; // exit the loop when pointers cross
            }
            std::swap(arr[i], arr[j]); // swap left element and right element if they dont fit rule
        }
        std::swap(arr[low], arr[j]);
        return j; // return new pivot index
    }
public:
    void quickSort(Container& arr, int low, int high){
        if(low < high){
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    void sort(Container& arr){
        quickSort(arr, 0, arr.size() - 1);
    }
};
#endif //QUICK_SORT