#include "scenes.hpp"
#include "renderer.hpp"

#include <rt/camera.hpp>

#include <algorithm>
#include <iostream>

using rt::Scene;
using rt::Camera;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  // Setting up the Scene
  Scene scene = scenes::SphereWithGround();

  // Defining the Image Dimensions
  constexpr int IMAGE_WIDTH = 1920;
  constexpr float ASPECT_RATIO = 16.f / 9.f;
  constexpr int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

  // Setting up a Camera
  constexpr Camera camera(1, ASPECT_RATIO * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });

  // Rendering
  constexpr Renderer renderer(IMAGE_WIDTH, IMAGE_HEIGHT);
  const auto image = renderer.Render(scene, camera);

  // Saving Image
  try {
    image.SaveAsPPM("/home/joao/Downloads/image.ppm");
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}