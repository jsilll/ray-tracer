#pragma once

#include <rt/object.hpp>
#include <rt/point.hpp>
#include <rt/ray.hpp>
#include <rt/vec3.hpp>

namespace rt {

/// @brief A sphere in 3D space.
class Sphere final : public Object
{
public:
  /**
   * @brief Constructs a sphere with the given center and radius.
   * @param center The center of the sphere.
   * @param radius The radius of the sphere.
   */
  [[nodiscard]] constexpr Sphere(const Point &center, const double radius) noexcept : _center(center), _radius(radius) {}

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
   * @brief Returns radius of the sphere squared.
   * @return
   */
  [[nodiscard]] constexpr auto Radius2() const noexcept { return _radius * _radius; }

  [[nodiscard]] bool Intersect(const Ray &ray, double t_min, double t_max, HitRecord &rec) const noexcept override;

private:
  /// @brief The center of the sphere.
  Point _center;
  /// @brief The radius of the sphere.
  double _radius;
};

}// namespace rt
