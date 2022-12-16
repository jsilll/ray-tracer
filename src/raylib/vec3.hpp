#pragma once

#include <array>
#include <cmath>

class Vec3
{
public:
  Vec3() noexcept : e_{ 0 } {}

  Vec3(double e0, double e1, double e2) noexcept : e_{ e0, e1, e2 } {}

  double x() const noexcept { return e_[0]; }

  double y() const noexcept { return e_[1]; }

  double z() const noexcept { return e_[2]; }

  double &operator[](int i) noexcept { return e_[i]; }

  double operator[](int i) const noexcept { return e_[i]; }

  Vec3 operator-() const noexcept { return Vec3(-e_[0], -e_[1], -e_[2]); }

  Vec3 &operator+=(const Vec3 &v) noexcept
  {
    e_[0] += v.e_[0];
    e_[1] += v.e_[1];
    e_[2] += v.e_[2];
    return *this;
  }

  Vec3 &operator*=(const double t) noexcept
  {
    e_[0] *= t;
    e_[1] *= t;
    e_[2] *= t;
    return *this;
  }

  Vec3 &operator/=(const double t) noexcept { return *this *= 1 / t; }

  double Norm() const noexcept { return std::sqrt(NormSquared()); }

  Vec3 Normalized() const noexcept { return *this / Norm(); }

  double NormSquared() const noexcept { return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]; }

  double Dot(const Vec3 &v) const noexcept { return e_[0] * v.e_[0] + e_[1] * v.e_[1] + e_[2] * v.e_[2]; }

  Vec3 Cross(const Vec3 &v) const noexcept
  {
    return Vec3(
      e_[1] * v.e_[2] - e_[2] * v.e_[1], e_[2] * v.e_[0] - e_[0] * v.e_[2], e_[0] * v.e_[1] - e_[1] * v.e_[0]);
  }

  // --- Friend Functions --- //

  friend Vec3 operator+(const Vec3 &u, const Vec3 &v)
  {
    return Vec3(u.e_[0] + v.e_[0], u.e_[1] + v.e_[1], u.e_[2] + v.e_[2]);
  }

  friend Vec3 operator-(const Vec3 &u, const Vec3 &v)
  {
    return Vec3(u.e_[0] - v.e_[0], u.e_[1] - v.e_[1], u.e_[2] - v.e_[2]);
  }

  friend Vec3 operator*(const Vec3 &u, const Vec3 &v)
  {
    return Vec3(u.e_[0] * v.e_[0], u.e_[1] * v.e_[1], u.e_[2] * v.e_[2]);
  }

  friend Vec3 operator*(double t, const Vec3 &v) { return Vec3(t * v.e_[0], t * v.e_[1], t * v.e_[2]); }

  friend Vec3 operator*(const Vec3 &v, double t) { return t * v; }

  friend Vec3 operator/(const Vec3 &v, double t) { return (1 / t) * v; }

  friend std::ostream &operator<<(std::ostream &out, const Vec3 &v)
  {

    return out << "Vec3{" << v.e_[0] << ", " << v.e_[1] << ", " << v.e_[2] << "}";
  }

private:
  std::array<double, 3> e_;
};