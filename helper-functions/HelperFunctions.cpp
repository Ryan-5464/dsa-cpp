#ifndef HELPER_FUNCTIONS_CPP
#define HELPER_FUNCTIONS_CPP

#include <iostream>
#include <random>
#include "../array-ds/Array.hpp"

template <typename T1, typename T2>
void fillArrayWithRandomNumbers(T1 *array) {
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    T2 minVal = 1;
    T2 maxVal = 100;
    T2 randNum;
    std::uniform_int_distribution<int> distribution(minVal, maxVal);
    for (int i=0; i < array->length(); i++) {
        randNum = static_cast<T2>(distribution(gen));
        array->setElement(i, randNum);
    };
};

#endif