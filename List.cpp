//
// Created by Grzegorz on 15.03.2020.
//
#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    size = 0;
    next = NULL;
    previous = NULL;
    values = NULL;
}

List::~List() {
    values = NULL;
    next = NULL;
    previous = NULL;
}

void List::addBegining(int value) {
    if (size == 0) {
        next = new int[size + 1];
        previous = new int[size + 1];
        values = new int[size + 1];
        next[0] = NULL;
        previous[0] = NULL;
        values[0] = value;

    } else {
        int *tempNext = new int[size + 1];
        int *tempPrevious = new int[size + 1];
        int *tempValues = new int[size + 1];
        tempValues[0] = value;
        tempPrevious[0] = NULL;
        tempNext[0] = values[1];
        for (int i = 1; i <= size; i++) {
            if (i != size) {
                tempNext[i] = values[i + 1];
            } else {
                tempNext[i] = NULL;
            }
            tempValues[i] = values[i - 1];
            if (i == 1) {
                tempPrevious[i] = value;
            } else {
                tempPrevious[i] = values[i - 1];
            }
        }
        delete[]values;
        delete[]next;
        delete[]previous;
        values = tempValues;
        next = tempNext;
        previous = tempPrevious;
    }
    size++;
}

void List::addEnding(int value) {
    if (size == 0) {
        next = new int[size + 1];
        previous = new int[size + 1];
        values = new int[size + 1];
        next[0] = NULL;
        previous[0] = NULL;
        values[0] = value;
        size++;

    } else {
        int *tempNext = new int[size + 1];
        int *tempValues = new int[size + 1];
        int *tempPrevious = new int[size + 1];
        size++;
        for (int i = 0; i < size - 1; i++) {
            tempNext[i] = values[i + 1];
            tempPrevious[i] = values[i - 1];
            tempValues[i] = values[i];
        }
        tempNext[size - 1] = NULL;
        tempPrevious[size - 1] = values[size - 1];
        tempValues[size - 1] = value;
        tempNext[size - 2] = values[size - 1];
        delete[]next;
        delete[]previous;
        delete[]values;
        values = tempValues;
        next = tempNext;
        previous = tempPrevious;
    }
}

void List::add(int index, int value) {
    if (0 <= index && index <= size) {
        int *tempNext = new int[size + 1];
        int *tempValues = new int[size + 1];
        int *tempPrevious = new int[size + 1];
        for (int i = 0; i < size + 1; i++) {
            if (i < index) {
                tempNext[i] = next[i];
                tempPrevious[i] = previous[i];
                tempValues[i] = values[i];
            } else if (i == index) {
                tempValues[i] = value;
                tempPrevious[i] = values[i - 1];
                tempNext[i] = values[i];
            } else if (index < i < size) {
                tempValues[i] = values[i - 1];
                tempPrevious[i] = tempValues[i - 1];
                tempNext[i] = values[i];
            } else if (i == size) {
                tempValues[i] = values[i - 1];
                tempPrevious[i] = tempValues[i - 1];
                tempNext[i] = NULL;
            }
        }
        size++;
        delete[]values;
        delete[]next;
        delete[]previous;
        values = tempValues;
        next = tempNext;
        previous = tempPrevious;
    } else {
        cerr << "WRONG INDEX VALUE\n";
    }
}

void List::deleteLast() {
    if (size == 0) {
        cerr << "List is empty, cant remove any element\n";
    } else {
        int *tempNext = new int[size - 1];
        int *tempValues = new int[size - 1];
        int *tempPrevious = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            if (i != size - 2) {
                tempNext[i] = next[i];
                tempPrevious[i] = previous[i];
                tempValues[i] = values[i];
            } else {
                tempNext[i] = NULL;
                tempPrevious[i] = previous[i];
                tempValues[i] = values[i];
            }
        }
        size--;
        delete[]values;
        delete[]next;
        delete[]previous;
        values = tempValues;
        next = tempNext;
        previous = tempPrevious;
    }
}

void List::deleteFirst() {
    if (size == 0) {
        cerr << "List is empty, cant remove any element\n";
    } else {
        int *tempNext = new int[size - 1];
        int *tempValues = new int[size - 1];
        int *tempPrevious = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            if (i == 0) {
                tempValues[i] = values[i + 1];
                tempNext[i] = next[i + 1];
                tempPrevious[i] = NULL;
            } else {
                tempValues[i] = values[i + 1];
                tempNext[i] = next[i + 1];
                tempPrevious[i] = previous[i + 1];
            }
        }
        size--;
        delete[]values;
        delete[]next;
        delete[]previous;
        values = tempValues;
        next = tempNext;
        previous = tempPrevious;
    }
}

void List::deleteElement(int index) {
    if (index < 0 || index >= size) {
        cerr << "Wrong index value\n";
    } else {
        int *tempNext = new int[size - 1];
        int *tempValues = new int[size - 1];
        int *tempPrevious = new int[size - 1];
        for (int i = 0; i < size - 1; i++) {
            if (i < index) {
                tempNext[i] = next[i];
                tempPrevious[i] = previous[i];
                tempValues[i] = values[i];
            } else {
                tempValues[i] = values[i + 1];
                tempPrevious[i] = previous[i + 1];
                tempNext[i] = next[i + 1];
            }
        }
        size--;
        delete[]values;
        delete[]next;
        delete[]previous;
        values = tempValues;
        next = tempNext;
        previous = tempPrevious;
    }
}

void List::printList() {
    for (int i = 0; i < size; i++) {
        cout << "[" << i << "]" << "=" << values[i] << endl;
    }
}