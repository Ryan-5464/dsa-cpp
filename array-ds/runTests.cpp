/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

#include <iostream>
#include "testArrayTypes.hpp"

int main() {
    TestArrayTypes test;
    int result;
    result = test.LengthFunc_ReturnsCorrectLength();
    result = test.testInt8ArraySizeFunc();
    result = test.testInt8ArrayGetFunc();
    result = test.testInt8ArraySetFunc();
    result = test.testInt8ArrayGetFuncWithOutOfRangeIdx();
    result = test.testInt8ArrayConstructArrayWithTooManyElements();
    result = test.testInt8ArrayConstructArrayWithMaxElements();
    return 0;
}