#include "shader.hpp"

#include <glad/glad.h>

#include "../log.hpp"
#include "../file/parse/shader.hpp"

namespace myra {
// public:
    Shader::Shader(const std::string &filePath) {
        myra::ShaderSource source = myra::loadMultiShader(filePath);

        m_programId = glCreateProgram();
        unsigned int vertexId, geometryId, fragmentId;
        if (source.vertex) {
            vertexId = compileShader(source.vertex->c_str(), GL_VERTEX_SHADER);
            glAttachShader(m_programId, vertexId);
        }
        if (source.geometry) {
            geometryId = compileShader(source.geometry->c_str(), GL_GEOMETRY_SHADER);
            glAttachShader(m_programId, geometryId);
        }
        if (source.fragment) {
            fragmentId = compileShader(source.fragment->c_str(), GL_FRAGMENT_SHADER);
            glAttachShader(m_programId, fragmentId);
        }
        glLinkProgram(m_programId);

        int success;
        glGetProgramiv(m_programId, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(m_programId, 512, NULL, infoLog);
            myra::error("Program Linking Failed. Info log:");
            myra::error(infoLog);
        }
        glDeleteShader(vertexId);
        glDeleteShader(geometryId);
        glDeleteShader(fragmentId);
    }

    void Shader::use() {
        glUseProgram(m_programId);
    }
// private:
    unsigned int Shader::compileShader(const char* source, GLenum shaderType) {
        unsigned int shaderId = glCreateShader(shaderType);
        glShaderSource(shaderId, 1, &source, NULL);
        glCompileShader(shaderId);

        int success;
        glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shaderId, 512, NULL, infoLog);
            myra::error("Shader Compilation Failed. Info log:");
            myra::error(infoLog);
        }
        return shaderId;
    }
}
