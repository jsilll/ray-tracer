#pragma once

#include <clap.hpp>
#include <logger.hpp>

#include <string>
#include <thread>
#include <unordered_map>

/// @brief The possible rendering types.
enum class RenderType {
  kBeauty,
  kNormalMap,
  kDepthMap,
};

/// @brief Converts a string to a RenderType.
const std::unordered_map<std::string, RenderType> str_to_render_type = { { "normal_map", RenderType::kNormalMap },
  { "depth_map", RenderType::kDepthMap },
  { "beauty", RenderType::kBeauty } };

/// @brief Converts a RenderType to a string.
const std::unordered_map<RenderType, std::string> render_type_to_str = { { RenderType::kNormalMap, "normal_map" },
  { RenderType::kDepthMap, "depth_map" },
  { RenderType::kBeauty, "beauty" } };

/// @brief The arguments for the program.
struct Args
{
  /// @brief The width of the image.
  std::size_t width{};
  /// @brief The height of the image.
  std::size_t height{};
  /// @brief The seed to use.
  unsigned int seed{};
  /// @brief The samples per pixel.
  unsigned int samples{};
  /// @brief The output file.
  std::string output{};
  /// @brief The type of render to perform.
  RenderType render_type{};

  /// @brief The maximum depth of the depth map, optional.
  double max_depth{ 1 };
  /// @brief The number of ray bounces, optional.
  unsigned int bounces{ 50 };
  /// @brief The number of threads to use, optional.
  unsigned int threads{ std::thread::hardware_concurrency() };
};

/**
 * @brief Parses the command line arguments.
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return
 */
Args GetArgs(const int argc, char *argv[], Logger &logger)
{
  Args args;
  Clap args_parser;
  args_parser.Parse(argc, argv);

  // Parsing required arguments
  args.output = args_parser.Value("output");
  args.seed = std::stoul(args_parser.Value("seed"));
  args.width = std::stoul(args_parser.Value("width"));
  args.height = std::stoul(args_parser.Value("height"));
  args.samples = std::stoul(args_parser.Value("samples"));

  // Parsing the required 'render_type' argument, enum conversion
  const auto render_type_str = args_parser.Value("render_type");
  const auto render_type_it = str_to_render_type.find(render_type_str);
  if (render_type_it == str_to_render_type.end()) {
    throw std::runtime_error("Invalid 'render_type' argument");
  } else {
    args.render_type = render_type_it->second;
  }

  // Parsing optional 'max_depth' argument
  try {
    args.max_depth = std::stof(args_parser.Value("max_depth"));
  } catch (const std::runtime_error &e) {
    if (args.render_type == RenderType::kDepthMap) {
      logger.Log(LogLevel::kWarning, "'max_depth' argument missing, using default value of 1");
    }
  }

  // Parsing optional 'bounces' argument
  try {
    args.bounces = std::stoul(args_parser.Value("bounces"));
  } catch (const std::exception &) {
    if (args.render_type == RenderType::kBeauty) {
      logger.Log(LogLevel::kWarning, "'bounces' argument missing, using default value of 50");
    }
  }

  // Parsing optional 'threads' argument
  try {
    args.threads = std::stoul(args_parser.Value("threads"));
  } catch (const std::exception &) {
    logger.Log(LogLevel::kWarning,
      "'threads' argument missing, using default value of " + std::to_string(std::thread::hardware_concurrency()));
  }

  return args;
}