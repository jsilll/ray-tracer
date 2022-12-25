#include <rt/materials/metal.hpp>

namespace rt {

bool Metal::Scatter(const Ray &ray, const HitRecord &rec, Color &attenuation, Ray &scattered) const noexcept
{
  const auto reflected = Vec3::Reflect(Vec3::Normalized(ray.direction()), rec.normal);
  scattered = Ray(rec.p, reflected + _fuzziness * Vec3::RandomInsideUnitSphere());
  attenuation = _albedo;
  return Vec3::Dot(scattered.direction(), rec.normal) > 0;
}

}// namespace rt