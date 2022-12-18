#pragma once

#include <rt/point.h>
#include <rt/ray.h>
#include <rt/vec3.h>

namespace rt {

/// @brief A sphere in 3D space.
class Sphere final
{
public:
  /**
   * @brief Constructs a sphere with the given center and radius.
   * @param center The center of the sphere.
   * @param radius The radius of the sphere.
   */
  [[nodiscard]] constexpr Sphere(const Point &center, float radius) noexcept : _center(center), _radius(radius) {}

  /**
   * @brief Returns the center of the sphere.
   * @return
   */
  [[nodiscard]] constexpr auto center() const noexcept { return _center; }

  /**
   * @brief Returns the radius of the sphere.
   * @return
   */
  [[nodiscard]] constexpr auto radius() const noexcept { return _radius; }

  /**
   * @brief Returns true the radius of the sphere squared.
   * @return
   */
  [[nodiscard]] constexpr auto Radius2() const noexcept { return _radius * _radius; }

  /**
   * @brief Returns true if the ray intersects the sphere.
   * @param r
   * @return
   */
  [[nodiscard]] constexpr auto IntersectedBy(const Ray &r) const noexcept
  {
    const auto oc = r.origin() - _center;
    const auto a = r.direction().Dot(r.direction());
    const auto b = 2.f * oc.Dot(r.direction());
    const auto c = oc.Dot(oc) - Radius2();
    const auto discriminant = b * b - 4.f * a * c;
    return discriminant > 0;
  }

private:
  Point _center;
  float _radius;
};

}// namespace rt
