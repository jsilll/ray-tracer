#pragma once

#include <rt/point.hpp>
#include <rt/ray.hpp>

namespace rt {

/// @brief A material that reflects rays.
class Material;

/// @brief A surface in 3D space.
struct HitRecord
{
  /// @brief The offset of intersection point
  double t{ 0 };
  /// @brief The point of intersection.
  Point p{ 0, 0, 0 };
  /// @brief True if the ray is outside the surface.
  bool front_face{ false };
  /// @brief The normal of the surface at the intersection point.
  /// @note Should always be normalized and point in the opposite direction as the ray.
  Vec3 normal{ 0, 0, 0 };

  /**
   * @brief Sets the normal of the surface.
   * @param r The ray.
   * @param outwards_normal The normal of the surface. Should always be normalized and point in the outwards direction
   * of the surface.
   * @return
   */
  constexpr void SetFaceNormal(const Ray &r, const Vec3 &outwards_normal) noexcept
  {
    front_face = r.direction().Dot(outwards_normal) <= 0;
    normal = front_face ? outwards_normal : -outwards_normal;
  }
};

}// namespace rt