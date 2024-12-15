#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2; // Save to array
            if (heap[index] <= heap[parent]) break;
            // Make the bigger element into the top
            else swap(heap[index], heap[parent]); 
            index = parent; 
        }
    }
    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1; // Since in the array the child node is 2 * i + x(l=1 or r = 2)
            int right = 2 * index + 2;
            int largest = index;
            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest == index) break;
            swap(heap[index], heap[largest]);
            index = largest;
        }
    }
public:
    // Insert new element into the priority queue
    void push(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    // Access the maximum element (highest priority element)
    int top() const {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        return heap[0];
    }
    // Remove the maximum element
    void pop() {
        if (heap.empty()) {
            throw runtime_error("Priority queue is empty");
        }
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            heapifyDown(0);
        }
    }
    // Check if the priority queue is empty
    bool empty() const {
        return heap.empty();
    }
};