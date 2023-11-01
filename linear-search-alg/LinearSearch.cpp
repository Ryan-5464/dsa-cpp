/* 
    Author: Ryan Tandy
    Created: 01/11/2023
    LastUpdated: 01/11/2023
    License: GNU PL V3.0
*/

#ifndef LINEAR_SEARCH_CPP
#define LINEAR_SEARCH_CPP

#include <iostream>
#include <cstdint>
#include "../array-ds/Array.hpp"

template <typename T1, typename T2>
int LinearSearch(T1 *array, T2 val) {
    int len = array->length();
    for (int i=0; i < len; i++) {
        if (array->getElement(i) == val) {
            return i;
        };
    };
    throw std::invalid_argument(
        "Value " + std::to_string(val) + " not found in the array.");
};

// int main() {
//     Array<int8_t> int8Array = Array<int8_t>(5);
//     int8_t val;
//     for (int i=0; i < int8Array.length(); i++) {
//         val = i;
//         int8Array.setElement(i, val);
//     };
//     int8Array.print();
//     int8_t findVal = 1;
//     int idx;
//     try {
//         idx = LinearSearch<Array<int8_t>, int8_t>(&int8Array, findVal);
//         std::cout << "index of val = " << idx << std::endl;
//     } catch (const std::exception& e) {
//         std::cout << "index of val = " << -1 << std::endl;
//     }
//     return 0;
// };

#endif