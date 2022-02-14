#include "parse_util.hpp"

#include <string>
#include <vector>

namespace myra {
    std::vector<std::string> splitString(const std::string& str, const std::string& delimiter) {
        std::vector<std::string> result;

        int delimiterIndex = 0;
        std::string currentSplit = "";

        for (int i = 0; i < str.length(); i++) {
            if (str[i] == delimiter[delimiterIndex]) {
                delimiterIndex++;
            } else {
                delimiterIndex = 0;
            }
            currentSplit += str[i];

            if (delimiterIndex == delimiter.length() || i == str.length() - 1) {
                currentSplit = currentSplit.substr(0, currentSplit.length() - delimiterIndex);
                if (!currentSplit.empty()) {
                    result.push_back(currentSplit);
                }
                currentSplit = "";
                delimiterIndex = 0;
            }
        }
        return result;
    }
}
