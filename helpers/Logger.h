#ifndef CROGUELITE_LOGGER_H
#define CROGUELITE_LOGGER_H

#include <fstream>
#include <string>
#include <ctime>

enum class LogLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
};

class Logger {
private:
    std::ofstream logFile;
    LogLevel minLevel;

    static std::string levelToString(const LogLevel level) {
        switch (level) {
            case LogLevel::DEBUG:   return "DEBUG";
            case LogLevel::INFO:    return "INFO";
            case LogLevel::WARNING: return "WARNING";
            case LogLevel::ERROR:   return "ERROR";
            case LogLevel::FATAL:   return "FATAL";
            default:                return "UNKNOWN";
        }
    }

    static std::string getTimestamp() {
        const std::time_t now = std::time(nullptr);
        char buf[20];
        std::strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
        return buf;
    }

    // Private constructor for Singleton pattern
    Logger() : minLevel(LogLevel::INFO) {
        logFile.open("game.log", std::ios::app); // Appends to the file
    }

public:
    // Destructor
    ~Logger() {
        if (logFile.is_open()) {
            logFile.close();
        }
    }

    // Get instance of the logger
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // Set the minimum verbosity level
    void setLogLevel(const LogLevel level) {
        minLevel = level;
    }

    // Core log method
    void log(const LogLevel level, const std::string& message) {
        if (level < minLevel) { return; }

        if (logFile.is_open()) {
            logFile << "[" << getTimestamp() << "] ["
                    << levelToString(level) << "] "
                    << message << std::endl; // Flushes instantly
        }
    }
};

// Convenient macros for easy use across game files
#define LOG_DEBUG(msg)   Logger::getInstance().log(LogLevel::DEBUG, msg)
#define LOG_INFO(msg)    Logger::getInstance().log(LogLevel::INFO, msg)
#define LOG_WARN(msg)    Logger::getInstance().log(LogLevel::WARNING, msg)
#define LOG_ERROR(msg)   Logger::getInstance().log(LogLevel::ERROR, msg)
#define LOG_FATAL(msg)   Logger::getInstance().log(LogLevel::FATAL, msg)


#endif //CROGUELITE_LOGGER_H
