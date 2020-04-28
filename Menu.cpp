//
// Created by grzegorz on 27.04.2020.
//
#include "Heap.h"
#include "Array.h"
#include "TimeCounter.h"
#include "BinarySearchTree.h"
#include "Menu.h"
#include "List.h"
#include <stdlib.h>
#include <time.h>
#include <curses.h>

using namespace std;

void Menu::printMenu() {
    cout << "Witaj\nProgram napisany przez : Grzegorz Kuchta 248861\n";
    cout << "Aby wybrać testowanie tablicy wybierz 1\n";
    cout << "Aby wybrać testowanie listy wybierz 2\n";
    cout << "Aby wybrać testowanie kopca wybierz 3\n";
    cout << "Aby wybrać testowanie zbalansowanego drzewa przeszukiwan binarnych wybierz 4\n";
    cout << "Aby zakonczyć program wybierz 0\n";
    int switcher;
    cin >> switcher;
    while (switcher != 0) {
        cout << "\n\n";
        switch (switcher) {
            default:
                cerr << "Niepoprawna wartość\n";
                break;
            case 1:
                arrayTest();
                break;
            case 2:
                listTest();
                break;
            case 3:
                heapTest();
                break;
            case 4:
                binarySearchTreeTest();
                break;
        }
        cout << "Aby wybrać testowanie tablicy wybierz 1\n";
        cout << "Aby wybrać testowanie listy wybierz 2\n";
        cout << "Aby wybrać testowanie kopca wybierz 3\n";
        cout << "Aby wybrać testowanie zbalansowanego drzewa przeszukiwan binarnych wybierz 4\n";
        cout << "Aby zakonczyć program wybierz 0\n";
        cin >> switcher;
    }
}

void Menu::arrayTest() {
    Array array;
    TimeCounter timeCounter;
    cout << "Podaj rozmiar tablicy początkowej, wypelnionej pseudolosowymi liczbami :";
    int size;
    cin >> size;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        array.addBegining(rand() % 101);
    }
    int switcher = 1;
    while (switcher != 0) {
        cout << "\n\n";
        cout << "Wybierz funkcję tablicy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj tablicę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cin >> switcher;
        int value;
        int index;
        switch (switcher) {
            default:
                cerr << "Niepoprawna liczba !\n";
                break;
            case 1:
                cout << "Podaj wartość :";
                cin >> value;
                timeCounter.start();
                array.addBegining(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 2:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                array.addEnding(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 3:
                cout << "Podaj wartosc :";
                cin >> value;
                cout << "Podaj indeks :";
                cin >> index;
                timeCounter.start();
                array.add(index, value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 4:
                timeCounter.start();
                array.deleteFirstElement();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 5:
                timeCounter.start();
                array.deleteLastElement();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 6:
                cout << "Podaj indeks :";
                cin >> index;
                timeCounter.start();
                array.deleteElement(index);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 7:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                array.find(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 8:
                array.printArray();
                break;
            case 0:
                break;
        }
    }
}

void Menu::listTest() {
    TimeCounter timeCounter;
    List list;
    int size, value, index;
    cout << "Podaj rozmiar listy poczatkowej, wypelnionej pseudolosowymi liczbami :";
    cin >> size;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        list.addBeginning(rand() & 101);
    }
    cout << "Wybierz funkcję listy:" << endl;
    cout << "    1. Dodaj na początek" << endl;
    cout << "    2. Dodaj na koniec" << endl;
    cout << "    3. Dodaj gdziekolwiek" << endl;
    cout << "    4. Usuń pierwszy" << endl;
    cout << "    5. Usuń ostatni" << endl;
    cout << "    6. Usuń którykolwiek" << endl;
    cout << "    7. Wyszukaj element" << endl;
    cout << "    8. Wydrukuj listę" << endl;
    cout << "    0. Wyjście" << endl << endl;
    int switcher = 1;
    cin >> switcher;
    while (switcher != 0) {
        switch (switcher) {
            default:
                cerr << "Niepoprawna liczba\n";
                break;
            case 1:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                list.addBeginning(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 2:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                list.addEnding(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 3:
                cout << "Podaj wartosc :";
                cin >> value;
                cout << "Podaj indeks :";
                cin >> index;
                timeCounter.start();
                list.add(index, value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 4:
                timeCounter.start();
                list.deleteFirst();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 5:
                timeCounter.start();
                list.deleteLast();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 6:
                cout << "Podaj indeks :";
                cin >> index;
                timeCounter.start();
                list.deleteElement(index);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 7:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                list.find(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 8:
                list.printList();
                break;
            case 0:
                break;
        }
        cout << "Wybierz funkcję listy:" << endl;
        cout << "    1. Dodaj na początek" << endl;
        cout << "    2. Dodaj na koniec" << endl;
        cout << "    3. Dodaj gdziekolwiek" << endl;
        cout << "    4. Usuń pierwszy" << endl;
        cout << "    5. Usuń ostatni" << endl;
        cout << "    6. Usuń którykolwiek" << endl;
        cout << "    7. Wyszukaj element" << endl;
        cout << "    8. Wydrukuj listę" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cin >> switcher;
    }

}

void Menu::heapTest() {
    Heap heap(100000);
    TimeCounter timeCounter;
    cout << "Podaj rozmiar poczatkowy kopca, wypelnioniony pseudolosowymi liczbami ";
    int size, value;
    cin >> size;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        heap.push(rand() % 101);
    }
    int switcher = 1;
    while (switcher != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj" << endl;
        cout << "    2. Usuń" << endl;
        cout << "    3. Wydrukuj kopiec" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cin >> switcher;
        switch (switcher) {
            default:
                cerr << "Niepoprawna liczba !\n";
                break;
            case 1:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                heap.push(value);
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 2:
                timeCounter.start();
                heap.pop();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 3:
                heap.printHeap();
                break;
            case 0:
                break;

        }
    }
}

void Menu::binarySearchTreeTest() {
    TimeCounter timeCounter;
    BinarySearchTree binarySearchTree;
    cout << "Podaj rozmiar poczatkowy bst, wypelnioniony pseudolosowymi liczbami ";
    int size, value;
    cin >> size;
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        binarySearchTree.addKey(rand() % 101);
    }
    int switcher = 1;
    while (switcher != 0) {
        cout << "Wybierz funkcję Kopca:" << endl;
        cout << "    1. Dodaj element" << endl;
        cout << "    2. Usuń element" << endl;
        cout << "    3. Wydrukuj drzewo" << endl;
        cout << "    4. Balansuj drzewo algorytmem DSW" << endl;
        cout << "    0. Wyjście" << endl << endl;
        cin >> switcher;
        switch (switcher) {
            default:
                cerr << "Niepoprawna liczba !\n";
                break;
            case 1:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                binarySearchTree.addKey(value);
                binarySearchTree.balanceTree();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 2:
                cout << "Podaj wartosc :";
                cin >> value;
                timeCounter.start();
                binarySearchTree.removeKey(value);
                binarySearchTree.balanceTree();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 3:
                binarySearchTree.print2D(binarySearchTree.root);
                break;
            case 4:
                timeCounter.start();
                binarySearchTree.balanceTree();
                timeCounter.stop();
                cout << "Czas wykonania operacji :" << timeCounter.countTime() << " [ms]\n";
                break;
            case 0:
                break;
        }
    }
}