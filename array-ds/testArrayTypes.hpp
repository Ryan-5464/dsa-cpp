/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

#ifndef TESTARRAYTYPES_HPP
#define TESTARRAYTYPES_HPP

#include "int8_tArray.hpp"

class TestArrayTypes {

    public:
        TestArrayTypes();
        int LengthFunc_ReturnsCorrectLength(
            int (Int8Array::*array)(), Int8Array array, int);
        int testInt8ArraySizeFunc();
        int testInt8ArrayGetFunc();
        int testInt8ArraySetFunc();
        int testInt8ArrayGetFuncWithOutOfRangeIdx();
        int testInt8ArrayConstructArrayWithTooManyElements();
        int testInt8ArrayConstructArrayWithMaxElements();
        // int testInt8ArrayPrintFunc();

};

#endif