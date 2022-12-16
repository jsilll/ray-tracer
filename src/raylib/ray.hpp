#pragma once

#include "point3.hpp"
#include "vec3.hpp"

class Ray
{
public:
  Ray() {}

  Ray(const Point3 &origin, const Vec3 &direction) : origin_(origin), direction_(direction) {}

  Point3 origin() const noexcept { return origin_; }

  Vec3 direction() const noexcept { return direction_; }

  Point3 at(double t) const noexcept { return origin_ + (t * direction_); }

public:
  Point3 origin_;
  Vec3 direction_;
};