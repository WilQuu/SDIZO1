#include <iostream>
#include "Array.cpp"
#include "List.h"
#include "Heap.h"
#include <stdlib.h>
#include <time.h>

int main() {
    Heap heap(20);
    for (int i = 0; i < 15; i++) {
        //int randomInt = rand() % 30 + 1;
        heap.push(i);
    }
    heap.printHeap();
    cout << endl;
    heap.pop();
    heap.printHeap();
    return 0;
}
