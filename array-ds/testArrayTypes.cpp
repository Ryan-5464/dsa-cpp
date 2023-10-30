#ifndef TESTARRAYTYPES_CPP
#define TESTARRAYTYPES_CPP

#include "int8_tArray.hpp"
#include "testArrayTypes.hpp"
#include <iostream>

TestArrayTypes::TestArrayTypes() {};

int TestArrayTypes::testInt8ArrayLengthFunc() {
    Int8Array array = Int8Array(5);
    int len = array.length();
    if (len == 5) {
        std::cout << "Test testInt8ArrayLengthFunc() success." << std::endl;
        return 0;
    };
    std::cout << "Test testInt8ArrayLengthFunc() failed. ";
    std::cout << "Expected length = 5, got length = ";
    std::cout << len << std::endl;
    return -1;
};

#endif