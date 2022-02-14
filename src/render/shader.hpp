#pragma once

#include <glad/glad.h>
#include <string>

namespace myra {
    class Shader {
    private:
        unsigned int m_programId;
    public:
        Shader(const std::string& filePath);
        void use();
    private:
        unsigned int compileShader(const char* source, GLenum shaderType);
    public:
    };
}
