//
// Created by Brandon on 2/9/22.
//

#ifndef CPP_GAME_ENGINE_GLOBALS
#define CPP_GAME_ENGINE_GLOBALS

#include <cassert>
#include <iostream>
#define UNUSED(x) (void)x;

typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned char byte;

//void print(const std::string& msg) {
//    std::cout << msg << '\n';
//}

template <class T>
auto& print(const T& msg) {
    std::cout << msg << '\n';
    return std::cout;
}

#endif //CPP_GAME_ENGINE_GLOBALS
