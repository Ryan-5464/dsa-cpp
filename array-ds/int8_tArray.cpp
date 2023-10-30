/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

#ifndef INT8_TARRAY_CPP
#define INT8_TARRAY_CPP

#include "int8_tArray.hpp"
#include <cstdint>
#include <iostream>

Int8Array::Int8Array(int len) : _length(len) {
    _size = _length * sizeof(int8_t);
    if (_size > _MAX_SIZE_BYTES) {
        int const MAX_LENGTH = _MAX_SIZE_BYTES / sizeof(int8_t);
        throw std::invalid_argument("Desired length too large. Max number of elements the array can hold is = " + std::to_string(MAX_LENGTH));
    }
    _head = new int8_t[_length];
    for (int i=0; i < _length; i++) {
        _head[i] = 0;
    }
};

Int8Array::~Int8Array() {
    delete _head;
}

int Int8Array::length() {
    return _length;
}

int Int8Array::size() {
    return _size;
}

void Int8Array::print() {
    std::cout << "Array = {";
    for (int i=0; i < _length; i++) {
        std::cout << _head[i] << ",";
    }
    std::cout << "}" << std::endl;
}

int8_t Int8Array::get(int idx) {
    if ((idx >= _length) || (idx < 0)) {
        std::cout << "Error: Index out of range. Max allowed index = ";
        std::cout << _length - 1 << std::endl; 
        return -127;
    }
    return _head[idx];
}

int Int8Array::set(int idx, int val) {
    if ((idx >= _length) || (idx < 0)) {
        std::cout << "Error: Index out of range. Max allowed index = ";
        std::cout << _length - 1 << std::endl; 
        return -127;
    }
    if ((idx >= _length) || (idx < 0)) {
        std::cout << "Error: Index out of range. Max allowed index = ";
        std::cout << _length - 1 << std::endl; 
        return -127;
    }
    _head[idx] = val;
    return 0;
}

#endif