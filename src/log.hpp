// TODO:
//   - Allow for toggling different error levels
//   - Output logs to a file
#pragma once

#include <string>

namespace myra {
    enum LogLevel {
        TRACE,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    void log(const std::string &message, LogLevel logLevel, const std::string &end = "\n");

    inline void trace(const std::string &message, const std::string &end = "\n") { log(message, LogLevel::TRACE, end); };
    inline void debug(const std::string &message, const std::string &end = "\n") { log(message, LogLevel::DEBUG, end); };
    inline void info(const std::string &message, const std::string &end = "\n") { log(message, LogLevel::INFO, end); };
    inline void warn(const std::string &message, const std::string &end = "\n") { log(message, LogLevel::WARN, end); };
    inline void error(const std::string &message, const std::string &end = "\n") { log(message, LogLevel::ERROR, end); };
    inline void fatal(const std::string &message, const std::string &end = "\n") { log(message, LogLevel::FATAL, end); };
}
