#pragma once

#include <rt/point.h>
#include <rt/ray.h>
#include <rt/vec3.h>

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
   * @param r
   * @param t_min
   * @param t_max
   * @param rec
   * @return
   */
  virtual bool Intersect(const Ray &ray, float t_min, float t_max, HitRecord &rec) const noexcept = 0;
};

}// namespace rt