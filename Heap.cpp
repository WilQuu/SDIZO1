//
// Created by Grzegorz on 15.03.2020.
//
#include <bits/stdc++.h>
#include "Heap.h"
#include <iostream>

using namespace std;

Heap::Heap(int size) {
    array = new int[size];
    indexOfLastElement = -1;
}

Heap::~Heap() {
    delete[]array;
}

void Heap::push(int value) {
    array[indexOfLastElement + 1] = value;
    indexOfLastElement++;
    int currentIndex = indexOfLastElement;
    int indexOfParent = (indexOfLastElement - 1) / 2;

    while (currentIndex != 0) {
        if (array[currentIndex] > array[indexOfParent]) {
            swap(array[currentIndex], array[indexOfParent]);
        }
        currentIndex = indexOfParent;
        indexOfParent = (indexOfParent - 1) / 2;
    }
}
/* TODO  */
/* ADD REPAIRING OF HEAP TO POP FUNCTION */
void Heap::pop() {
    if (indexOfLastElement == -1) {
        cerr << "Heap is empty,cant remove any element\n";
    } else {
        swap(array[0], array[indexOfLastElement]);
        array[indexOfLastElement] = NULL;
        indexOfLastElement--;
        int level = 0;
        int currentIndex = indexOfLastElement;
        while (currentIndex != 0) {
            currentIndex = (currentIndex - 1) / 2;
            level++;
        }
        for (int i = 0; i < level; i++) {
            if (currentIndex * 2 + 2 <= indexOfLastElement) {
                if (array[currentIndex] < array[currentIndex * 2 + 1] ||
                    array[currentIndex] < array[currentIndex * 2 + 2]) {
                    if (array[currentIndex * 2 + 1] > array[currentIndex * 2 + 2]) {
                        swap(array[currentIndex], array[currentIndex * 2 + 1]);
                        currentIndex = currentIndex * 2 + 1;
                    } else {
                        swap(array[currentIndex], array[currentIndex * 2 + 2]);
                        currentIndex = currentIndex * 2 + 2;
                    }
                }
            } else if (currentIndex * 2 + 1 <= indexOfLastElement) {
                if (array[currentIndex] < array[currentIndex * 2 + 1]) {
                    swap(array[currentIndex], array[currentIndex * 2 + 1]);
                    currentIndex = currentIndex * 2 + 1;
                }
            }
        }
    }
}

void Heap::printHeap() {
    for (int i = 0; i < indexOfLastElement + 1; i++) {
        cout << "[" << i << "] = " << array[i] << endl;
    }
}