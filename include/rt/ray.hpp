#pragma once

#include <rt/point.hpp>
#include <rt/vec3.hpp>

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
  [[nodiscard]] constexpr Ray(const Point &origin, const Vec3 &direction) noexcept
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
  [[nodiscard]] constexpr auto At(const double t) const noexcept { return _origin + t * _direction; }

private:
  /// @brief The origin of the ray.
  Point _origin;
  /// @brief The direction of the ray.
  Vec3 _direction;
};

}// namespace rt