#pragma once

#include <rt/camera.hpp>
#include <rt/color.hpp>
#include <rt/point.hpp>
#include <rt/primitives/sphere.hpp>
#include <rt/ray.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>
#include <rt/vec3.hpp>

#include "main.hpp"

using rt::Scene;
using rt::Point;
using rt::HitRecord;
using rt::Ray;
using rt::Sphere;
using rt::Vec3f;
using rt::Color;
using rt::Camera;
using rt::utils::kInf;

[[nodiscard]] Color RayColor(const Ray &ray, const Scene &scene)
{
  HitRecord rec;
  if (scene.Intersect(ray, 0, kInf, rec)) { return 0.5 * (rec.normal + Color(1, 1, 1)); }
  Vec3f unit_direction = ray.direction().Normalized();
  const auto t = 0.5f * (unit_direction.y() + 1.0f);
  return (1.0f - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7f, 1.0);
}

void WriteColor(std::fstream &out, const Color &pixel_color)
{
  constexpr float multiplier = 255.999f;
  out << static_cast<int>(multiplier * pixel_color.x()) << ' ' << static_cast<int>(multiplier * pixel_color.y()) << ' '
      << static_cast<int>(multiplier * pixel_color.z()) << '\n';
}

void Render(const int IMAGE_WIDTH, const int IMAGE_HEIGHT, const Camera &cam, const Scene &scene, std::fstream &out)
{
  constexpr Point origin(0, 0, 0);
  const Vec3f vertical(0, cam.viewport_height(), 0);
  const Vec3f horizontal(cam.viewport_width(), 0, 0);
  const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3f(0, 0, cam.focal_length());

  // Writing Image
  out << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";
  for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
    std::cout << "\rLines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < IMAGE_WIDTH; ++i) {
      // Computing this ray's direction
      const float u = float(i) / (static_cast<float>(IMAGE_WIDTH - 1));
      const float v = float(j) / (static_cast<float>(IMAGE_HEIGHT - 1));
      const Vec3f direction = lower_left_corner + u * horizontal + v * vertical - origin;
      // Computing this ray's color
      const Ray ray(origin, direction);
      const Color pixel_color = RayColor(ray, scene);
      // Writing this ray's color to the image
      WriteColor(out, pixel_color);
    }
  }
  std::cout << "\nDone.\n";
}
