/* 
    Author: Ryan Tandy
    Created: 31/10/2023
    LastUpdated: 01/11/2023
    License: GNU PL V3.0

    Notes: 2 types with known sizes, int8_t & int16_t are used to test the array
    template.
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
    
    test.testArray_length_returnsCorrectLength(
        &array, 5, funcName + " int8_t"
    );
};

void testArray_size() {
    ArrayTest test;
    std::string funcName = "testArray_size_returnsCorrectSize: ";
    Array<int8_t> int8array = Array<int8_t>(5);
    Array<int16_t> int16array = Array<int16_t>(5);
    
    test.testArray_size_returnsCorrectSize(
        &int8array, 5, funcName + " int8_t"
    );
    
    test.testArray_size_returnsCorrectSize(
        &int16array, 10, funcName + " int16_t"
    );
};

void testArray_constructor() {
    ArrayTest test;
    std::string passFuncName = "testArray_constructor_createMaxLenArraySuccess"; 
    std::string failFuncName = "testArray_constructor_throwsErrorIfArrayLengthToLarge";

    test.testArray_constructor_createMaxLenArraySuccess<Array<int8_t>>(
        1000000, passFuncName + " int8_t"
    );

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<int8_t>>(
        10000001, failFuncName + " int8_t"
    );

    test.testArray_constructor_createMaxLenArraySuccess<Array<int16_t>>(
        500000, passFuncName + " int16_t"
    );

    test.testArray_constructor_throwsErrorIfArrayLengthToLarge<Array<int16_t>>(
        500001, failFuncName + " int16_t"
    );
};

/*  Necessary to test both getElement and setElement as setElement is needed
    to set a unique value so that getElement can be tested to make sure it is 
    returning the correct bytes in memory. 
*/
void testArray_getElementAndSetElement() {
    ArrayTest test;
    std::string passFuncName = "testArray_get_set_setsAndReturnsCorrectElement"; 
    int8_t setVal = 1;
    int8_t expVal = 1;
    int idx = 4;
    Array<int8_t> int8Array = Array<int8_t>(5);
    Array<int16_t> int16Array = Array<int16_t>(5);

    test.testArray_get_set_setsAndReturnsCorrectElement(
        &int8Array, idx, setVal, expVal, passFuncName + " int8_t"
    );

    test.testArray_get_set_setsAndReturnsCorrectElement(
        &int16Array, idx, setVal, expVal, passFuncName + " int16_t"
    );
    
};

void testArray_getElement() {
    ArrayTest test;
    std::string failFuncName = "testArray_get_throwsErrorIfIndexOutOfRange";
    int gtrThanMaxIdx = 5;
    int lesThanMinIdx = -1;
    Array<int8_t> int8Array = Array<int8_t>(5);
    Array<int16_t> int16Array = Array<int16_t>(5);

    test.testArray_get_throwsErrorIfIndexOutOfRange(
        &int8Array, gtrThanMaxIdx, failFuncName + " int8_t"
    );
    
    test.testArray_get_throwsErrorIfIndexOutOfRange(
        &int8Array, lesThanMinIdx, failFuncName + " int8_t"
    );
    
    test.testArray_get_throwsErrorIfIndexOutOfRange(
        &int16Array, gtrThanMaxIdx, failFuncName + " int16_t"
    );
    
    test.testArray_get_throwsErrorIfIndexOutOfRange(
        &int16Array, lesThanMinIdx, failFuncName + " int16_t"
    );
};

void testArray_setElement() {
    ArrayTest test;
    std::string failFuncName = "testArray_set_throwsErrorIfIndexOutOfRange";
    int8_t setVal = 1;
    int gtrThanMaxIdx = 5;
    int lesThanMinIdx = -1;
    Array<int8_t> int8Array = Array<int8_t>(5);
    Array<int16_t> int16Array = Array<int16_t>(5);

    test.testArray_set_throwsErrorIfIndexOutOfRange(
        &int8Array, gtrThanMaxIdx, setVal, failFuncName + " int8_t"
    );
    
    test.testArray_set_throwsErrorIfIndexOutOfRange(
        &int8Array, lesThanMinIdx, setVal, failFuncName + " int8_t"
    );
    
    test.testArray_set_throwsErrorIfIndexOutOfRange(
        &int16Array, gtrThanMaxIdx, setVal, failFuncName + " int16_t"
    );
    
    test.testArray_set_throwsErrorIfIndexOutOfRange(
        &int16Array, lesThanMinIdx, setVal, failFuncName + " int16_t"
    );
};



int main() {
    testArray_length();
    testArray_size();
    testArray_constructor();
    testArray_getElementAndSetElement();
    testArray_getElement();
    testArray_setElement(); 
    return 0;
};

#endif