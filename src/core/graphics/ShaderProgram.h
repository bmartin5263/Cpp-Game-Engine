//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_SHADERPROGRAM_H
#define CPP_GAME_ENGINE_SHADERPROGRAM_H

class ShaderProgram {
public:
    virtual void init(const char *vShader, const char *fShader) = 0;
    virtual void use() const = 0;
    virtual void setBool(const std::string &name, bool value) const = 0;
    virtual void setInt(const std::string &name, int value) const = 0;
    virtual void setFloat(const std::string &name, float value) const = 0;

    virtual ~ShaderProgram() = default;
};

class NullShaderProgram : ShaderProgram {
    void init(const char *vShader, const char *fShader) override {}
    void use() const override {}
    ~NullShaderProgram() override = default;
};

#endif //CPP_GAME_ENGINE_SHADERPROGRAMGL_H
