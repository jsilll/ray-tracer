#include <scenes.hpp>

namespace scenes {

std::pair<rt::Scene, rt::Camera> SphereWithGround(const double aspect_ratio) noexcept
{
  rt::Scene scene;
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, 0, -1), 0.5));
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, -100.5, -1), 100));
  auto camera = rt::Camera(1, aspect_ratio * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  return { std::move(scene), camera };
}

}// namespace scenes