//
// Created by Grzegorz on 14.03.2020.
//

#include "Array.h"
#include<iostream>

using namespace std;

Array::Array() {
    headPointer = NULL;
    size = 0;
}

Array::~Array() {
    if (headPointer != NULL) {
        delete[] headPointer;
    }
}

void Array::addBegining(int value) {
    int *tempHeadPointer = new int[size + 1];
    tempHeadPointer[0] = value;

    for (int i = 0; i < size; i++) {
        tempHeadPointer[i + 1] = headPointer[i];
    }

    size++;
    delete headPointer;
    headPointer = tempHeadPointer;
}
/* return index of element with expected value */
int Array::getElement(int value) {
    for(int i=0;i<size;i++){
        if(headPointer[i]==value)
            return i;
    }
    /* value of -1 means there is no value that was set as a parameter of function*/
    return -1;
}

void Array::addEnding(int value) {
    int *tempHeadPointer = new int[size + 1];
    tempHeadPointer[size] = value;
    for (int i = 0; i < size; i++) {
        tempHeadPointer[i] = headPointer[i];
    }
    size++;
    delete[] headPointer;
    headPointer = tempHeadPointer;
}

void Array::add(int index, int value) {
    if (index >= size || index < 0) {
        cerr << "INDEX OUT OF BOUNDS\n";
    } else {
        int *tempHeadPointer = new int[size + 1];
        for (int i = 0; i < index; i++) {
            tempHeadPointer[i] = headPointer[i];
        }
        tempHeadPointer[index] = value;

        for (int i = index + 1; i <= size; i++) {
            tempHeadPointer[i] = headPointer[i-1];
        }
        size++;
        delete[]headPointer;
        headPointer = tempHeadPointer;
    }
}

void Array::deleteLastElement() {
    if (size > 0) {
        int *tempHeadPointer = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            tempHeadPointer[i] = headPointer[i];
        }
        delete[]headPointer;
        headPointer = tempHeadPointer;
        size--;
    } else
        cerr << "Array is empty, cant delete any value\n";
}

void Array::deleteFirstElement() {
    if (size > 0) {
        int *tempHeadPointer = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            tempHeadPointer[i] = headPointer[i + 1];
        }
        size--;
        delete[]headPointer;
        headPointer = tempHeadPointer;
    } else {
        cerr << "Array is empty, cant delete any value\n";
    }
}

void Array::deleteElement(int index) {
    if (index < size && index >= 0) {
        int *tempHeadPointer = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            if (i < index) {
                tempHeadPointer[i] = headPointer[i];
            } else if (i >= index) {
                tempHeadPointer[i] = headPointer[i + 1];
            }
        }
        delete[]headPointer;
        headPointer = tempHeadPointer;
        size--;
    } else {
        cerr << "Array is empty or wrong index value\n";
    }
}

void Array::printArray() {
    if (size == 0) {
        cerr << "Array is empty\n";
    } else {
        for (int i = 0; i < size; i++) {
            cout << "[" << i << "]" << "=" << headPointer[i] << endl;
        }
        cout << endl;
    }
}



