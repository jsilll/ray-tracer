#include "renderer.hpp"
#include "scenes.hpp"

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

  // Rendering
  const auto renderer = Renderer(IMAGE_WIDTH, IMAGE_HEIGHT, scene);

  // Setting up a Camera
  const auto camera = Camera(1, ASPECT_RATIO * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });

  // Rendering the Image
  std::cout << "Rendering..." << std::endl;
  const auto image = renderer.Render(camera);
  std::cout << "Done Rendering" << std::endl;

  // Saving Image
  std::cout << "Saving Image..." << std::endl;
  try {
    image.SaveAsPPM("/home/joao/Downloads/image.ppm");
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Done Saving Image" << std::endl;

  return EXIT_SUCCESS;
}