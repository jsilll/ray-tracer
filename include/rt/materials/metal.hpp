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
    Scatter(const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const noexcept override
  {
    const auto reflected = Vec3::Reflect(Vec3::Normalized(ray.direction()), rec.normal);
    scattered = Ray(rec.p, reflected + _fuzziness * Vec3::RandomInsideUnitSphere());
    attenuation = _albedo;
    return Vec3::Dot(scattered.direction(), rec.normal) > 0;
  }

private:
  /// @brief The albedo of the material.
  Color _albedo;
  /// @brief The fuzziness of the material.
  double _fuzziness;
};

}// namespace rt