/* 
    Author: Ryan Tandy
    Date: 30/10/2023
    License: GNU PL V3.0
*/

### Compile command
g++ runTests.cpp testArrayTypes.cpp int8_tArray.cpp

### Test cases
.length() = length of array.
.size() = size of array.
.get(min) -> .get(max) = success.
.get(-1) && .get(>max) = fail. Throw error.
.set(min idx, min val) -> .set(max idx, max val) = success.
.set(-1, min val) && .set(>max idx, min val) = fail. Throw error.
.set(min idx, < min val) && .set( min idx, >max val) = fail. Throw error.
Array(MAX_LENGTH) = success.
Arry(>MAX_LENGTH) = fail. Throw error.

### Things to learn about the compiler
error debugging
preprocessor
contextor?
backend
linking