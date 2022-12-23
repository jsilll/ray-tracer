#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

/// @brief The different levels of logging.
enum class LogLevel { kDebug, kInfo, kWarning, kError };

/// @brief Simple logging class.
class Logger final
{
public:
  /**
   * @brief Construct a new Logger object.
   * @param stream The stream to log to.
   */
  [[nodiscard]] explicit Logger(std::ostream &stream) noexcept : _stream(stream) {}

  /**
   * @brief Logs a message to the console.
   * @param level The level of the message.
   * @param message The message to Log.
   */
  void Log(LogLevel level, const std::string &message) const noexcept;

private:
  /// @brief The stream to Log to.
  std::ostream &_stream;
};
