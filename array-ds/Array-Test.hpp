/* 
    Author: Ryan Tandy
    Created: 31/10/2023
    LastUpdated: 31/10/2023
    License: GNU PL V3.0
*/

#ifndef ARRAY_TEST_HPP
#define ARRAY_TEST_HPP
#define TEST_FAIL(func) \
    std::cout << "Test failed! for function "; \
    std::cout << funcName << std::endl; \
    exit(0); 
#define TEST_PASS(func) \
    std::cout << "PASSED: " << funcName << std::endl;

#include <iostream>

class ArrayTest {
    public:
        ArrayTest() {};

        template <typename T>
        void testArray_length_returnsCorrectLength(
                T *array, 
                int expLen,
                std::string funcName 
            ) {
                if (array->length() == expLen) {
                    TEST_PASS(funcName);
                } else{
                    std::cout << "Length = " << array->length() << std::endl;
                    std::cout << "Expected length = " << expLen << std::endl;
                    TEST_FAIL(funcName);
                };
        };
        
        template <typename T>
        void testArray_size_returnsCorrectSize(
            T *array,
            int expSize,
            std::string funcName
        ) {
            if (array->size() == expSize) {
                TEST_PASS(funcName);
            } else {
                std::cout << "Size = " << array->size() << std::endl;
                std::cout << "Expected size = " << expSize << std::endl;
                TEST_FAIL(func);
            };
        };
        
        template <typename T>
        void testArray_constructor_createMaxLenArraySuccess(
            int len,
            std::string funcName
        ) {
            try {
                T Array(len);
                TEST_PASS(funcName);
            } catch (const std::exception& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
                TEST_FAIL(funcName);
            }
        };
        
        template <typename T>
        void testArray_constructor_throwsErrorIfArrayLengthToLarge(
            int len,
            std::string funcName
        ) {
            try {
                T Array(len);
                TEST_FAIL(funcName);
            } catch (const std::exception& e) {
                std::cerr << "Exception: " << e.what() << std::endl;
                TEST_PASS(funcName);
            }
        };

        bool testArray_get_returnsCorrectElement();
        bool testArray_get_throwsErrorIfIndexOutOfRange();
        bool testArray_set_setsElementCorrectly();
        bool testArray_set_throwsErrorIfIndexOutOfRange();
};

#endif

/*
    Test cases:
        test length
        test size for each type
        test set element for each type
        test get element for each type
        test constructor
*/