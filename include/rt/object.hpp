#pragma once

#include <rt/hit_record.hpp>
#include <rt/point.hpp>
#include <rt/ray.hpp>
#include <rt/vec3.hpp>

namespace rt {

/// @brief An object in 3D space.
class Object
{
public:
  virtual ~Object() = default;

  /**
   * @brief Returns whether the given ray intersects the surface.
   * @param ray The ray to test.
   * @param t_min The minimum offset of the intersection point.
   * @param t_max The maximum offset of the intersection point.
   * @param rec The record of the intersection.
   * @return
   */
  [[nodiscard]] virtual bool Intersect(const Ray &ray, double t_min, double t_max, HitRecord &rec) const noexcept = 0;
};

}// namespace rt
