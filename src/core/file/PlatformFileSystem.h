//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_PLATFORMFILESYSTEM_H
#define CPP_GAME_ENGINE_PLATFORMFILESYSTEM_H

#include "globals.h"

class Image;
class PlatformFileSystem {
public:
    virtual bool startup(const std::string &assetDirectory) = 0;
    virtual void shutdown() = 0;
    virtual void loadImage(const std::string& path, Image& image) = 0;
    virtual void loadTextFile(const std::string& path, std::string& out) = 0;
    virtual ~PlatformFileSystem() = default;

};

#endif //CPP_GAME_ENGINE_PLATFORMFILESYSTEM_H
