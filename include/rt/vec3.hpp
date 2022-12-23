#pragma once

#include <rt/utils.hpp>

#include <cmath>
#include <iostream>
#include <type_traits>

namespace rt {

/// @brief A 3D vector.
class Vec3
{
public:
  /**
   * @brief Constructs a vector with the given x, y, and z components.
   * @param x The x component.
   * @param y The y component.
   * @param z The z component.
   */
  [[nodiscard]] constexpr Vec3(const double x, const double y, const double z) noexcept : _x(x), _y(y), _z(z) {}

  /**
   * @brief Returns the x component of this vector.
   * @return
   */
  [[nodiscard]] constexpr auto x() const noexcept { return _x; }

  /**
   * @brief Returns the y coordinate of this vector.
   * @return
   */
  [[nodiscard]] constexpr auto y() const noexcept { return _y; }

  /**
   * @brief Returns the z coordinate of the vector.
   * @return
   */
  [[nodiscard]] constexpr auto z() const noexcept { return _z; }

  /**
   * @brief Negates this vector.
   * @return
   */
  [[nodiscard]] constexpr auto operator-() const noexcept { return Vec3(-_x, -_y, -_z); }

  /**
   * @brief Sums this vector with the given vector.
   * @param v The vector.
   * @return
   */
  constexpr auto &operator+=(const Vec3 &v) noexcept
  {
    _x += v._x;
    _y += v._y;
    _z += v._z;
    return *this;
  }

  /**
   * @brief Subtracts the given vector from this vector.
   * @param v The vector.
   * @return
   */
  constexpr auto &operator-=(const Vec3 &v) noexcept
  {
    _x -= v._x;
    _y -= v._y;
    _z -= v._z;
    return *this;
  }

  /**
   * @brief Multiply this vector by a scalar.
   * @param t The scalar.
   * @return
   */
  constexpr auto &operator*=(const double t) noexcept
  {
    _x *= t;
    _y *= t;
    _z *= t;
    return *this;
  }

  /**
   * @brief Divide each component of the vector by the given scalar.
   * @param t The scalar.
   * @return
   */
  constexpr auto &operator/=(const double t) noexcept { return *this *= 1 / t; }

  /**
   * @brief Returns whether this vector is equal to the given vector.
   * @param v The vector.
   * @return
   */
  [[nodiscard]] constexpr auto operator==(const Vec3 &v) const noexcept
  {
    return _x == v._x && _y == v._y && _z == v._z;
  }

  /**
   * @brief Returns the sum of this vector with a scalar.
   * @param u The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator+(const Vec3 &u, const double t) noexcept
  {
    return Vec3(u._x + t, u._y + t, u._z + t);
  }

  /**
   * @brief Returns the subtraction of this vector with a scalar.
   * @param u The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator-(const Vec3 &u, const double t) noexcept
  {
    return Vec3(u._x - t, u._y - t, u._z - t);
  }

  /**
   * @brief Sums two vectors.
   * @param u The first vector.
   * @param v The second vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator+(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._x + v._x, u._y + v._y, u._z + v._z);
  }

  /**
   * @brief Subtracts two vectors.
   * @param u The first vector.
   * @param v The second vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator-(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._x - v._x, u._y - v._y, u._z - v._z);
  }

  /**
   * @brief Element-wise multiplication of two vectors.
   * @param u The first vector.
   * @param v The second vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._x * v._x, u._y * v._y, u._z * v._z);
  }

  /**
   * @brief Multiplies a vector by a scalar.
   * @param t The scalar.
   * @param v The vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const double t, const Vec3 &v) noexcept
  {
    return Vec3(t * v._x, t * v._y, t * v._z);
  }

  /**
   * @brief Multiplies a vector by a scalar.
   * @param v The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const Vec3 &v, const double t) noexcept { return t * v; }

  /**
   * @brief Divides a vector by a scalar.
   * @param v The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator/(const Vec3 &v, const double t) noexcept { return (1 / t) * v; }

  /**
   * @brief Returns the norm of the vector squared.
   * @return
   */
  [[nodiscard]] constexpr auto NormSquared() const noexcept { return _x * _x + _y * _y + _z * _z; }

  /**
   * @brief Returns the norm of the vector.
   * @return
   */
  [[nodiscard]] constexpr auto Norm() const noexcept { return std::sqrt(NormSquared()); }

  /**
   * @brief Returns a unit vector in the same direction as this vector.
   * @return
   */
  [[nodiscard]] constexpr auto Normalized() const noexcept { return *this / Norm(); }

  /**
   * @brief Returns the dot product of two vectors.
   * @param v The vector.
   * @return
   */
  [[nodiscard]] constexpr auto Dot(const Vec3 &v) const noexcept { return _x * v._x + _y * v._y + _z * v._z; }

  /**
   * @brief Cross product of two vectors.
   * @param v The vector.
   * @return
   */
  [[nodiscard]] constexpr auto Cross(const Vec3 &v) const noexcept
  {
    return Vec3(_y * v._z - _z * v._y, _z * v._x - _x * v._z, _x * v._y - _y * v._x);
  }

  /**
   * @brief Returns a Vec3 with the same direction as this Vec3, but with a norm of 1.
   * @param out The output stream.
   * @param v The vector.
   * @return
   */
  friend auto &operator<<(std::ostream &out, const Vec3 &v) noexcept
  {
    return out << "Vec3{" << v._x << ", " << v._y << ", " << v._z << '}';
  }

  /**
   * @brief Returns a random vector in the unit sphere.
   * @return
   */
  [[nodiscard]] static Vec3 RandomInUnitSphere() noexcept
  {
    return 2 * Vec3(utils::RandomDouble(), utils::RandomDouble(), utils::RandomDouble()) - 1;
  }

  /**
   * @brief Returns a random vector within unit sphere.
   * @return
   */
  [[nodiscard]] static Vec3 RandomWithinUnitSphere() noexcept
  {
    while (true) {
      auto p = 2 * Vec3(utils::RandomDouble(), utils::RandomDouble(), utils::RandomDouble()) - 1;
      if (p.NormSquared() < 1) { return p; }
    }
  }

  /**
   * @brief Returns a random vector within the same hemisphere as the normal.
   * @param normal The normal vector.
   * @return
   */
  [[nodiscard]] static Vec3 RandomInHemisphere(const Vec3 &normal) noexcept
  {
    Vec3 in_unit_sphere = RandomInUnitSphere();
    if (in_unit_sphere.Dot(normal) > 0.0)// In the same hemisphere as the normal
      return in_unit_sphere;
    else
      return -in_unit_sphere;
  }

protected:
  /// @brief The x component of the vector.
  double _x;
  /// @brief The y component of the vector.
  double _y;
  /// @brief The z component of the vector.
  double _z;
};

}// namespace rt