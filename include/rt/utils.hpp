#pragma once

#include <cmath>
#include <limits>

namespace rt::utils {

/// @brief Pi constant.
constexpr float kPi = 3.1415926535897932385f;

/// @brief Infinity constant.
constexpr auto kInf = std::numeric_limits<float>::infinity();

/**
 * @brief Converts degrees to radians.
 * @param degrees
 * @return
 */
constexpr float DegreesToRadians(float degrees) { return degrees * kPi / 180.f; }

}// namespace rt::utils