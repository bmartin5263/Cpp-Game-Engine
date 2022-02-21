//
// Created by Brandon on 2/20/22.
//

#include "DefaultFileSystem.h"
#include <cstdio>
#include <sstream>
#include <fstream>

bool DefaultFileSystem::startup(const std::string &assetDirectory) {
    this->assetDirectory = assetDirectory;
    return true;
}

void DefaultFileSystem::shutdown() {

}

void DefaultFileSystem::loadTextFile(const char *path, std::string &out) {
    auto finalPath = assetDirectory + path;
    std::ifstream file;
    // ensure ifstream objects can throw exceptions:
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // open file
        file.open(finalPath);
        std::stringstream stream;
        // read file's buffer contents into streams
        stream << file.rdbuf();
        file.close();
        // convert stream into string
        out   = stream.str();
    }
    catch (std::ifstream::failure &e) {
        print("ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ");
        print(finalPath);
        assert(false);
    }
}

void DefaultFileSystem::loadImage(const char* path, Image &image) {
    auto finalPath = assetDirectory + path;
    auto s = finalPath.c_str();
    stbi_set_flip_vertically_on_load(true);
    image.data.reset(stbi_load(s, &image.width, &image.height, &image.nrChannels, 0));
}
