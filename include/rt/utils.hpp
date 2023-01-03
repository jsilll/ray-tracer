#pragma once

#include <cmath>
#include <limits>
#include <random>

/// @brief Aggregates the parameters general utilities for the library.
namespace rt::utils {

/// @brief Pi constant.
constexpr double kPi = 3.1415926535897932385f;

/// @brief Infinity constant.
constexpr auto kInf = std::numeric_limits<double>::infinity();

/**
 * @brief Converts degrees to radians.
 * @param degrees The degrees to convert.
 * @return
 */
[[nodiscard]] inline constexpr double DegreesToRadians(double degrees) { return degrees * kPi / 180; }

/**
 * @brief Clamps a value between a minimum and a maximum.
 * @param x The value to clamp.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return
 */
[[nodiscard]] inline constexpr double Clamp(double x, double min, double max)
{
  if (x < min) {
    return min;
  } else if (x > max) {
    return max;
  } else {
    return x;
  }
}

/**
 * @brief Generates a random double in the range [0, 1).
 * @return
 */
[[nodiscard]] inline double RandomDouble() noexcept
{
  static std::random_device rd;
  static std::mt19937 generator(rd());
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(generator);
}

}// namespace rt::utils