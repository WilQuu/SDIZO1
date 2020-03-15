//
// Created by Grzegorz on 15.03.2020.
//

#ifndef SDIZO1_LIST_H
#define SDIZO1_LIST_H

class List {
private:
    int* previous;
    int*next;
    int* values;
    int size;
public:
    void addBegining(int value);
    void addEnding(int value);
    void add(int index,int value);
    void deleteFirst();
    void deleteLast();
    void deleteElement(int index);
    void printList();
    List();
    ~List();
};


#endif //SDIZO1_LIST_H
