/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

#ifndef TESTARRAYTYPES_CPP
#define TESTARRAYTYPES_CPP

#include "int8_tArray.hpp"
#include "testArrayTypes.hpp"
#include <iostream>

TestArrayTypes::TestArrayTypes() {};

int TestArrayTypes::LengthFunc_ReturnsCorrectLength(
        int (Int8Array::*length)(), 
        Int8Array array,
        int expectedLength
    ) {
    int len = (array.*length)();
    if (len == expectedLength) {
        std::cout << "Test testInt8ArrayLengthFunc() success." << std::endl;
        return 0;
    };
    std::cout << "Test testInt8ArrayLengthFunc() failed. ";
    std::cout << "Expected length = 5, got length = ";
    std::cout << len << std::endl;
    return -1;
};

int TestArrayTypes::testInt8ArraySizeFunc() {
    Int8Array array = Int8Array(5);
    int size = array.size();
    if (size == 5) {
        std::cout << "Test testInt8ArraySizeFunc() success." << std::endl;
        return 0;
    };
    std::cout << "Test testInt8ArraySizeFunc() failed. ";
    std::cout << "Expected size = 5 bytes, got size = ";
    std::cout << size << " bytes." << std::endl;
    return -1;
};

int TestArrayTypes::testInt8ArrayGetFunc() {
    Int8Array array = Int8Array(5);
    int8_t val = array.get(2);
    if (val == 0) {
        std::cout << "Test testInt8ArrayGetFunc() success." << std::endl;
        return 0;
    };
    std::cout << "Test testInt8ArrayGetFunc() failed. ";
    std::cout << "Expected value = 0, got value = ";
    int outVal = static_cast<int>(val);
    std::cout << outVal << std::endl;
    return -1;
};

int TestArrayTypes::testInt8ArraySetFunc() {
    Int8Array array = Int8Array(5);
    array.set(2, -1);
    int8_t setVal = array.get(2);
    if (setVal == -1) {
        std::cout << "Test testInt8ArraySetFunc() success." << std::endl;
        return 0;
    };
    std::cout << "Test testInt8ArraySetFunc() failed. ";
    std::cout << "Expected value = -1, got value = ";
    int outVal = static_cast<int>(setVal);
    std::cout << outVal << std::endl;
    return -1;
};

int TestArrayTypes::testInt8ArrayGetFuncWithOutOfRangeIdx() {
    Int8Array array = Int8Array(5);
    int testVals[2] = {-1, 6};
    int testValCnt = sizeof(testVals) / sizeof(int);
    int result;
    for (int i=0; i < testValCnt; i++) {
        int8_t val = array.get(testVals[i]);
        if (val == -127) {
            std::cout << "Test testInt8ArrayGetFuncWithOutOfRangeIdx() success. testVal = " << testVals[i] << std::endl;
        } else {
            std::cout << "Test testInt8ArrayGetFuncWithOutOfRangeIdx() failed. ";
            std::cout << "Expected value = -127, got value = ";
            int outVal = static_cast<int>(val);
            std::cout << outVal << std::endl;
            return -1;
        }
    }; 
    return 0;
};

int TestArrayTypes::testInt8ArrayConstructArrayWithTooManyElements() {
    try {
        Int8Array array = Int8Array(1000001);
        std::cout << "Test testInt8ArrayConstructArrayWithTooManyElements() failed. Was able to create an array with more elements than intended." << std::endl;
        return -1;
    } catch (const std::exception& e) {
        std::cout << "Test testInt8ArrayConstructArrayWithTooManyElements() success." << std::endl;
        return 0;
    }
};

int TestArrayTypes::testInt8ArrayConstructArrayWithMaxElements() {
    try {
        Int8Array array = Int8Array(1000000);
        std::cout << "Test testInt8ArrayConstructArrayWithMaxElements() success." << std::endl;
        return 0;
    } catch (const std::exception& e) {
        std::cout << "Test testInt8ArrayConstructArrayWithMaxElements() failed. Was able to create an array with more elements than intended." << std::endl;
        return -1;
    }
};

void Test_Int8Array_LengthFunc_ReturnsCorrectLength() {
    TestArrayTypes test;
    Int8Array array = Int8Array(5);
    int expectedLength = 5; 
    test.LengthFunc_ReturnsCorrectLength(&Int8Array::length, array, 5);
}

void runTests() {
}

#endif