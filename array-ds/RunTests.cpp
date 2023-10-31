/* 
    Author: Ryan Tandy
    Created: 31/10/2023
    LastUpdated: 31/10/2023
    License: GNU PL V3.0

    Notes: Tests cover types with guaranteed size only.
*/

#ifndef RUN_TESTS_CPP
#define RUN_TESTS_CPP

#include <iostream>
#include <cstdint>
#include "Array.hpp"
#include "Array-Test.hpp"


void testArray_length() {
    ArrayTest test;
    std::string funcName = "testArray_length_returnsCorrectLength: ";
    Array<int8_t> array = Array<int8_t>(5);
    test.testArray_length_returnsCorrectLength(&array, 5, funcName + "int8_t");
};

void testArray_size() {
    ArrayTest test;
    std::string funcName = "testArray_size_returnsCorrectSize: ";
    
    Array<int8_t> int8array = Array<int8_t>(5);
    test.testArray_size_returnsCorrectSize(&int8array, 5, funcName + "int8_t");
    
    Array<int16_t> int16array = Array<int16_t>(5);
    test.testArray_size_returnsCorrectSize(&int16array, 10, funcName + "int16_t");
    
    Array<int32_t> int32array = Array<int32_t>(5);
    test.testArray_size_returnsCorrectSize(&int32array, 20, funcName + "int32_t");
    
    Array<int64_t> int64array = Array<int64_t>(5);
    test.testArray_size_returnsCorrectSize(&int64array, 40, funcName + "int64_t");

    Array<char16_t> char16Array = Array<char16_t>(5);
    test.testArray_size_returnsCorrectSize(&char16Array, 10, funcName + "char16_t");

    Array<char32_t> char32Array = Array<char32_t>(5);
    test.testArray_size_returnsCorrectSize(&char32Array, 20, funcName + "char32_t");
};

void testArray_constructor() {
    ArrayTest test;
    std::string passFuncName = "testArray_constructor_createMaxLenArraySuccess"; 
    std::string failFuncName = "testArray_constructor_throwsErrorIfArrayLengthToLarge";

    test.testArray_constructor_createMaxLenArraySuccess<Array<int8_t>>(1000000, passFuncName);

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<int8_t>>(10000001, failFuncName);

    test.testArray_constructor_createMaxLenArraySuccess<Array<int16_t>>(500000, passFuncName);

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<int16_t>>(500001, failFuncName);

    test.testArray_constructor_createMaxLenArraySuccess<Array<int32_t>>(250000, passFuncName);

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<int32_t>>(250001, failFuncName);

    test.testArray_constructor_createMaxLenArraySuccess<Array<int64_t>>(125000, passFuncName);

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<int64_t>>(125001, failFuncName);

    test.testArray_constructor_createMaxLenArraySuccess<Array<char16_t>>(500000, passFuncName);

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<char16_t>>(500001, failFuncName);

    test.testArray_constructor_createMaxLenArraySuccess<Array<char32_t>>(250000, passFuncName);

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<char32_t>>(250001, failFuncName);
};

void testArray_getElement() {
    ArrayTest test;
    std::string passFuncName = "testArray_get_returnsCorrectElement"; 
    std::string failFuncName = "testArray_get_throwsErrorIfIndexOutOfRange";

    Array<int8_t> int8Array = Array<int8_t>(5);
    test.testArray_get_returnsCorrectElement(&int8Array, 4, 0, passFuncName);
    test.testArray_get_throwsErrorIfIndexOutOfRange(&int8Array, 5, 0, failFuncName);
    test.testArray_get_throwsErrorIfIndexOutOfRange(&int8Array, -1, 0, failFuncName);

    Array<int16_t> int16Array = Array<int16_t>(5);
    test.testArray_get_returnsCorrectElement(&int16Array, 4, 0, passFuncName);
    test.testArray_get_throwsErrorIfIndexOutOfRange(&int16Array, 5, 0, failFuncName);
    test.testArray_get_throwsErrorIfIndexOutOfRange(&int16Array, -1, 0, failFuncName);
};


int main() {
    testArray_length();
    testArray_size();
    testArray_constructor();
    testArray_getElement();
    return 0;
};

#endif