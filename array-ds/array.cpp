#include "array.hpp"
# include <iostream>



int Array::getLength() {
    return length; 
}

int Array::getSize() {
    return sizeof(int) * length;
}

int Array::getElement(int idx) {
    if (!(idx < length)) {
        printf("ERROR: index out of range. Max index = %d \n", length);
        return -1;
    }
    return start[idx];
}

void Array::printArray() {
    std::cout << "Array = {";
    for (int i=0; i < length; i++) {
        std::cout << start[i] << ",";
    }
    std::cout << "} \n" << std::endl;
}

int Array::setElement(int idx, int val) {
    if (!(idx < length)) {
        printf("ERROR: index out of range. Max index = %d \n", length);
        return -1;
    }
    start[idx] = val;
    return 0;
}