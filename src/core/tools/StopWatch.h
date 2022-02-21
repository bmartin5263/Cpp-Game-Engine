//
// Created by Brandon Martin on 12/26/18.
//

#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <chrono>

using namespace std::chrono;
class StopWatch {
public:
    void tick();
    void tock();

    template<class TimeUnit>
    long long int time() {
        return std::chrono::duration_cast<TimeUnit>(end - start).count();
    }

private:
    time_point<high_resolution_clock> start;
    time_point<high_resolution_clock> end;

};

#endif //STOPWATCH_H
