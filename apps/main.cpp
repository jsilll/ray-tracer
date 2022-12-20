#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

#include <rt/camera.hpp>
#include <rt/primitives/sphere.hpp>
#include <rt/scene.hpp>

#include "main.hpp"

using rt::Scene;
using rt::Sphere;
using rt::Camera;

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  // Image
  constexpr int IMAGE_WIDTH = 400;
  constexpr float ASPECT_RATIO = 16.f / 9.f;
  constexpr int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

  // Opening the output file
  std::string filename{ "/home/joao/Downloads/image.ppm" };
  std::fstream file{ filename, std::fstream::out };

  if (!file.is_open()) {
    std::cerr << "Error: Could not open file '" << filename << "' for writing." << std::endl;
    return EXIT_FAILURE;
  }

  // Camera
  constexpr Camera cam(1, ASPECT_RATIO * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });

  // Scene
  Scene scene;
  scene.Add(std::make_unique<Sphere>(Point(0, 0, -1), 0.5f));
  scene.Add(std::make_unique<Sphere>(Point(0, -100.5, -1), 100));

  // Rendering
  Render(IMAGE_WIDTH, IMAGE_HEIGHT, cam, scene, file);

  return EXIT_SUCCESS;
}