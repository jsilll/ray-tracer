#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

/// @brief The different levels of logging.
enum class LogLevel { kInfo, kWarning, kError };

/// @brief Simple logging class.
class Logger final
{
public:
  [[nodiscard]] explicit Logger(std::ostream &stream) noexcept : _stream(stream) {}

  /**
   * @brief Logs a message to the console.
   * @param level The level of the message.
   * @param message The message to Log.
   */
  void Log(LogLevel level, const std::string &message) const noexcept;

private:
  /// @brief The stream to log to.
  std::ostream &_stream;
};
