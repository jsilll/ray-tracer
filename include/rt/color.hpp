#pragma once

#include <rt/vec3.hpp>

namespace rt {

/// @brief A color in RGB space.
using Color = Vec3f;

/// @brief Aggregates the color utilities for the library.
namespace color {

  /**
   * @brief Returns a color from the normals of a surface.
   * @param normal The normal of the surface.
   * @return
   */
  [[nodiscard]] constexpr Color FromNormal(const Vec3f &normal) noexcept { return (normal + 1.0f) / 2; }

}// namespace color

}// namespace rt