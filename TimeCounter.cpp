//
// Created by grzegorz on 27.04.2020.
//

#include "TimeCounter.h"

void TimeCounter::start() {
    startTime = high_resolution_clock::now();
}

void TimeCounter::stop() {
    stopTime = high_resolution_clock::now();
}

long TimeCounter::countTime() {
    return duration_cast<nanoseconds>(TimeCounter::startTime - TimeCounter::stopTime).count();
}