/* 
    Author: Ryan Tandy
    Created: 02/11/2023
    LastUpdated: 02/11/2023
    License: GNU PL V3.0
*/

#ifndef BUBBLE_SORT_CPP
#define BUBBLE_SORT_CPP

#include <iostream>
#include <cstdint>
#include <random>
#include "../array-ds/Array.hpp"
#include "../helper-functions/HelperFunctions.cpp"



template <typename T1, typename T2>
void BubbleSort(T1 *array) {
    std::cout << "Unsorted array = " << std::endl;
    array->print();
    int len = array->length();
    T2 eleOne;
    T2 eleTwo;
    for (int j=1; j < len-1; j++) {
        for (int i=0; i < len-j; i++) {
            eleOne = array->getElement(i);
            eleTwo = array->getElement(i+1);
            if (eleOne > eleTwo) {
                array->setElement(i, eleTwo);
                array->setElement(i+1, eleOne);
            };
        };
    };
    std::cout << "Sorted array = " << std::endl; 
    array->print();
};

int main() {
    int len = 20;
    Array<int8_t> int8Array = Array<int8_t>(len);
    fillArrayWithRandomNumbers<Array<int8_t>, int8_t>(&int8Array);    
    BubbleSort<Array<int8_t>, int8_t>(&int8Array);
    return 0;
};


#endif

