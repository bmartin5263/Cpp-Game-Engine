//
// Created by Brandon Martin on 12/26/18.
//

#include "StopWatch.h"

void StopWatch::tick() {
    start = std::chrono::high_resolution_clock::now();
}

void StopWatch::tock() {
    end = std::chrono::high_resolution_clock::now();
}
