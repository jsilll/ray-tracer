#pragma once

#include <rt/scene.hpp>
#include <rt/primitives/sphere.hpp>

namespace scenes {

[[nodiscard]] rt::Scene SphereWithGround() noexcept
{
  rt::Scene scene;
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, 0, -1), 0.5f));
  scene.Add(std::make_unique<rt::Sphere>(rt::Point(0, -100.5, -1), 100));
  return scene;
}

}// namespace scenes