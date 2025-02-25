/**
 * @file Logger.hpp
 * @brief Provides a thread‑safe logging facility for the DSALibraryProject.
 *
 * This header defines the Logger class which implements a singleton logger.
 * The logger outputs messages with timestamps and log levels, ensuring thread-safety
 * using a mutex.
 */

 #ifndef DSA_LOGGER_HPP
 #define DSA_LOGGER_HPP
 
 #include <iostream>
 #include <mutex>
 #include <chrono>
 #include <iomanip>
 #include <sstream>
 #include <string>
 
 namespace dsa {
 
 /**
  * @class Logger
  * @brief Singleton class for thread‑safe logging.
  *
  * The Logger class provides methods to log messages with a timestamp and log level.
  * It is implemented as a singleton to ensure consistent logging throughout the project.
  */
 class Logger {
 public:
     /// Supported log levels.
     enum class LogLevel { INFO, WARNING, ERROR };
 
     /**
      * @brief Returns the global Logger instance.
      * @return Reference to the Logger singleton.
      */
     static Logger& instance() {
         static Logger logger;
         return logger;
     }
 
     /**
      * @brief Logs a message with the given log level.
      *
      * This method is thread‑safe; it locks a mutex to ensure that log messages do not interleave.
      *
      * @param level The log level (INFO, WARNING, ERROR).
      * @param message The message to log.
      */
     void log(LogLevel level, const std::string& message) {
         std::lock_guard<std::mutex> lock(mutex_);
         std::cout << getTimestamp() << " [" << logLevelToString(level) << "] " << message << std::endl;
     }
 
 private:
     Logger() = default;
     std::mutex mutex_;
 
     /**
      * @brief Generates a formatted timestamp string.
      * @return The timestamp in "YYYY-MM-DD HH:MM:SS" format.
      */
     std::string getTimestamp() {
         auto now = std::chrono::system_clock::now();
         auto time_t_now = std::chrono::system_clock::to_time_t(now);
         std::tm tm_now;
 #ifdef _WIN32
         localtime_s(&tm_now, &time_t_now);
 #else
         localtime_r(&time_t_now, &tm_now);
 #endif
         std::stringstream ss;
         ss << std::put_time(&tm_now, "%Y-%m-%d %H:%M:%S");
         return ss.str();
     }
 
     /**
      * @brief Converts a LogLevel enum to a string.
      * @param level The log level.
      * @return A string representation of the log level.
      */
     std::string logLevelToString(LogLevel level) {
         switch (level) {
             case LogLevel::INFO:    return "INFO";
             case LogLevel::WARNING: return "WARNING";
             case LogLevel::ERROR:   return "ERROR";
             default:                return "UNKNOWN";
         }
     }
 };
 
 } // namespace dsa
 
 #endif // DSA_LOGGER_HPP
 