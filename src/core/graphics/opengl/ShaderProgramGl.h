//
// Created by Brandon on 2/14/22.
//

#ifndef CPP_GAME_ENGINE_SHADERPROGRAMGL_H
#define CPP_GAME_ENGINE_SHADERPROGRAMGL_H

#include <memory>
#include "globals.h"
#include "../ShaderProgram.h"

class ShaderProgramGl : public ShaderProgram {
public:
    void init(const char *vShader, const char *fShader) override;
    void release();
    void use() const override;
    void setBool(const std::string &name, bool value) override;
    void setInt(const std::string &name, int value) override;
    void setFloat(const std::string &name, float value) override;
    void setMatrix4(const std::string &name, const glm::mat4& value) override;

    ~ShaderProgramGl() override;

private:
    uint id = 0;

    static void readFiles(const char *vShader, const char *fShader, std::string &vOut, std::string &fOut);
    static uint compile(uint vShader, uint fShader);
};


#endif //CPP_GAME_ENGINE_SHADERPROGRAMGL_H
