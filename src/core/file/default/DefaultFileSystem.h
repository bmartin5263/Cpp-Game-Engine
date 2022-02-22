//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_DEFAULTFILESYSTEM_H
#define CPP_GAME_ENGINE_DEFAULTFILESYSTEM_H

#include "../PlatformFileSystem.h"

class DefaultFileSystem : public PlatformFileSystem {
public:
    bool startup(const std::string &assetDirectory) override;
    void shutdown() override;
    void loadTextFile(const std::string& path, std::string &out) override;
    void loadImage(const std::string& path, Image& image) override;

    std::string assetPath() {
        return assetDirectory;
    }

    DefaultFileSystem();
    ~DefaultFileSystem() override;

private:
    std::string assetDirectory;

};


#endif //CPP_GAME_ENGINE_DEFAULTFILESYSTEM_H
