//
// Created by grzegorz on 27.04.2020.
//

#ifndef UNTITLED_TIMECOUNTER_H
#define UNTITLED_TIMECOUNTER_H

#include<iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class TimeCounter {
public:
    high_resolution_clock::time_point startTime;
    high_resolution_clock::time_point stopTime;

    void start();

    void stop();

    long countTime();
};


#endif //UNTITLED_TIMECOUNTER_H
