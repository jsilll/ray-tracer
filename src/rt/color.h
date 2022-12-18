#pragma once

#include <rt/vec3.h>

namespace rt {

/// @brief A color in RGB space.
using Color = Vec3f;

namespace color {

  /**
   * @brief Returns a color from the normals of a surface.
   * @param normal
   * @return
   */
  [[nodiscard]] constexpr Color FromNormal(const Vec3f &normal) noexcept { return (normal + 1.0f) / 2; }

}// namespace color

}// namespace rt