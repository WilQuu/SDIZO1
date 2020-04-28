//
// Created by Grzegorz on 15.03.2020.
//
#include <iostream>
#include "List.h"

using namespace std;

List::List() {
    size = 0;
    firstElement = NULL;
    element = NULL;
    lastElement = NULL;
}

List::~List() {
    element = firstElement;
    for (int i = 0; i < size; i++) {
        element = NULL;
        element = element->next;
    }
}

void List::addBeginning(int value) {
    if (firstElement == NULL) {
        firstElement = new listElement(value, NULL, NULL);
        lastElement = firstElement;
    } else {
        element = firstElement;
        firstElement = new listElement(value, element, NULL);
        element->prev = firstElement;
    }
    size++;
}

void List::addEnding(int value) {
    if (firstElement == NULL) {
        firstElement = new listElement(value, NULL, NULL);
        lastElement = firstElement;
    } else {
        element = lastElement;
        lastElement = new listElement(value, NULL, element);
        element->next = lastElement;
    }
    size++;
}

void List::add(int index, int value) {
    if (index < 0 || index > size) {
        cerr << "Index out of bounds\n";
    } else if (index == 0) {
        addBeginning(value);
    } else if (index == size) {
        addEnding(value);
    } else {
        element = firstElement;
        for (int i = 0; i < index; i++) {
            element = element->next;
        }
        listElement *newElement = new listElement(value, element, element->prev);
        element->prev = newElement;
        newElement->prev->next = newElement;
        size++;
    }
}


void List::deleteLast() {
    if (firstElement == NULL) {
        cerr << "List is empty, cant remove any element!\n";
    } else {
        lastElement->prev->next = NULL;
        size--;
    }
}

void List::deleteFirst() {
    if (firstElement == NULL) {
        cerr << "List is empty, cant remove any element!\n";
    } else {
        firstElement = firstElement->next;
        firstElement->prev = NULL;
        size--;
    }
}

void List::deleteElement(int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of bounds\n";
    } else if (index == 0) {
        deleteFirst();
    } else if (index == size - 1) {
        deleteLast();
    } else {
        element = firstElement;
        for (int i = 0; i < index; i++) {
            element = element->next;
        }
        element->prev->next = element->next;
        element->next->prev = element->prev;
        size--;
    }
}

void List::find(int value) {
    element = firstElement;
    for (int i = 0; i < size; i++) {
        if (element->value == value) {
            cout << "Element znajduje sie na pozycji :" << i << endl;
            return;
        }
        element=element->next;
    }
    cout << "Nie ma takiej wartosci w liscie !\n";
}

void List::printList() {
    element = firstElement;
    for (int i = 0; i < size; i++) {
        cout << element->value << " ";
        element = element->next;
    }
    cout << endl;
    element = lastElement;
    for (int i = 0; i < size; i++) {
        cout << element->value << " ";
        element = element->prev;
    }
    cout << endl;
}
