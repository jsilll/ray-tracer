#include <algorithm>
#include <iostream>

#include <rt/camera.h>
#include <rt/color.h>
#include <rt/point.h>
#include <rt/primitives/sphere.h>
#include <rt/ray.h>
#include <rt/vec3.h>

using rt::Camera;
using rt::Color;
using rt::Point;
using rt::Ray;
using rt::Vec3f;
using rt::Sphere;

[[nodiscard]] constexpr Color RayColor(const Ray &ray)
{
  constexpr Sphere sphere({ 0, 0, -1 }, 0.5f);
  if (sphere.IntersectedBy(ray)) { return { 1, 0, 0 }; }
  const auto t = 0.5f * (ray.direction().Normalized().y() + 1.f);
  constexpr Color blue(0.5f, 0.7f, 1.f);
  constexpr Color orange(1.f, 0.5f, 0.f);
  return (1.f - t) * orange + t * blue;
}

void WriteColor(std::ostream &out, const Color &pixel_color)
{
  constexpr float multiplier = 255.999f;
  out << static_cast<int>(multiplier * pixel_color.x()) << ' ' << static_cast<int>(multiplier * pixel_color.y()) << ' '
      << static_cast<int>(multiplier * pixel_color.z()) << '\n';
}

void Render(const int IMAGE_WIDTH, const int IMAGE_HEIGHT, const Camera &cam)
{
  constexpr Point origin(0, 0, 0);
  const Vec3f vertical(0, cam.viewport_height(), 0);
  const Vec3f horizontal(cam.viewport_width(), 0, 0);
  const auto lower_left_corner =
    origin - horizontal / 2 - vertical / 2 - Vec3f(0, 0, cam.focal_length());

  // Writing Image
  std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";
  for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
    std::cerr << "\rLines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < IMAGE_WIDTH; ++i) {
      // Computing this ray's direction
      const float u = float(i) / (static_cast<float>(IMAGE_WIDTH - 1));
      const float v = float(j) / (static_cast<float>(IMAGE_HEIGHT - 1));
      const Vec3f direction = lower_left_corner + u * horizontal + v * vertical - origin;
      // Computing this ray's color
      const Ray ray(origin, direction);
      const Color pixel_color = RayColor(ray);
      // Writing this ray's color to the image
      WriteColor(std::cout, pixel_color);
    }
  }
  std::cerr << "\nDone.\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
  // Image
  constexpr int IMAGE_WIDTH = 400;
  constexpr float ASPECT_RATIO = 16.f / 9.f;
  constexpr int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

  // Camera
  constexpr Camera cam(1.f, static_cast<float>(ASPECT_RATIO) * 2.f, 2.f);

  Render(IMAGE_WIDTH, IMAGE_HEIGHT, cam);

  return EXIT_SUCCESS;
}