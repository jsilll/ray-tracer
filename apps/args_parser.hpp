#pragma once

#include <map>
#include <stdexcept>
#include <string>

/// @brief A simple class for parsing command line arguments.
class ArgsParser final
{
public:
  /**
   * @brief Parses the command line arguments.
   * @param argc The number of arguments.
   * @param argv The arguments.
   * @return
   */
  void ParseArgs(int argc, char *argv[]) noexcept;

  /**
   * @brief Returns the value of the given key.
   * @param key The key to get the value of.
   * @return
   */
  [[nodiscard]] std::string GetValue(const std::string &key) const
  {
    auto it = _args.find(key);
    if (it != _args.end()) { return it->second; }
    throw std::runtime_error('\'' + key + "' argument not found.");
  }

private:
  /// @brief The arguments.
  std::map<std::string, std::string> _args;
};
