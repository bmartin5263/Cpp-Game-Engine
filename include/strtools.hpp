//
// Created by Brandon on 2/21/22.
//

#ifndef CPP_GAME_ENGINE_STRTOOLS_HPP
#define CPP_GAME_ENGINE_STRTOOLS_HPP

#include <string>

bool hasEnding(std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

#endif //CPP_GAME_ENGINE_STRTOOLS_HPP
