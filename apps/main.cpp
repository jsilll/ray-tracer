#include "renderer.hpp"

#include <rt/camera.hpp>
#include <rt/primitives/sphere.hpp>
#include <rt/scene.hpp>

#include <algorithm>
#include <iostream>

using rt::Point;
using rt::Scene;
using rt::Sphere;
using rt::Camera;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  // Setting up the Scene
  Scene scene;
  scene.Add(std::make_unique<Sphere>(Point(0, 0, -1), 0.5f));
  scene.Add(std::make_unique<Sphere>(Point(0, -100.5, -1), 100));

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