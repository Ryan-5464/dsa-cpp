/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include <iostream>

template <typename T> 
Array<T>::Array(int len) {
    _size = _length * sizeof(T);
    if (_size > _MAX_SIZE_BYTES) {
        int const maxLength = _MAX_SIZE_BYTES / sizeof(T);
        throw std::invalid_argument("Desired length too large. Max number of elements the array can hold is = " + std::to_string(maxLength));
    }
    _head = new T[_length];
    for (int i=0; i < _length; i++) {
        _head[i] = 0;
    }         
};
        
template <typename T> 
Array<T>::~Array() {
    delete _head;
};

template <typename T>
void Array<T>::print() {
    std::cout << "array = {";
    for (int i=0; i <_length; i++) {
        std::cout << _head[i] << ", ";
    };
    std::cout << "}" << std::endl;
};

template <typename T>
int Array<T>::length() {
    return _length;
};

template <typename T>
int Array<T>::size() {
    return _size;
};

template <typename T>
T Array<T>::getElement(int idx) {
    if ((idx >= _length) || (idx < 0)) {
        std::cout << "Error: Index out of range. Max allowed index = ";
        std::cout << _length - 1 << std::endl; 
        return -127;
    }
    return _head[idx];
};

template <typename T>
T Array<T>::setElement(int idx, T val) {
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
};

#endif

