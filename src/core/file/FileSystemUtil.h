//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_FILESYSTEMUTIL_H
#define CPP_GAME_ENGINE_FILESYSTEMUTIL_H

#include "globals.h"
#include "stb_image.h"

struct ImageDeleter {
    void operator()(byte* data) { stbi_image_free(data); }
};

struct Image {
    std::unique_ptr<byte, ImageDeleter> data;
    int width;
    int height;
    int nrChannels;
};

#endif //CPP_GAME_ENGINE_FILESYSTEMUTIL_H
