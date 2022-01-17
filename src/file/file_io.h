#pragma once

#include <optional>

namespace myra {
    std::optional<std::string> readFile(const std::string& filePath);
    bool writeFile(const std::string& filePath, const std::string& contents);
}
