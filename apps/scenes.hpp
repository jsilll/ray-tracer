#pragma once

#include <rt/camera.hpp>
#include <rt/scene.hpp>

#include <utility>

namespace scenes {

/**
 * @brief Creates a scene with a single sphere and
 * another larger sphere as ground for casting shadows.
 * @param aspect_ratio The aspect ratio of the camera.
 * @return
 */
[[nodiscard]] std::pair<rt::Scene, rt::Camera> Default(double aspect_ratio) noexcept;

/**
 * @brief Creates a scene with three spheres.
 * @param aspect_ratio The aspect ratio of the camera.
 * @return
 */
[[nodiscard]] std::pair<rt::Scene, rt::Camera> MetalSpheres(double aspect_ratio) noexcept;

}// namespace scenes