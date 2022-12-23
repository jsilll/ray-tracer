#pragma once

#include <map>
#include <stdexcept>
#include <string>

/// @brief A simple command line argument parser.
class Clap final
{
public:
  /**
   * @brief Parses the command line arguments in long form.
   * Example: --width=1920 --height=1080 ...
   * @param argc The number of arguments.
   * @param argv The arguments.
   * @return
   */
  void Parse(int argc, char *argv[]) noexcept;

  /**
   * @brief Returns the value of the given key.
   * @param key The key to get the value of.
   * @return
   */
  [[nodiscard]] std::string Value(const std::string &key) const
  {
    auto it = _args.find(key);
    if (it != _args.end()) { return it->second; }
    throw std::runtime_error('\'' + key + "' argument not found.");
  }

private:
  /// @brief The arguments.
  std::map<std::string, std::string> _args;
};
