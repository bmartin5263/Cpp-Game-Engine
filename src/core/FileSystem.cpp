//
// Created by Brandon on 2/20/22.
//

#include "FileSystem.h"
#include "file/default/DefaultFileSystem.h"

bool FileSystem::startup(const char* assetDirectory) {
    return instance().startup(assetDirectory);
}

void FileSystem::shutdown() {
    instance().shutdown();
}

PlatformFileSystem &FileSystem::instance() {
    static DefaultFileSystem pfs;
    return pfs;
}

std::string FileSystem::loadTextFile(const char *filename) {
    std::string out;
    instance().loadTextFile(filename, out);
    return out;
}

void FileSystem::loadImage(const char* path, Image &image) {
    instance().loadImage(path, image);
}
