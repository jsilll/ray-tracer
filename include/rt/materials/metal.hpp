#pragma once

#include <rt/color.hpp>
#include <rt/materials/material.hpp>
#include <rt/ray.hpp>

namespace rt {

class Metal final : public Material
{
public:
  /**
   * @brief Constructs a metal material with the given albedo and fuzziness.
   * @param albedo The albedo of the material.
   * @param fuzziness The fuzziness of the material.
   */
  [[nodiscard]] explicit Metal(const Color &albedo, const double fuzziness) noexcept
    : _albedo(albedo), _fuzziness(fuzziness)
  {}

  [[nodiscard]] bool
    Scatter(const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const noexcept override;

private:
  /// @brief The albedo of the material.
  Color _albedo;
  /// @brief The fuzziness of the material.
  double _fuzziness;
};

}// namespace rt