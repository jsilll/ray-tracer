#pragma once

#include <cmath>
#include <iostream>
#include <type_traits>

namespace rt {

/// @brief A 3D vector.
template<typename T> class Vec3 final
{
  static_assert(std::is_arithmetic<T>::value, "Vec3 class template only accepts arithmetic types.");

public:
  /**
   * @brief Constructs a vector with the given x, y, and z components.
   * @param x The x component.
   * @param y The y component.
   * @param z The z component.
   */
  [[nodiscard]] constexpr Vec3(const T x, const T y, const T z) noexcept : _e{ x, y, z } {}

  /**
   * @brief Returns the x component of this vector.
   * @return
   */
  [[nodiscard]] constexpr auto x() const noexcept { return _e[0]; }

  /**
   * @brief Returns the y coordinate of this vector.
   * @return
   */
  [[nodiscard]] constexpr auto y() const noexcept { return _e[1]; }

  /**
   * @brief Returns the z coordinate of the vector.
   * @return
   */
  [[nodiscard]] constexpr auto z() const noexcept { return _e[2]; }

  /**
   * @brief Negates this vector.
   * @return
   */
  [[nodiscard]] constexpr auto operator-() const noexcept { return Vec3(-_e[0], -_e[1], -_e[2]); }

  /**
   * @brief Sums this vector with the given vector.
   * @param v The vector.
   * @return
   */
  constexpr auto &operator+=(const Vec3 &v) noexcept
  {
    _e[0] += v._e[0];
    _e[1] += v._e[1];
    _e[2] += v._e[2];
    return *this;
  }

  /**
   * @brief Subtracts the given vector from this vector.
   * @param v The vector.
   * @return
   */
  constexpr auto &operator-=(const Vec3 &v) noexcept
  {
    _e[0] -= v._e[0];
    _e[1] -= v._e[1];
    _e[2] -= v._e[2];
    return *this;
  }

  /**
   * @brief Multiply this vector by a scalar.
   * @param t The scalar.
   * @return
   */
  constexpr auto &operator*=(const T t) noexcept
  {
    _e[0] *= t;
    _e[1] *= t;
    _e[2] *= t;
    return *this;
  }

  /**
   * @brief Divide each component of the vector by the given scalar.
   * @param t The scalar.
   * @return
   */
  constexpr auto &operator/=(const T t) noexcept { return *this *= 1 / t; }

  /**
   * @brief Returns whether this vector is equal to the given vector.
   * @param v The vector.
   * @return
   */
  constexpr auto operator==(const Vec3 &v) const noexcept
  {
    return _e[0] == v._e[0] && _e[1] == v._e[1] && _e[2] == v._e[2];
  }

  /**
   * @brief Returns the sum of this vector with a scalar.
   * @param u The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator+(const Vec3 &u, const T t) noexcept
  {
    return Vec3(u._e[0] + t, u._e[1] + t, u._e[2] + t);
  }

  /**
   * @brief Sums two vectors.
   * @param u The first vector.
   * @param v The second vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator+(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._e[0] + v._e[0], u._e[1] + v._e[1], u._e[2] + v._e[2]);
  }

  /**
   * @brief Subtracts two vectors.
   * @param u The first vector.
   * @param v The second vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator-(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._e[0] - v._e[0], u._e[1] - v._e[1], u._e[2] - v._e[2]);
  }

  /**
   * @brief Element-wise multiplication of two vectors.
   * @param u The first vector.
   * @param v The second vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._e[0] * v._e[0], u._e[1] * v._e[1], u._e[2] * v._e[2]);
  }

  /**
   * @brief Multiplies a vector by a scalar.
   * @param t The scalar.
   * @param v The vector.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const T t, const Vec3 &v) noexcept
  {
    return Vec3(t * v._e[0], t * v._e[1], t * v._e[2]);
  }

  /**
   * @brief Multiplies a vector by a scalar.
   * @param v The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const Vec3 &v, const T t) noexcept { return t * v; }

  /**
   * @brief Divides a vector by a scalar.
   * @param v The vector.
   * @param t The scalar.
   * @return
   */
  [[nodiscard]] friend constexpr auto operator/(const Vec3 &v, const T t) noexcept { return (1 / t) * v; }

  /**
   * @brief Returns the norm of the vector squared.
   * @return
   */
  [[nodiscard]] constexpr auto NormSquared() const noexcept { return _e[0] * _e[0] + _e[1] * _e[1] + _e[2] * _e[2]; }

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
  [[nodiscard]] constexpr auto Dot(const Vec3 &v) const noexcept
  {
    return _e[0] * v._e[0] + _e[1] * v._e[1] + _e[2] * v._e[2];
  }

  /**
   * @brief Cross product of two vectors.
   * @param v The vector.
   * @return
   */
  [[nodiscard]] constexpr auto Cross(const Vec3 &v) const noexcept
  {
    return Vec3(
      _e[1] * v._e[2] - _e[2] * v._e[1], _e[2] * v._e[0] - _e[0] * v._e[2], _e[0] * v._e[1] - _e[1] * v._e[0]);
  }

  /**
   * @brief Returns a Vec3 with the same direction as this Vec3, but with a norm of 1.
   * @param out The output stream.
   * @param v The vector.
   * @return
   */
  friend auto &operator<<(std::ostream &out, const Vec3 &v) noexcept
  {
    return out << "Vec3{" << v._e[0] << ", " << v._e[1] << ", " << v._e[2] << '}';
  }

private:
  /// @brief The components of the vector.
  T _e[3];
};

/// @brief Type alias for Vec3<float>.
using Vec3f = Vec3<float>;

}// namespace rt