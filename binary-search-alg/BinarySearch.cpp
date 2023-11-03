/* 
    Author: Ryan Tandy
    Created: 02/11/2023
    LastUpdated: 02/11/2023
    License: GNU PL V3.0
*/

#ifndef BINARY_SEARCH_CPP
#define BINARY_SEARCH_CPP

#include <iostream>
#include <cstdint>
#include "../array-ds/Array.hpp"

template <typename T1, typename T2>
int BinarySearch(T1 *array, T2 val) {
    int len = array->length();
    int mid;
    int hi = len;
    int lo = 0;
    while(1) {
        mid = lo + (hi - lo) / 2;
        T2 midVal = array->getElement(mid);
        if (midVal == val) {
            return mid;
        };
        if (val < midVal) {
            hi = mid;
        };
        if (val > midVal) {
            lo = mid + 1;
        };
        if (hi == lo) {
            break;
        };
    };
    throw std::invalid_argument(
        "Value " + std::to_string(val) + " not found in the array.");
};

int main() {
    Array<int8_t> int8Array = Array<int8_t>(19);
    int8_t val;
    for (int i=0; i < int8Array.length(); i++) {
        val = i*2;
        int8Array.setElement(i, val);
    };
    int8Array.print();
    int8_t findVal = 12;
    int idx;
    try {
        idx = BinarySearch<Array<int8_t>, int8_t>(&int8Array, findVal);
        std::cout << "index of val = " << idx << std::endl;
    } catch (const std::exception& e) {
        std::cout << "index of val = " << -1 << std::endl;
    }
    return 0;
};

#endif