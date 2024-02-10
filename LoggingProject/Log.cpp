#include "Log.h"

namespace Logger {
    void log(LogLevel logLevel, const std::string& message, std::ostream& outputStream) {
        auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm tm;
        if (localtime_s(&tm, &now) != 0) {
            // Handle error, e.g., unable to convert time
            outputStream << "Error: Unable to get local time." << std::endl;
            return;
        }

        char timestamp[20]; // Enough to hold the timestamp
        std::strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", &tm);

        outputStream << getLevelColor(logLevel);
        outputStream << getLevelString(logLevel) << " [" << timestamp << "] " << message << "\033[0m" << std::endl; // Reset color after message
    }

    std::string getLevelString(LogLevel logLevel) {
        switch (logLevel) {
            case LogLevel::DEBUG:
                return "[DEBUG]";
            case LogLevel::INFO:
                return "[INFO]";
            case LogLevel::WARNING:
                return "[WARNING]";
            case LogLevel::ERROR:
                return "[ERROR]";
            case LogLevel::CRITICAL:
                return "[CRITICAL]";
            default:
                return "[UNKNOWN]";
        }
    }

    std::string getLevelColor(LogLevel logLevel) {
        switch (logLevel) {
        case LogLevel::DEBUG:
            return "\033[34m"; // Blue
        case LogLevel::INFO:
            return "\033[32m"; // Green
        case LogLevel::WARNING:
            return "\033[33m"; // Yellow
        case LogLevel::ERROR:
            return "\033[31m";
        case LogLevel::CRITICAL:
            return "\033[35m"; // Red for both ERROR and CRITICAL
        default:
            return ""; // No color
        }
    }
}
