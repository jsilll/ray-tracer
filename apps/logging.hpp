#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>

/// @brief The different levels of logging.
enum class LogLevel { Debug, Info, Warning, Error };

/// @brief Log Level Prefixes.
const std::string LOG_LEVEL_PREFIXES[] = {
  "\033[36m[DEBUG]\033[0m ",// cyan
  "\033[32m[INFO]\033[0m ",// green
  "\033[33m[WARNING]\033[0m ",// yellow
  "\033[31m[ERROR]\033[0m "// red
};

/**
 * @brief Logs a message to the console.
 * @param level The level of the message.
 * @param message The message to log.
 */
void log(LogLevel level, const std::string &message)
{
  // Get the current time
  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  auto now_tm = *std::localtime(&now_c);

  // Format the time and log the message
  std::cout << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " ";
  std::cout << LOG_LEVEL_PREFIXES[static_cast<int>(level)] << message << std::endl;
}