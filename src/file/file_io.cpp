#include <iostream>
#include <fstream>
#include <optional>
#include "file_io.h"

namespace myra {
    std::optional<std::string> readFile(const std::string& filePath) {
        std::ifstream ifs(filePath);

        if (!ifs.is_open()) { return {}; }

        return std::string(
                (std::istreambuf_iterator<char>(ifs)),
                (std::istreambuf_iterator<char>())
        );
    }

    bool writeFile(const std::string& filePath, const std::string& contents) {
        std::fstream file;
        file.open(filePath, std::ios::out);

        if (!file.is_open()) { return false; }

        file << contents;
        file.close();
        return true;
    }
}
