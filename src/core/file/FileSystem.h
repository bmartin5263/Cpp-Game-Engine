//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_FILESYSTEM_H
#define CPP_GAME_ENGINE_FILESYSTEM_H

#include "globals.h"

#include <../platform.h>

#ifdef DoDesktop

#endif

class Image;
class FileSystem {
public:
    FileSystem();
    ~FileSystem();

    void startup(const std::string &assetDirectory);
    void shutdown();

    void loadImageImpl(const std::string& path, Image& image);
    void loadTextFileImpl(const std::string& path, std::string& out);
    const std::string& assetDirectoryImpl() const;

    static void loadImage(const std::string& path, Image& image) { instance().loadImageImpl(path, image); };
    static void loadTextFile(const std::string& path, std::string& out) { instance().loadTextFileImpl(path, out); };
    static const std::string& assetDirectory() { return instance().assetDirectoryImpl(); };

    static FileSystem& instance();

private:
    std::string _assetDirectory;

};

#endif //CPP_GAME_ENGINE_FILESYSTEM_H
