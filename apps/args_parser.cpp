#include "args_parser.hpp"

#include <string_view>

void ArgsParser::ParseArgs(int argc, char *argv[]) noexcept
{
  for (int i = 1; i < argc; i++) {
    std::string_view arg(argv[i]);
    if (arg.starts_with("--")) {
      // Long option
      size_t pos = arg.find('=');
      if (pos != std::string_view::npos) {
        // Option with value
        std::string key = std::string(arg.substr(2, pos - 2));
        std::string value = std::string(arg.substr(pos + 1));
        _args[key] = value;
      } else {
        // Option without value
        std::string key = std::string(arg.substr(2));
        _args[key] = "";
      }
    } else if (arg.starts_with("-")) {
      // Short option
      if (arg.size() > 2) {
        // Option cluster
        for (size_t j = 1; j < arg.size(); j++) {
          char ch = arg[j];
          _args[std::string(1, ch)] = "";
        }
      } else {
        // Single short option
        char ch = arg[1];
        if (i + 1 < argc && argv[i + 1][0] != '-') {
          // Option with value
          std::string value = argv[i + 1];
          _args[std::string(1, ch)] = value;
          i++;
        } else {
          // Option without value
          _args[std::string(1, ch)] = "";
        }
      }
    } else {
      // Positional argument
      _args[std::string()] = arg;
    }
  }
}
