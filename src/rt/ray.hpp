#pragma once

#include "point.hpp"
#include "vec3.hpp"

namespace rt {

class Ray final
{
public:
  constexpr Ray(const Point3 &origin, const Vec3 &direction) : origin_(origin), direction_(direction) {}

  [[nodiscard]] constexpr auto origin() const noexcept { return origin_; }

  [[nodiscard]] constexpr auto direction() const noexcept { return direction_; }

  [[nodiscard]] constexpr auto At(double t) const noexcept { return origin_ + t * direction_; }

private:
  Point3 origin_;
  Vec3 direction_;
};

}// namespace rt