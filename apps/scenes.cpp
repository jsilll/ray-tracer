#include <scenes.hpp>

#include <rt/materials/lambertian_alt.hpp>
#include <rt/materials/lambertian_hack.hpp>
#include <rt/materials/lambertian_true.hpp>
#include <rt/materials/metal.hpp>
#include <rt/primitives/sphere.hpp>

#include <memory>

namespace scenes {

std::pair<rt::Scene, rt::Camera> SphereWithGround(const double aspect_ratio) noexcept
{
  rt::Scene scene;
  const auto camera = rt::Camera(1, aspect_ratio * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });

  const auto color = rt::Color(0.75, 0.75, 0.75);
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, 0, -1), 0.5, std::make_unique<rt::LambertianTrue>(color)));
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, -100.5, -1), 100, std::make_unique<rt::LambertianTrue>(color)));

  return { std::move(scene), camera };
}

std::pair<rt::Scene, rt::Camera> MetalSpheres(const double aspect_ratio) noexcept
{
  rt::Scene scene;
  const auto camera = rt::Camera(1, aspect_ratio * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });

  const auto color_ground = rt::Color(0.8, 0.8, 0.0);
  const auto color_center = rt::Color(0.7, 0.3, 0.3);
  const auto color_left = rt::Color(0.8, 0.8, 0.8);
  const auto color_right = rt::Color(0.8, 0.6, 0.2);

  scene.Add(std::make_unique<rt::Sphere>(
    rt::Point(0.0, -100.5, -1.0), 100.0, std::make_unique<rt::LambertianTrue>(color_ground)));
  scene.Add(
    std::make_unique<rt::Sphere>(rt::Point(0.0, 0.0, -1.0), 0.5, std::make_unique<rt::LambertianTrue>(color_center)));

  scene.Add(
    std::make_unique<rt::Sphere>(rt::Point(-1.0, 0.0, -1.0), 0.5, std::make_unique<rt::Metal>(color_left, 0.3)));
  scene.Add(
    std::make_unique<rt::Sphere>(rt::Point(1.0, 0.0, -1.0), 0.5, std::make_unique<rt::Metal>(color_right, 0.3)));

  return { std::move(scene), camera };
}

}// namespace scenes