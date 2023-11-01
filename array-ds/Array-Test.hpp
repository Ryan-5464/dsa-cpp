/* 
    Author: Ryan Tandy
    Created: 31/10/2023
    LastUpdated: 01/11/2023
    License: GNU PL V3.0
*/

#ifndef ARRAY_TEST_HPP
#define ARRAY_TEST_HPP
#define TEST_FAIL(funcName) \
    std::cout << "FAIL: Test failed! for function "; \
    std::cout << funcName << std::endl; \
    exit(0); 
#define TEST_PASS(funcName) \
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
                    std::cout << "FAIL: Length = " << array->length() << std::endl;
                    std::cout << "FAIL: Expected length = " << expLen << std::endl;
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
                std::cout << "FAIL: Size = " << array->size() << std::endl;
                std::cout << "FAIL: Expected size = " << expSize << std::endl;
                TEST_FAIL(funcName);
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
                std::cerr << "FAIL: Exception: " << e.what() << std::endl;
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

        template <typename T1, typename T2>
        void testArray_get_set_setsAndReturnsCorrectElement(
            T1 *array,
            int idx,
            T2 setVal,
            T2 expVal,
            std::string funcName
        ) {
            array->setElement(idx, setVal);
            T2 element = array->getElement(idx);
            if (element == expVal) {
                TEST_PASS(funcName);
            } else {
                int intElement = static_cast<int>(element); 
                int intExpVal = static_cast<int>(expVal); 
                std::cout << "FAIL: Value = " << intElement << std::endl;
                std::cout << "FAIL: Expected value = " << intExpVal << std::endl;
                TEST_FAIL(funcName);
            };
        };

        template <typename T>
        void testArray_get_throwsErrorIfIndexOutOfRange(
            T *array,
            int idx,
            std::string funcName
        ) {
            try {
                int element = array->getElement(idx);
                std::cout << "Index in range. Index = " << idx <<std::endl;
                TEST_FAIL(funcName);
            } catch (const std::exception& e) {
                TEST_PASS(funcName);
            };
        };

        template <typename T1, typename T2>
        void testArray_set_throwsErrorIfIndexOutOfRange(
            T1 *array,
            int idx,
            T2 setVal,
            std::string funcName
        ) {
            try {
                T2 element = array->setElement(idx, setVal);
                std::cout << "FAIL: Index in range. Index = " << idx <<std::endl;
                TEST_FAIL(funcName);
            } catch (const std::exception& e) {
                TEST_PASS(funcName);
            };
        };

};

#endif
