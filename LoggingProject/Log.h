#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <string>
#include <chrono>
#include <ctime>

namespace Logger {
    enum class LogLevel {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        CRITICAL
    };

    void log(LogLevel logLevel, const std::string& message, std::ostream& outputStream = std::cerr);

    std::string getLevelString(LogLevel logLevel);
    std::string getLevelColor(LogLevel logLevel);
}

#endif // LOG_H
