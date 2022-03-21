//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_FILE_UTILS_HPP
#define CPP_GAME_ENGINE_FILE_UTILS_HPP

#include "globals.hpp"

struct ImageDeleter {
    void operator()(byte* data);
};

struct Image {
    std::unique_ptr<byte, ImageDeleter> data;
    int width;
    int height;
    int nrChannels;

    void load(const char *path);
};

#endif //CPP_GAME_ENGINE_FILE_UTILS_HPP
