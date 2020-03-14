#include <iostream>
#include "Array.cpp"

int main() {
    Array array;
    for (int i = 0; i < 10; i++) {
        array.addEnding(i);
    }
    array.printArray();
    return 0;
}