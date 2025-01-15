#include "queue.hpp"
#include <chrono>
#include <random>
#include <vector>
#include <algorithm>
using namespace std::chrono;

int main() {
    // init the queue
    PriorityQueue<int, vector<int>, greater<int>> MaxQueue; 
    MaxQueue.push(5);
    MaxQueue.push(2);
    MaxQueue.push(8);
    MaxQueue.push(10);
    MaxQueue.push(4);
    MaxQueue.push(2);
    MaxQueue.push(30);
    MaxQueue.push(81);
    MaxQueue.push(3);
    MaxQueue.push(1);
    
    // Test queue output
    cout << "Queue element: ";
    while (!MaxQueue.empty()) {
        cout << MaxQueue.top() << " ";
        MaxQueue.pop();
    }
    cout << endl;

    std::vector<int> sizes = {500, 10000, 50000, 100000};

    for (int num_elements : sizes) {
        std::cout << "\n--- Queue Performance (n = " << num_elements << ") ---\n";

        std::vector<int> data(num_elements);
        std::iota(data.begin(), data.end(), 0);

        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(data.begin(), data.end(), g);

        PriorityQueue<int> MaxQueue; // Create a new queue for each size

        // Measure push() performance
        auto start = high_resolution_clock::now();
        for (int x : data) {
            MaxQueue.push(x);
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "Push time: " << duration.count() << " milliseconds" << endl;

        // Measure pop() performance
        start = high_resolution_clock::now();
        while (!MaxQueue.empty()) {
            MaxQueue.pop();
        }
        end = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(end - start);
        cout << "Pop time: " << duration.count() << " milliseconds" << endl;
    }
    return 0;
}
