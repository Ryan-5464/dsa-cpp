#ifndef LINEAR_SEARCH_TEST_CASES_CPP
#define LINEAR_SEARCH_TEST_CASES_CPP

#include <iostream>
#include <cstdint>

#include "LinearSearch.cpp"
#include "LinearSearchTest.cpp"
#include "../array-ds/Array.hpp"

void testLinearSearch() {
    LinearSearchTest test;
    std::string passFuncName = "test_LinearSearch_returnsCorrectIndexForValidValue";
    std::string failFuncName = "test_LinearSearch_throwsErrorValueNotExistInArray";
    Array<int8_t> int8Array = Array<int8_t>(5);
    for (int i=0; i < int8Array.length(); i++) {
        int8Array.setElement(i, static_cast<int8_t>(i*2));
    }
    
    test.test_LinearSearch_returnsCorrectIndexForValidValue(
        &int8Array, 6, passFuncName + " int8_t"
    );

    test.test_LinearSearch_throwsErrorValueNotExistInArray(
        &int8Array, 777, failFuncName + " int8_t"
    );
};

int main() {
    testLinearSearch();
    return 0;
};

#endif