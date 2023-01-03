#include <clap.hpp>

#include <string_view>

void Clap::Parse(int argc, char *argv[]) noexcept
{
  // For each argument
  for (int i = 1; i < argc; ++i) {
    std::string_view arg(argv[i]);
    // If the argument is a key
    if (arg.starts_with("--")) {
      std::size_t pos = arg.find('=');
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
    }
  }
}
