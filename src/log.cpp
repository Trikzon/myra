#include "log.hpp"

#include <string>
#include <iostream>

namespace myra {
    const std::string logLevelToEN_US[6] = {
            "TRACE",
            "DEBUG",
            "INFO",
            "WARN",
            "ERROR",
            "FATAL"
    };

    void log(const std::string &message, LogLevel logLevel, const std::string &end) {
        std::cout << "[" << logLevelToEN_US[logLevel] << "] " << message << end << std::flush;
    }
}
