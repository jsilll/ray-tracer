#pragma once

#include <rt/color.hpp>
#include <rt/materials/material.hpp>

namespace rt {

/// @brief Lambertian Alternative Implementation.
class LambertianAlt final : public Material
{
public:
  /**
   * @brief Constructs a diffuse material with the given albedo.
   * @param albedo The albedo of the material.
   */
  [[nodiscard]] explicit LambertianAlt(const Color &albedo) noexcept : _albedo(albedo) {}

  [[nodiscard]] bool Scatter([[maybe_unused]] const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const noexcept override
  {
    attenuation = _albedo;
    scattered = Ray(rec.p, Vec3::RandomInHemisphere(rec.normal));
    return true;
  }

private:
  /// @brief The albedo of the material.
  Color _albedo;
};

}// namespace rt
