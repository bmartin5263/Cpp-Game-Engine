//
// Created by Brandon on 2/22/22.
//

#include "FileSystem.h"
#include "Engine.h"

const std::string &FileSystem::assetDirectoryImpl() const {
    return _assetDirectory;
}

FileSystem &FileSystem::instance() {
    return Engine::fileSystem();
}
