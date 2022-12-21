#pragma once

#include "args_parser.hpp"
#include "logging.hpp"

#include <string>
#include <unordered_map>

enum class RenderType {
  kNormalMap,
  kDepthMap,
};

const std::unordered_map<std::string, RenderType> str_to_render_type = { { "normal_map", RenderType::kNormalMap },
  { "depth_map", RenderType::kDepthMap } };

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
};

Args GetArgs(const int argc, char *argv[])
{
  Args args;
  ArgsParser args_parser;
  args_parser.ParseArgs(argc, argv);
  args.output = args_parser.GetValue("output");
  args.seed = std::stoul(args_parser.GetValue("seed"));
  args.width = std::stoul(args_parser.GetValue("width"));
  args.height = std::stoul(args_parser.GetValue("height"));
  args.samples = std::stoul(args_parser.GetValue("samples"));
  args.bounces = std::stoul(args_parser.GetValue("bounces"));
  const auto render_type_str = args_parser.GetValue("render_type");
  const auto render_type_it = str_to_render_type.find(render_type_str);
  if (render_type_it == str_to_render_type.end()) {
    throw std::runtime_error("Invalid 'render_type' argument.");
  } else {
    args.render_type = render_type_it->second;
  }
  return args;
}

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
