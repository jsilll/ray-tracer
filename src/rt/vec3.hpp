#pragma once

#include <array>
#include <cmath>
#include <iostream>

namespace rt {

class Vec3 final
{
public:
  constexpr Vec3(double e0, double e1, double e2) noexcept : e_{ e0, e1, e2 } {}

  [[nodiscard]] constexpr auto x() const noexcept { return e_[0]; }

  [[nodiscard]] constexpr auto y() const noexcept { return e_[1]; }

  [[nodiscard]] constexpr auto z() const noexcept { return e_[2]; }

  [[nodiscard]] constexpr auto &operator[](std::size_t i) noexcept { return e_[i]; }

  [[nodiscard]] constexpr auto operator[](std::size_t i) const noexcept { return e_[i]; }

  [[nodiscard]] constexpr auto operator-() const noexcept { return Vec3(-e_[0], -e_[1], -e_[2]); }

  [[nodiscard]] constexpr auto &operator+=(const Vec3 &v) noexcept
  {
    e_[0] += v.e_[0];
    e_[1] += v.e_[1];
    e_[2] += v.e_[2];
    return *this;
  }

  [[nodiscard]] constexpr auto &operator*=(const double t) noexcept
  {
    e_[0] *= t;
    e_[1] *= t;
    e_[2] *= t;
    return *this;
  }

  [[nodiscard]] constexpr auto &operator/=(const double t) noexcept { return *this *= 1 / t; }

  [[nodiscard]] friend constexpr auto operator+(const Vec3 &u, const Vec3 &v)
  {
    return Vec3(u.e_[0] + v.e_[0], u.e_[1] + v.e_[1], u.e_[2] + v.e_[2]);
  }

  [[nodiscard]] friend constexpr auto operator-(const Vec3 &u, const Vec3 &v)
  {
    return Vec3(u.e_[0] - v.e_[0], u.e_[1] - v.e_[1], u.e_[2] - v.e_[2]);
  }

  [[nodiscard]] friend constexpr auto operator*(const Vec3 &u, const Vec3 &v)
  {
    return Vec3(u.e_[0] * v.e_[0], u.e_[1] * v.e_[1], u.e_[2] * v.e_[2]);
  }

  [[nodiscard]] friend constexpr auto operator*(double t, const Vec3 &v)
  {
    return Vec3(t * v.e_[0], t * v.e_[1], t * v.e_[2]);
  }

  [[nodiscard]] friend constexpr auto operator*(const Vec3 &v, double t) { return t * v; }

  [[nodiscard]] friend constexpr auto operator/(const Vec3 &v, double t) { return (1 / t) * v; }

  [[nodiscard]] friend auto &operator<<(std::ostream &out, const Vec3 &v)
  {
    return out << "Vec3{" << v.e_[0] << ", " << v.e_[1] << ", " << v.e_[2] << '}';
  }

  [[nodiscard]] constexpr auto NormSquared() const noexcept { return e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]; }

  [[nodiscard]] constexpr auto Norm() const noexcept { return std::sqrt(NormSquared()); }

  [[nodiscard]] constexpr auto Normalized() const noexcept { return *this / Norm(); }

  [[nodiscard]] constexpr auto Dot(const Vec3 &v) const noexcept
  {
    return e_[0] * v.e_[0] + e_[1] * v.e_[1] + e_[2] * v.e_[2];
  }

  [[nodiscard]] constexpr auto Cross(const Vec3 &v) const noexcept
  {
    return Vec3(
      e_[1] * v.e_[2] - e_[2] * v.e_[1], e_[2] * v.e_[0] - e_[0] * v.e_[2], e_[0] * v.e_[1] - e_[1] * v.e_[0]);
  }

private:
  std::array<double, 3> e_;
};

}// namespace rt