/* 
    Author: Ryan Tandy
    Created: 30/10/2023
    LastUpdated: 01/11/2023
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

        Array() : _length(0), _size(0), _head(nullptr) {};

        Array(int len) : _length(len) {
            _size = _length * sizeof(T);
            if (_size > _MAX_SIZE_BYTES) {
                int const maxLength = _MAX_SIZE_BYTES / sizeof(T);
                throw std::invalid_argument("Desired length too large. Max number of elements the array can hold is = " + std::to_string(maxLength));
            }
            _head = new T[_length]; // Need to delete this?
            T defaultVal = 0;
            for (int i=0; i < _length; i++) {
                _head[i] = defaultVal;
            }         
        };
                
        ~Array() {
            delete _head;
        };

        void print() {
            int outVal;
            std::cout << "array = {";
            for (int i=0; i <_length; i++) {
                int outVal = static_cast<int>(_head[i]);
                std::cout << outVal << ", ";
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
                throw std::invalid_argument("Error: Index out of range. Allowed index range = 0 -> " + std::to_string(_length - 1));
            }
            return _head[idx];
        };

        T setElement(int idx, T val) {
            if ((idx >= _length) || (idx < 0)) {
                throw std::invalid_argument("Error: Index out of range. Allowed index range = 0 -> " + std::to_string(_length - 1));
            }
            if ((idx >= _length) || (idx < 0)) {
                throw std::invalid_argument("Error: Index out of range. Allowed index range = 0 -> " + std::to_string(_length - 1));
            }
            _head[idx] = val;
            return 0;
        };
};

#endif





