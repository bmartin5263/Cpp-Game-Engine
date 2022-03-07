//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_FILESYSTEM_H
#define CPP_GAME_ENGINE_FILESYSTEM_H

#include "globals.hpp"

#include "platform.h"

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

    static void loadImage(const std::string& path, Image& outImage) { instance().loadImageImpl(path, outImage); };
    static void loadTextFile(const std::string& path, std::string& outText) { instance().loadTextFileImpl(path, outText); };
    static const std::string& assetDirectory() { return instance().assetDirectoryImpl(); };

    static FileSystem& instance();

private:
    std::string _assetDirectory;

};

#endif //CPP_GAME_ENGINE_FILESYSTEM_H
