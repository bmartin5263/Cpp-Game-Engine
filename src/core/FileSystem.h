//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_FILESYSTEM_H
#define CPP_GAME_ENGINE_FILESYSTEM_H

#include "file/PlatformFileSystem.h"
#include "globals.h"

class FileSystem {
public:

    static bool startup(const char* assetDirectory);
    static void shutdown();

    static void loadImage(const char* path, Image& image);
    static std::string loadTextFile(const char* filename);

private:
    FileSystem() = default;

    static inline PlatformFileSystem& instance();
};

#endif //CPP_GAME_ENGINE_FILESYSTEM_H
