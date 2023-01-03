#pragma once

#include <rt/color.hpp>
#include <rt/hit_record.hpp>
#include <rt/ray.hpp>

namespace rt {

/// @brief A material that can be applied to any 3d object.
class Material
{
public:
  virtual ~Material() = default;

  /**
   * @brief Returns whether the given ray intersects the surface.
   * @param ray The ray to test.
   * @param rec The hit record.
   * @param attenuation The attenuation of the ray.
   * @param scattered The scattered ray.
   * @return
   */
  [[nodiscard]] virtual bool
    Scatter(const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const noexcept = 0;
};

}// namespace rt