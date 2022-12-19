#pragma once

#include <rt/point.hpp>
#include <rt/ray.hpp>
#include <rt/vec3.hpp>

namespace rt {

/// @brief A surface in 3D space.
struct HitRecord
{
  /// @brief The offset of intersection point
  float t{ 0 };
  /// @brief The point of intersection.
  Point p{ 0, 0, 0 };
  /// @brief The normal of the surface at the intersection point.
  Vec3f normal{ 0, 0, 0 };
};

/// @brief A surface in 3D space.
class Surface
{
public:
  virtual ~Surface() = default;

  /**
   * @brief Returns whether the given ray intersects the surface.
   * @param r The ray to test.
   * @param t_min The minimum offset of the intersection point.
   * @param t_max The maximum offset of the intersection point.
   * @param rec The record of the intersection.
   * @return
   */
  [[nodiscard]] virtual bool Intersect(const Ray &ray, float t_min, float t_max, HitRecord &rec) const noexcept = 0;
};

}// namespace rt
