#pragma once

#include <rt/vec3.hpp>

#include <cmath>
#include <limits>
#include <random>

/// @brief Aggregates the parameters general utilities for the library.
namespace rt::utils {

/// @brief Pi constant.
constexpr float kPi = 3.1415926535897932385f;

/// @brief Infinity constant.
constexpr auto kInf = std::numeric_limits<float>::infinity();

/**
 * @brief Converts degrees to radians.
 * @param degrees The degrees to convert.
 * @return
 */
inline constexpr float DegreesToRadians(float degrees) { return degrees * kPi / 180.f; }
// TODO: add tests

/**
 * @brief Clamps a value between a minimum and a maximum.
 * @param x The value to clamp.
 * @param min The minimum value.
 * @param max The maximum value.
 * @return
 */
inline constexpr float Clamp(float x, float min, float max)
{
  // TODO: add tests
  if (x < min) return min;
  if (x > max) return max;
  return x;
}

/**
 * @brief Generates a random float in the range [0, 1).
 * @return
 */
inline float RandomFloat() noexcept
{
  // TODO: add tests
  static std::random_device rd;
  static std::mt19937 generator(rd());
  static std::uniform_real_distribution<float> distribution(0.0f, 1.0f);
  return distribution(generator);
}

}// namespace rt::utils