#pragma once

#include <rt/point.h>
#include <rt/vec3.h>

namespace rt {

/// @brief A ray in 3D space.
class Ray final
{
public:
  /**
   * @brief Constructs a ray with the given origin and direction.
   * @param origin The origin of the ray.
   * @param direction The direction of the ray.
   */
  [[nodiscard]] constexpr Ray(const Point &origin, const Vec3f &direction) noexcept
    : _origin(origin), _direction(direction)
  {}

  /**
   * @brief Returns the origin of the ray.
   * @return
   */
  [[nodiscard]] constexpr auto origin() const noexcept { return _origin; }

  /**
   * @brief Returns the direction of the ray.
   * @return
   */
  [[nodiscard]] constexpr auto direction() const noexcept { return _direction; }

  /**
   * @brief Returns the point at the given distance along the ray.
   * @param t The distance along the ray.
   * @return
   */
  [[nodiscard]] constexpr auto At(const float t) const noexcept { return _origin + t * _direction; }

private:
  Point _origin;
  Vec3f _direction;
};

}// namespace rt