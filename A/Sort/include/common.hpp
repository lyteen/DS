// common.hpp
#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>
#include <vector>

template <typename T>
void printArray(const std::vector<T>& arr) {
    for (const auto& element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

#endif // COMMON_HPP