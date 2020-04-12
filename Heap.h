//
// Created by Grzegorz on 15.03.2020.
//

#ifndef SDIZO1_HEAP_H
#define SDIZO1_HEAP_H


class Heap {
private:

    int *array;
    int indexOfLastElement;

public:
    Heap(int size);

    ~Heap();

    void push(int value);

    void pop();

    void printHeap();

};


#endif //SDIZO1_HEAP_H
