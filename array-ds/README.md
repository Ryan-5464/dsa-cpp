/* 
    Author: Ryan Tandy
    Created: 30/10/2023
    LastUpdated: 01/11/2023
    License: GNU PL V3.0
*/

### Compile command (linux)
g++ RunTests.cpp Test-Array.hpp Array.hpp -o run-tests.cpp

### Run command (linux)
./run-tests.cpp

### Notes
The code is for a static Array class is defined with the following methods:
Array(), Array(len), ~Array(), length(), size(), print()
getElement(idx), setElement(idx, val).

### Test cases
.length() = success.
.size() = success.
.getElement(min) && .getElement(max) = success.
.getElement(-1) && .getElement(>max) = fail. Throw error.
.seElement(min idx, min val) && .setElement(max idx, max val) = success.
.setElement(-1, min val) && .setElement(>max idx, min val) = fail. Throw error.
Array(MAX_LENGTH) = success.
Arry(>MAX_LENGTH) = fail. Throw error.

### Things to learn about the compiler
error debugging
preprocessor
contextor?
backend
linking