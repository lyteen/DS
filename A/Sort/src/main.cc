#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <numeric>
#include <cassert>
#include <functional> // Crucial: Include for std::function
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "simple_sort.hpp"
#include "common.hpp"
#define KeyType int
#define DataType int
#define MaxSize 90
using namespace std;
using namespace chrono;


typedef struct entry{
    KeyType key;
    DataType data;
}Entry;

typedef struct list
{
    int n;
    Entry D[MaxSize];
}List;




void testSortPerformance(std::function<void(std::vector<int>&)> sortFunc, const std::string& sortName, int num_elements, int num_runs) {
    cout << "\n--- " << sortName << " Performance (n = " << num_elements << ") ---\n";
    for (int run = 0; run < num_runs; ++run) {
        vector<int> data(num_elements);
        iota(data.begin(), data.end(), 0);

        random_device rd;
        mt19937 g(rd());
        shuffle(data.begin(), data.end(), g);

        auto start = high_resolution_clock::now();
        sortFunc(data);
        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Run " << run + 1 << " sort time: " << duration.count() << " milliseconds" << endl;
        assert(is_sorted(data.begin(), data.end()));
    }
}

int main() {
    const int num_runs = 5;
    std::vector<int> sizes = {500, 10000};

    for (int num_elements : sizes) {

        testSortPerformance([](std::vector<int>& data) {
            std::sort(data.begin(), data.end());
        }, "Heap Sort", num_elements, num_runs);

        // Test Selection Sort
        testSortPerformance(selectionSort<int>, "Selection Sort", num_elements, num_runs);

        // Test Bubble Sort
        testSortPerformance(bubbleSort<int>, "Bubble Sort", num_elements, num_runs);

        // Test Insertion Sort
        testSortPerformance(insertionSort<int>, "Insertion Sort", num_elements, num_runs);

        // Test Merge Sort
        testSortPerformance([](std::vector<int>& data){mergeSort(data, 0, data.size() - 1);}, "Merge Sort", num_elements, num_runs);

        // Test Quick Sort
        Quick_Sort<int> quickSort;
        testSortPerformance([&](std::vector<int>& data){quickSort.sort(data);}, "Quick Sort", num_elements, num_runs);

    }

    return 0;
}