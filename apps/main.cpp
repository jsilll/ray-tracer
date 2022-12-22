#include "main.hpp"
#include "renderer.hpp"
#include "scenes.hpp"

#include <rt/camera.hpp>
#include <rt/rendering.hpp>

#include <algorithm>
#include <optional>

using rt::Scene;
using rt::Camera;

int main(int argc, char *argv[])
{
  // Parse the command line arguments
  Args args;
  try {
    args = GetArgs(argc, argv);
  } catch (const std::exception &e) {
    log(LogLevel::kError, e.what());
    std::exit(EXIT_FAILURE);
  }
#ifdef DEBUG
  LogArgs(args);
#endif

  // Setting up the scene and camera
#ifdef DEBUG
  log(LogLevel::kDebug, "Setting up the scene and camera");
#endif
  const auto [scene, camera] =
    scenes::SphereWithGround(static_cast<float>(args.width) / static_cast<float>(args.height));

  // Setting up the Image and Rendered classes
#ifdef DEBUG
  log(LogLevel::kDebug, "Setting up the Image and Renderer classes.");
#endif
  Image image;
  const auto renderer = Renderer(args.width, args.height, scene);

  // Rendering
  log(LogLevel::kInfo, "Rendering Image.");
  switch (args.render_type) {
  case RenderType::kNormalMap:
    image = renderer.Render(camera, rt::rendering::RenderNormalMap);
    break;
  case RenderType::kDepthMap:
    image = renderer.Render(
      camera, [&](const auto &s, const auto &r) { return rt::rendering::RenderDepthMap(s, r, args.max_depth); });
    break;
  }
#if DEBUG
  log(LogLevel::kDebug, "Finished Rendering.");
#endif

  // Saving the Image
  log(LogLevel::kInfo, "Saving Image.");
  try {
    image.SaveAsPPM(args.output);
  } catch (const std::exception &e) {
    log(LogLevel::kError, "Failed to save image!");
    return EXIT_FAILURE;
  }
#ifdef DEBUG
  log(LogLevel::kDebug, "Finished Saving Image.");
#endif

  return EXIT_SUCCESS;
}