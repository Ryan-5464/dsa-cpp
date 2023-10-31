/* 
    Author: Ryan Tandy
    Created: 31/10/2023
    LastUpdated: 31/10/2023
    License: GNU PL V3.0
*/

#ifndef RUN_TESTS_CPP
#define RUN_TESTS_CPP
#define CHECK_TEST_RESULT(res, exp, funcName) \
    if (res != exp) { \
        std::cout << "Test failed! for function "; \
        std::cout << funcName << std::endl; \
        return false; \
    } \
    std::cout << "PASSED: " << funcName << std::endl;

#include <iostream>
#include <cstdint>
#include "Array.hpp"
#include "Array-Test.hpp"


bool testArray_length() {
    ArrayTest test;
    bool result;
    Array<int8_t> array = Array<int8_t>(5);
    result = test.testArray_length_returnsCorrectLength(&array, 5);
    CHECK_TEST_RESULT(result, true, "testArray_length_returnsCorrectLength")
    return true;
};


int main() {
    bool result = testArray_length();
    return 0;
};

#endif