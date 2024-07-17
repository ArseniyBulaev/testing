# Useful

## Configuration and generation
In build
```
cmake .. -DCMAKE_BUILD_TYPE=Debug -G "MinGW Makefiles"
```
## Build
```
cmake --build . 
```
## A quick one-liner to compile and run the tests
```
cmake --build tests; tests/multiCurrencyMoney_tst
```