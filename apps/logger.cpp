#include <logger.hpp>

/// @brief Log Level Prefixes.
const std::string LOG_LEVEL_PREFIXES[] = {
  "\033[32m[INFO]\033[0m ",// green
  "\033[33m[WARNING]\033[0m ",// yellow
  "\033[31m[ERROR]\033[0m "// red
};

void Logger::Log(LogLevel level, const std::string &message) const noexcept
{
  // Get the current time
  const auto now = std::chrono::system_clock::now();
  const auto now_c = std::chrono::system_clock::to_time_t(now);
  const auto now_tm = *std::localtime(&now_c);

  // Format the time and log the message (this assumes no concurrent accesses)
  std::cout << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << " ";
  std::cout << LOG_LEVEL_PREFIXES[static_cast<int>(level)] << message << std::endl;
}
