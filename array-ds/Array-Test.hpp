/* 
    Author: Ryan Tandy
    Created: 31/10/2023
    LastUpdated: 31/10/2023
    License: GNU PL V3.0
*/

#ifndef ARRAY_TEST_HPP
#define ARRAY_TEST_HPP

#include <iostream>

class ArrayTest {
    public:
        ArrayTest() {};
        template <typename T>
        bool testArray_length_returnsCorrectLength(
                T *array, 
                int expLen 
            ) {
                if (array->length() == expLen) {
                    return true;
                }
                std::cout << "Length = " << array->length() << std::endl;
                std::cout << "Expected length = " << expLen << std::endl;
                return false;
        };
        bool testArray_size_returnsCorrectSize();
        bool testArray_constructor_createsObject();
        bool testArray_constructor_throwsErrorIfArrayLengthToLarge();
        bool testArray_get_returnsCorrectElement();
        bool testArray_get_throwsErrorIfIndexOutOfRange();
        bool testArray_set_setsElementCorrectly();
        bool testArray_set_throwsErrorIfIndexOutOfRange();
};

#endif

/*
    Test cases:
        test length
        test size for each type
        test set element for each type
        test get element for each type
        test constructor
*/