/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

#ifndef INT8_TARRAY_HPP
#define INT8_TARRAY_HPP

#include <cstdint>

class Int8Array {

private:
    int const _MAX_SIZE_BYTES = 1000000; 
    int _length;
    int _size;
    int8_t *_head;

public:
    Int8Array(int len);
    ~Int8Array();
    int length();
    int size();
    void print();
    
    int8_t get(int idx);
    int set(int idx, int val);
};

#endif