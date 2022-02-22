//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_SHADERPROGRAM_H
#define CPP_GAME_ENGINE_SHADERPROGRAM_H

#include "glm/detail/type_mat.hpp"

class ShaderProgram {
public:
    virtual void init(const char *vShader, const char *fShader) = 0;
    virtual void use() const = 0;
    virtual void setBool(const std::string &name, bool value) = 0;
    virtual void setInt(const std::string &name, int value) = 0;
    virtual void setFloat(const std::string &name, float value) = 0;
    virtual void setMatrix4(const std::string &name, const glm::mat4& value) = 0;

    virtual ~ShaderProgram() = default;
};

class NullShaderProgram : ShaderProgram {
    void init(const char *vShader, const char *fShader) override {}
    void use() const override {}
    ~NullShaderProgram() override = default;
};

#endif //CPP_GAME_ENGINE_SHADERPROGRAMGL_H
