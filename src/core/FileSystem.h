//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_FILESYSTEM_H
#define CPP_GAME_ENGINE_FILESYSTEM_H

#include <string>

class Image;
class PlatformFileSystem;
class FileSystem {
public:
    static void loadImage(const std::string& path, Image& image);
    static std::string loadTextFile(const std::string& filename);

private:
    static PlatformFileSystem& instance();

};

#endif //CPP_GAME_ENGINE_FILESYSTEM_H
