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
    _head = new int8_t[_length];
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
    return _head[idx];
}

void Int8Array::set(int idx, int val) {
    _head[idx] = val;
}

#endif