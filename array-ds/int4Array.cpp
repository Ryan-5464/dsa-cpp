#include "int4Array.hpp"
#include <iostream>


int4Array::int4Array(int len) {
    length = len;
    start = new int[len];
}