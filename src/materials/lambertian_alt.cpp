#include <rt/materials/lambertian_alt.hpp>

namespace rt {

bool LambertianAlt::Scatter([[maybe_unused]] const Ray &ray,
  const HitRecord &rec,
  Color &attenuation,
  Ray &scattered) const noexcept
{
  attenuation = _albedo;
  scattered = Ray(rec.p, Vec3::RandomInHemisphere(rec.normal));
  return true;
}

}// namespace rt