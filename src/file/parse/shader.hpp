#pragma once

#include <optional>
#include <string>

namespace myra {
    struct ShaderSource {
        std::optional<std::string> vertex = {};
        std::optional<std::string> geometry = {};
        std::optional<std::string> fragment = {};
    };

    ShaderSource loadMultiShader(const std::string &filePath);
}


