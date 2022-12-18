#pragma once

#include <rt/point.h>
#include <rt/primitives/surface.h>
#include <rt/ray.h>
#include <rt/vec3.h>

namespace rt {

/// @brief A sphere in 3D space.
class Sphere final : public Surface
{
public:
  /**
   * @brief Constructs a sphere with the given center and radius.
   * @param center The center of the sphere.
   * @param radius The radius of the sphere.
   */
  [[nodiscard]] constexpr Sphere(const Point &center, const float radius) noexcept : _center(center), _radius(radius) {}

  /**
   * @brief Returns the center of the sphere.
   * @return
   */
  [[nodiscard]] constexpr auto center() const noexcept { return _center; }

  /**
   * @brief Returns the radius of the sphere.
   * @return
   */
  [[nodiscard]] constexpr auto radius() const noexcept { return _radius; }

  /**
   * @brief Returns true the radius of the sphere squared.
   * @return
   */
  [[nodiscard]] constexpr auto Radius2() const noexcept { return _radius * _radius; }

  /**
   * @brief Returns whether the given ray intersects the sphere.
   * @param ray
   * @param t_min
   * @param t_max
   * @param rec
   * @return
   */
  bool Intersect(const Ray &ray, const float t_min, const float t_max, HitRecord &rec) const noexcept override
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
    rec.normal = (rec.p - _center) / _radius;
    return true;
  }

private:
  Point _center;
  float _radius;
};

}// namespace rt
