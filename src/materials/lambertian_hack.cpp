#include <rt/materials/lambertian_hack.hpp>

namespace rt {

bool LambertianHack::Scatter([[maybe_unused]] const Ray &ray,
  const HitRecord &rec,
  Color &attenuation,
  Ray &scattered) const noexcept
{
  attenuation = _albedo;
  const auto scatter_direction = rec.normal + Vec3::RandomInsideUnitSphere();
  scattered = scatter_direction.NearZero() ? Ray(rec.p, rec.normal) : Ray(rec.p, scatter_direction);
  return true;
}

}// namespace rt