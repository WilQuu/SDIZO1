//
// Created by Grzegorz on 14.03.2020.
//

#ifndef SDIZO1_ARRAY_H
#define SDIZO1_ARRAY_H


class Array {
public:
    int size;
    int *headPointer;

    Array();

    ~Array();

    void addBegining(int value);

    void addEnding(int value);

    int getElement(int index);

    void add(int index, int value);

    void deleteLastElement();

    void deleteFirstElement();

    void deleteElement(int index);

    void printArray();


};


#endif //SDIZO1_ARRAY_H
