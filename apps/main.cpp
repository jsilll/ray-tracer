#include "args_parser.hpp"
#include "logging.hpp"
#include "renderer.hpp"
#include "scenes.hpp"

#include <rt/camera.hpp>

#include <algorithm>
#include <iostream>

using rt::Scene;
using rt::Camera;

struct Args
{
  std::size_t seed{};
  std::size_t width{};
  std::size_t samples{};
  std::size_t height{};
  std::size_t bounces{};
  std::string_view output;
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  // Parse the command line arguments
  Args args;
  ArgsParser args_parser;
  args_parser.ParseArgs(argc, argv);
  try {
    // TODO: actually use these arguments
    args.output = args_parser.GetValue("output");
    args.seed = std::stoul(args_parser.GetValue("seed"));
    args.width = std::stoul(args_parser.GetValue("width"));
    args.height = std::stoul(args_parser.GetValue("height"));
    args.samples = std::stoul(args_parser.GetValue("samples"));
    args.bounces = std::stoul(args_parser.GetValue("bounces"));
  } catch (const std::exception &e) {
    log(LogLevel::Error, e.what());
    return EXIT_FAILURE;
  }

  // Setting up the Scene
  Scene scene = scenes::SphereWithGround();

  // Defining the Image Dimensions
  constexpr int IMAGE_WIDTH = 1920;
  constexpr float ASPECT_RATIO = 16.f / 9.f;
  constexpr int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

  // Setting up a Camera
  const auto camera = Camera(1, ASPECT_RATIO * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });

  // Rendering the Image
  const auto renderer = Renderer(IMAGE_WIDTH, IMAGE_HEIGHT, scene);
  log(LogLevel::Info, "Rendering...");
  const auto image = renderer.Render(camera);
  log(LogLevel::Info, "Done!");

  // Saving Image
  log(LogLevel::Info, "Saving Image...");
  try {
    image.SaveAsPPM("/home/joao/Downloads/image.ppm");
  } catch (const std::exception &e) {
    log(LogLevel::Error, "Failed to save image!");
    return EXIT_FAILURE;
  }
  log(LogLevel::Info, "Done!");

  return EXIT_SUCCESS;
}