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
   * @param e0 The x component.
   * @param e1 The y component.
   * @param e2 The z component.
   */
  [[nodiscard]] constexpr Vec3(T x, T y, T z) noexcept : _e{ x, y, z } {}

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
   * @brief Returns the length of the vector.
   * @return
   */
  [[nodiscard]] constexpr auto operator-() const noexcept { return Vec3(-_e[0], -_e[1], -_e[2]); }

  /**
   * @brief Returns the squared length of the vector.
   * @param v
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
   * @brief Returns the squared length of the vector.
   * @param v
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
   * @param t
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
   * @param t
   * @return
   */
  constexpr auto &operator/=(const T t) noexcept { return *this *= 1 / t; }

  /**
   * @brief Returns the length of the vector.
   * @param v
   * @return
   */
  constexpr auto operator==(const Vec3 &v) const noexcept
  {
    return _e[0] == v._e[0] && _e[1] == v._e[1] && _e[2] == v._e[2];
  }

  /**
   * @brief Returns the length of the vector.
   * @param u
   * @param v
   * @return
   */
  [[nodiscard]] friend constexpr auto operator+(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._e[0] + v._e[0], u._e[1] + v._e[1], u._e[2] + v._e[2]);
  }

  /**
   * @brief Subtracts two vectors.
   * @param u
   * @param v
   * @return
   */
  [[nodiscard]] friend constexpr auto operator-(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._e[0] - v._e[0], u._e[1] - v._e[1], u._e[2] - v._e[2]);
  }

  /**
   * @brief Dot product.
   * @param u
   * @param v
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const Vec3 &u, const Vec3 &v) noexcept
  {
    return Vec3(u._e[0] * v._e[0], u._e[1] * v._e[1], u._e[2] * v._e[2]);
  }

  /**
   * @brief Dot product.
   * @param t
   * @param v
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(T t, const Vec3 &v) noexcept
  {
    return Vec3(t * v._e[0], t * v._e[1], t * v._e[2]);
  }

  /**
   * @brief Dot product of two vectors.
   * @param v
   * @param t
   * @return
   */
  [[nodiscard]] friend constexpr auto operator*(const Vec3 &v, T t) noexcept { return t * v; }

  /**
   * @brief Dot product.
   * @param v
   * @param t
   * @return
   */
  [[nodiscard]] friend constexpr auto operator/(const Vec3 &v, T t) noexcept { return (1 / t) * v; }

  /**
   * @brief Dot product of two vectors.
   * @return
   */
  [[nodiscard]] constexpr auto NormSquared() const noexcept { return _e[0] * _e[0] + _e[1] * _e[1] + _e[2] * _e[2]; }

  /**
   * @brief Returns the length of the vector.
   * @return
   */
  [[nodiscard]] constexpr auto Norm() const noexcept { return std::sqrt(NormSquared()); }

  /**
   * @brief Returns a unit vector in the same direction as this vector.
   * @return
   */
  [[nodiscard]] constexpr auto Normalized() const noexcept { return *this / Norm(); }

  /**
   * @brief Dot product.
   * @param v
   * @return
   */
  [[nodiscard]] constexpr auto Dot(const Vec3 &v) const noexcept
  {
    return _e[0] * v._e[0] + _e[1] * v._e[1] + _e[2] * v._e[2];
  }

  /**
   * @brief Cross product of two vectors.
   * @param v
   * @return
   */
  [[nodiscard]] constexpr auto Cross(const Vec3 &v) const noexcept
  {
    return Vec3(
      _e[1] * v._e[2] - _e[2] * v._e[1], _e[2] * v._e[0] - _e[0] * v._e[2], _e[0] * v._e[1] - _e[1] * v._e[0]);
  }

  /**
   * @brief Returns a Vec3 with the same direction as this Vec3, but with a norm of 1.
   * @param out
   * @param v
   * @return
   */
  friend auto &operator<<(std::ostream &out, const Vec3 &v) noexcept
  {
    return out << "Vec3{" << v._e[0] << ", " << v._e[1] << ", " << v._e[2] << '}';
  }

private:
  T _e[3];
};

/// @brief Type alias for Vec3<float>.
using Vec3f = Vec3<float>;

}// namespace rt