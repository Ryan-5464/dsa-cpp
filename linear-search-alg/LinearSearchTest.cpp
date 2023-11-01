/* 
    Author: Ryan Tandy
    Created: 30/10/2023
    LastUpdated: 01/11/2023Test
    License: GNU PL V3.0
*/

#ifndef LINEAR_SEARCH_TEST_CPP
#define LINEAR_SEARCH_TEST_CPP

#include <iostream>
#include "LinearSearch.cpp"

#define TEST_FAIL(funcName) \
    std::cout << "FAIL: Test failed! for function "; \
    std::cout << funcName << std::endl; \
    exit(0); 
#define TEST_PASS(funcName) \
    std::cout << "PASSED: " << funcName << std::endl;

class LinearSearchTest {
    
    public:
        LinearSearchTest() {};

        template <typename T1, typename T2>
        void test_LinearSearch_returnsCorrectIndexForValidValue(
            T1 *array,
            T2 val,
            std::string funcName
        ) {
            int idx;
            try {
                idx = LinearSearch<T1, T2>(array, val);
                TEST_PASS(funcName);
            } catch (const std::exception& e) {
                std::cout << "FAIL: value not found. " << idx << std::endl;
                TEST_FAIL(funcName);
            }
        };

        template <typename T1, typename T2>
        void test_LinearSearch_throwsErrorValueNotExistInArray(
            T1 *array,
            T2 val,
            std::string funcName
        ) {
            int idx;
            try {
                idx = LinearSearch<T1, T2>(array, val);
                std::cout << "FAIL: value found in array, idx = ";
                std::cout << idx << std::endl;
                TEST_FAIL(funcName);
            } catch (const std::exception& e) {
                TEST_PASS(funcName);
            }
        };
};

#endif
