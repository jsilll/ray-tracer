#pragma once

#include <rt/camera.hpp>
#include <rt/primitives/sphere.hpp>
#include <rt/scene.hpp>

#include <utility>

namespace scenes {

/**
 * @brief Creates a scene with a single sphere and
 * another larger sphere as ground for casting shadows.
 * @return
 */
[[nodiscard]] std::pair<rt::Scene, rt::Camera> SphereWithGround(const float aspect_ratio) noexcept
{
  rt::Scene scene;
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, 0, -1), 0.5f));
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, -100.5, -1), 100));
  auto camera = rt::Camera(1, aspect_ratio * 2, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  return { std::move(scene), camera };
}

}// namespace scenes