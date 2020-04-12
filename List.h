//
// Created by Grzegorz on 15.03.2020.
//

#ifndef SDIZO1_LIST_H
#define SDIZO1_LIST_H

struct listElement {
    int value;
    listElement *next;
    listElement *prev;

    listElement(int value, listElement *next, listElement *prev) {
        this->value = value;
        this->next = next;
        this->prev = prev;
    }

};

class List {
private:
    listElement *firstElement;
    listElement *element;
    listElement *lastElement;
    int size;
public:
    void addBeginning(int value);

    void addEnding(int value);

    void add(int index, int value);

    void deleteFirst();

    void deleteLast();

    void deleteElement(int index);

    void printList();

    List();

    ~List();
};


#endif //SDIZO1_LIST_H
