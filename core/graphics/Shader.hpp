//
// Created by Brandon on 2/20/22.
//

#ifndef CPP_GAME_ENGINE_SHADER_HPP
#define CPP_GAME_ENGINE_SHADER_HPP

#include "glm/detail/type_mat.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Engine.h"
#include <fstream>
#include <sstream>
#include <globals.hpp>

#include "platform.h"
#ifdef DoOpenGl
#include "mygl.hpp"
#include "glad/glad.h"
#endif

class Shader {
public:
    void use() const;
    void setBool(const std::string &name, bool value);
    void setInt(const std::string &name, int value);
    void setFloat(const std::string &name, float value);
    void setMatrix4(const std::string &name, const glm::mat4& value);
    void setVector3f(const std::string &name, glm::vec3 value);

    PLATFORM void release();

    ~Shader();

private:
    friend class GraphicsLoader;
#ifdef DoOpenGl
    uint id = 0;
#endif

};

#endif //CPP_GAME_ENGINE_SHADERGL_H
