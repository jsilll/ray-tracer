#pragma once

#include <clap.hpp>
#include <logger.hpp>

#include <fstream>
#include <string>
#include <thread>
#include <unordered_map>

/// @brief Defines for the command line arguments keys.
#define WIDTH_KEY "width"
#define HEIGHT_KEY "height"
#define OUTPUT_KEY "output"
#define SAMPLES_KEY "samples"
#define BOUNCES_KEY "bounces"
#define RENDER_TYPE_KEY "type"
#define MAX_DEPTH_KEY "max_depth"

/// @brief Defines for the 'render_type' command line argument possible values.
#define RENDER_TYPE_VAL_BEAUTY "beauty"
#define RENDER_TYPE_VAL_DEPTH_MAP "depth"
#define RENDER_TYPE_VAL_NORMAL_MAP "normal"

/// @brief Defines for the error messages.
#define ERROR_OUTPUT "'output' argument is invalid"
#define ERROR_WIDTH "'width' argument is invalid"
#define ERROR_HEIGHT "'height' argument is invalid"
#define ERROR_RENDER_TYPE "'type' argument is invalid"
#define ERROR_SAMPLES "'samples' argument is either invalid or missing, using default value of 32"
#define ERROR_MAX_DEPTH "'max_depth' argument is either invalid or missing, using default value of 1"
#define ERROR_BOUNCES "'bounces' argument is either invalid or missing, using default value of 50"

/// @brief The possible rendering types.
enum class RenderType {
  kBeauty,
  kNormalMap,
  kDepthMap,
};

/// @brief Converts a string to a RenderType.
const std::unordered_map<std::string, RenderType> str_to_render_type = { { RENDER_TYPE_VAL_BEAUTY,
                                                                           RenderType::kBeauty },
  { RENDER_TYPE_VAL_NORMAL_MAP, RenderType::kNormalMap },
  { RENDER_TYPE_VAL_DEPTH_MAP, RenderType::kDepthMap } };

/// @brief The arguments for the program.
struct Args
{
  // Required Arguments

  /// @brief The width of the image.
  std::size_t width{};
  /// @brief The height of the image.
  std::size_t height{};
  /// @brief The output file.
  std::string output{};
  /// @brief The type of render to perform.
  RenderType render_type{};

  // Optional arguments

  /// @brief The maximum depth of the depth map.
  double max_depth{ 1 };
  /// @brief The samples per pixel.
  unsigned int samples{ 32 };
  /// @brief The number of ray bounces.
  unsigned int bounces{ 50 };
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

  Clap parser;
  parser.Parse(argc, argv);

  // Parsing the required 'output' argument
  try {
    args.output = parser.Value(OUTPUT_KEY);
  } catch (const std::exception &e) {
    throw std::runtime_error(ERROR_OUTPUT);
  }

  // Parsing the required 'width' argument
  try {
    args.width = std::stoul(parser.Value(WIDTH_KEY));
  } catch (const std::exception &e) {
    throw std::runtime_error(ERROR_WIDTH);
  }

  // Parsing the required 'output' argument
  try {
    args.height = std::stoul(parser.Value(HEIGHT_KEY));
  } catch (const std::exception &e) {
    throw std::runtime_error(ERROR_HEIGHT);
  }

  // Parsing the required 'type' argument
  try {
    args.render_type = str_to_render_type.at(parser.Value(RENDER_TYPE_KEY));
  } catch (const std::exception &e) {
    throw std::runtime_error(ERROR_RENDER_TYPE);
  }

  // Parsing optional 'samples' argument
  try {
    args.samples = std::stoul(parser.Value(SAMPLES_KEY));
  } catch (const std::invalid_argument &e) {
    if (args.render_type == RenderType::kBeauty) { logger.Log(LogLevel::kWarning, ERROR_SAMPLES); }
  }

  // Parsing optional 'max_depth' argument
  try {
    args.max_depth = std::stof(parser.Value(MAX_DEPTH_KEY));
  } catch (const std::runtime_error &e) {
    if (args.render_type == RenderType::kDepthMap) { logger.Log(LogLevel::kWarning, ERROR_MAX_DEPTH); }
  }

  // Parsing optional 'bounces' argument
  try {
    args.bounces = std::stoul(parser.Value(BOUNCES_KEY));
  } catch (const std::exception &) {
    if (args.render_type == RenderType::kBeauty) { logger.Log(LogLevel::kWarning, ERROR_BOUNCES); }
  }

  return args;
}