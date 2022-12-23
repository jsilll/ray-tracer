#include <rt/primitives/sphere.hpp>

namespace rt {

bool Sphere::Intersect(const Ray &ray, const double t_min, const double t_max, HitRecord &rec) const noexcept
{
  const auto oc = ray.origin() - _center;
  const auto a = ray.direction().NormSquared();
  const auto half_b = oc.Dot(ray.direction());
  const auto c = oc.NormSquared() - Radius2();
  const auto discriminant = half_b * half_b - a * c;

  if (discriminant < 0) return false;

  const auto discriminant_square_root = std::sqrt(discriminant);
  auto root = (-half_b - discriminant_square_root) / a;
  if (root < t_min || t_max < root) {
    root = (-half_b + discriminant_square_root) / a;
    if (root < t_min || t_max < root) return false;
  }

  rec.t = root;
  rec.p = ray.At(rec.t);
  rec.SetFaceNormal(ray, (rec.p - _center) / _radius);

  return true;
}

}// namespace rt