/* 
    Author: Ryan Tandy
    Created: 30/10/2023
    LastUpdated: 31/10/2023Test
    License: GNU PL V3.0
*/

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> 
class Array {
    
    private:
        int const _MAX_SIZE_BYTES = 1000000;
        int _length;
        int _size;
        T *_head;

    public:
        Array(int len) : _length(len) {
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
                
        ~Array() {
            delete _head;
        };

        void print() {
            std::cout << "array = {";
            for (int i=0; i <_length; i++) {
                std::cout << _head[i] << ", ";
            };
            std::cout << "}" << std::endl;
        };

        int length() {
            return _length;
        };

        int size() {
            return _size;
        };


        T getElement(int idx) {
            if ((idx >= _length) || (idx < 0)) {
                std::cout << "Error: Index out of range. Max allowed index = ";
                std::cout << _length - 1 << std::endl; 
                return -127;
            }
            return _head[idx];
        };

        T setElement(int idx, T val) {
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
};

#endif





