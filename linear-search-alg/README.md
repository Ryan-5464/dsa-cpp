/* 
    Author: Ryan Tandy
    Created: 01/10/2023
    LastUpdated: 01/11/2023
    License: GNU PL V3.0
*/

### Compile command (linux)
g++ LinearSearchTestCases.cpp LinearSearchTest.cpp ../array-ds/Array.hpp LinearSearch.cpp -o run-tests.cpp

### Run command (linux)
./run-tests.cpp

### Notes
The code is for a linear search algorithm for the array class

### Test cases
LinearSearch() -> idx, success when value exists in array
LinearSearch() -> throwError when value not exist in array.