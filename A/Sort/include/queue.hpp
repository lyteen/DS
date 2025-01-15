#ifndef QUEUE
#define QUEUE
#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
// priority_queue
// use template
// use enum
enum class Queue_Status{
    NoElement,
    MaxNamber = 10000   
};
enum Status{
    Nodata,
    MaxIndex = 10000,
    MinIndex = 0
};

// construction Array
template<typename T>
class Array{
private:
    T* data;
    size_t capacity;
    size_t n_sizes;

    // resize the memory
    void resize(size_t size){
        if(size > capacity){
            size_t new_cap = capacity == 0 ? 1 : capacity * 2;
            while(new_cap < size){
                new_cap = new_cap * 2;
            }
            T* new_data = new T[new_cap];
            for(size_t i = 0; i < n_sizes; i++){
                new_data[i] = data[i];
            }

            delete[] data;
            data = new_data;
            capacity = new_cap;
        }
        n_sizes = size;
    }
public:
    // inited distribution: 10 capacity
    Array(size_t cap = 10) : capacity(cap), n_sizes(0){
        data = new T[capacity];
    }
    // release the memory
    ~Array(){
        delete[] data;
    }

    // push back the value
    void push_back(const T& value){
        if(CheckOverUpper()) return;
        if(n_sizes == capacity){
            resize(n_sizes + 1);
        }
        data[n_sizes++] = value;
    }

    // destory last element
    void pop_back(){
        if(CheckOverLower()) return;
        data[size - 1].~T();
        --n_sizes;
    }

    // return last element
    inline T& back(){
        if(CheckOverLower()) return NULL;
        return data[n_sizes - 1];
    }

    // use the index visit the data
    inline T& operator[](size_t index){
        if (index >= n_sizes) {
            throw std::out_of_range("Index out of Upper Bounds");
        }
        if(index > 0 && index < n_sizes){
            return data[index];
        }else{
            return NULL;
        }
    }

    // get the current size
    inline size_t size() const{
        return n_sizes;
    }

    // check is_empty
    inline bool empty() const{
        if(n_sizes == 0){
            return true;
        }else{
            return false;
        }
    }

    inline void clear(){
        for(size_t i = 0; i < n_sizes; i++){
            data[i].~T();
        }
        n_sizes = 0;
    }

    // check the upperoverflow
    inline bool CheckOverUpper(){
        if(n_sizes >= Status::MaxIndex){
            cout << "overflow the Upper Bound" << endl;
            return true;
        }
        return false;
    }

    // check the loweroverflow
    inline bool CheckOverLower(){
        if(n_sizes <= Status::MaxIndex){
            cout << "overflow the Lower Bound" << endl;
            return true;
        }
        return false;
    }

};

// use `functional` less compare two element e.g. if <int> 6 > 4 -> true, <char> ASCII value b > a
template<typename T, typename Container = vector<T>, typename Compare = std::less<T>>
class PriorityQueue{
private:
    Container heap;
    Compare comp;

    // from new element to root element, make sure the heap fit the compare rule
    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;
            if(comp(heap[index], heap[parent])){
                break;
            }
            std::swap(heap[index], heap[parent]); // if current element 
            index = parent;
        }
    }

    // pop the element make sure the heap structure fit your rule
    void heapifyDown(int index){
        int size = heap.size();
        while(true){
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if(leftChild < size && comp(heap[largest], heap[leftChild])){
                largest = leftChild;
            }
            if(rightChild < size && comp(heap[largest], heap[rightChild])){
                largest = rightChild;
            }
            if(largest == index){
                break;
            }
            std::swap(heap[index], heap[largest]);
            index = largest;
        }
    }
public:
    // default constructor
    PriorityQueue() : comp(Compare()) {}

    // custom constructor
    explicit PriorityQueue(const Compare& compare) : comp(compare) {}

    // push element
    void push(const T& value){
        heap.push_back(value);
        heapifyUp(heap.size() - 1); // e.g. if comp is `less` and value > parent_value -> swap the value and parent_value
    }

    // check is_empty
    inline bool empty() const{
        return heap.empty();
    }

    // get the root element
    inline T& top(){
        if(empty()){
            throw std::out_of_range("PriorityQueue is empty"); // if empty catch the error info
        }
        return heap[0]; // return the first element
    }

    // rearrange the binary queue
    void pop(){
        if(empty()){
            throw std::out_of_range("PriorityQueue is empty"); // if empty catch the error info
            return;
        }
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back(); // pop the last element
        heapifyDown(0); // from root element, make sure last element (new_root) fit the arrange rule
    }

    // clear all element
    void clear(){
        heap.clear();
    }

    // get the size of queue
    inline size_t size() const{
        return heap.size();
    }
};
#endif