#pragma once

#include <rt/color.hpp>
#include <rt/materials/material.hpp>

namespace rt {

/// @brief Lambertian Hack Implementation.
class LambertianHack final : public Material
{
public:
  /**
   * @brief Constructs a diffuse material with the given albedo.
   * @param albedo The albedo of the material.
   */
  [[nodiscard]] explicit LambertianHack (const Color &albedo) noexcept : _albedo(albedo) {}

  [[nodiscard]] bool Scatter(const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const noexcept override;

private:
  /// @brief The albedo of the material.
  Color _albedo;
};

}// namespace rt
