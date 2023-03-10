#include <main.hpp>

#include <renderer.hpp>
#include <scenes.hpp>

#include <rt/rendering.hpp>

#include <algorithm>
#include <optional>

using rt::Scene;
using rt::Camera;

std::pair<rt::Scene, rt::Camera> LoadScene(SceneType scene_type, const double aspect_ratio) noexcept
{
  switch (scene_type) {
  case kDefault:
    return scenes::Default(aspect_ratio);
  case kMetalSpheres:
    return scenes::MetalSpheres(aspect_ratio);
  default:
    return scenes::Default(aspect_ratio);
  }
}

int main(int argc, char *argv[])
{
  // Create the logger
  Logger logger(std::cout);

  // Program Arguments
  Args args;
  try {
    args = GetArgs(argc, argv, logger);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  // Setting up the scene and camera
  const auto [scene, camera] =
    LoadScene(args.scene_type, static_cast<double>(args.width) / static_cast<double>(args.height));

  // Setting up the Renderer
  const auto samples = static_cast<int>(args.samples);
  const auto renderer = Renderer(args.width, args.height, samples, scene);

  // Rendering
  Image image;
  logger.Log(LogLevel::kInfo, "Rendering Image");
  switch (args.render_type) {
  case RenderType::kNormalMap:
    image = renderer.Render(camera, rt::rendering::RenderNormal);
    break;
  case RenderType::kDepthMap:
    image = renderer.Render(
      camera, [&](const auto &s, const auto &r) { return rt::rendering::RenderDepth(s, r, args.max_depth); });
    break;
  case RenderType::kBeauty:
    image = renderer.Render(
      camera, [&](const auto &s, const auto &r) { return rt::rendering::RenderBeauty(s, r, args.bounces); });
    break;
  }

  // Saving the Image
  logger.Log(LogLevel::kInfo, "Saving Image");
  try {
    image.SaveAsPPM(args.output);
  } catch (const std::exception &e) {
    logger.Log(LogLevel::kError, "Failed to save image");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}