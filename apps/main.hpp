#pragma once

#include "args_parser.hpp"
#include "logging.hpp"

#include <string>
#include <unordered_map>

/// @brief The possible rendering types.
enum class RenderType {
  kNormalMap,
  kDepthMap,
};

/// @brief Converts a string to a RenderType.
const std::unordered_map<std::string, RenderType> str_to_render_type = { { "normal_map", RenderType::kNormalMap },
  { "depth_map", RenderType::kDepthMap } };

/// @brief Converts a RenderType to a string.
const std::unordered_map<RenderType, std::string> render_type_to_str = { { RenderType::kNormalMap, "normal_map" },
  { RenderType::kDepthMap, "depth_map" } };

/// @brief The arguments for the program.
struct Args
{
  /// @brief The seed to use.
  std::size_t seed{};
  /// @brief The width of the image.
  std::size_t width{};
  /// @brief The samples per pixel.
  std::size_t samples{};
  /// @brief The height of the image.
  std::size_t height{};
  /// @brief The number of ray bounces.
  std::size_t bounces{};
  /// @brief The output file.
  std::string output{};
  /// @brief The type of render to perform.
  RenderType render_type{};

  /// @brief The maximum depth of the depth map, optional.
  float max_depth{ 1 };
};

/**
 * @brief Parses the command line arguments.
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return
 */
Args GetArgs(const int argc, char *argv[])
{
  Args args;
  ArgsParser args_parser;
  args_parser.ParseArgs(argc, argv);

  // Parsing required arguments
  args.output = args_parser.GetValue("output");
  args.seed = std::stoul(args_parser.GetValue("seed"));
  args.width = std::stoul(args_parser.GetValue("width"));
  args.height = std::stoul(args_parser.GetValue("height"));
  args.samples = std::stoul(args_parser.GetValue("samples"));
  args.bounces = std::stoul(args_parser.GetValue("bounces"));

  // Parsing the render type argument, enum conversion
  const auto render_type_str = args_parser.GetValue("render_type");
  const auto render_type_it = str_to_render_type.find(render_type_str);
  if (render_type_it == str_to_render_type.end()) {
    throw std::runtime_error("Invalid 'render_type' argument.");
  } else {
    args.render_type = render_type_it->second;
  }

  // Parsing optional arguments
  try {
    args.max_depth = std::stof(args_parser.GetValue("max_depth"));
  } catch (const std::runtime_error &e) {
    if (args.render_type == RenderType::kDepthMap) {
      log(LogLevel::kWarning,
        "'max_depth' argument missing, using default value of 1.");
    }
  }

  return args;
}

/**
 * @brief Prints the parsed arguments, for debugging purposes.
 */
void LogArgs(const Args &args)
{
  log(LogLevel::kDebug, "Seed: " + std::to_string(args.seed));
  log(LogLevel::kDebug, "Width: " + std::to_string(args.width));
  log(LogLevel::kDebug, "Height: " + std::to_string(args.height));
  log(LogLevel::kDebug, "Samples: " + std::to_string(args.samples));
  log(LogLevel::kDebug, "Bounces: " + std::to_string(args.bounces));
  log(LogLevel::kDebug, "Render type: " + render_type_to_str.at(args.render_type));
  log(LogLevel::kDebug, "Output: " + args.output);
}
