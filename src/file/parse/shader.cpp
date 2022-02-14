#include "shader.hpp"

#include <string>
#include <vector>

#include "../file_io.hpp"
#include "parse_util.hpp"

namespace myra {
    ShaderSource loadMultiShader(const std::string& filePath) {
        ShaderSource result;
        auto fileContent = myra::readFile(filePath);
        if (!fileContent) { return result; }

        std::vector<std::string> splits = myra::splitString(*fileContent, "#type ");
        for (std::string split : splits) {
            int endOfFirstLine = split.find('\n');
            std::string type = split.substr(0, endOfFirstLine);
            std::string source = split.substr(endOfFirstLine + 1);

            if (type == "vertex") {
                result.vertex = source;
            } else if (type == "geometry") {
                result.geometry = source;
            } else if (type == "fragment") {
                result.fragment = source;
            }
        }
        return result;
    }
}
