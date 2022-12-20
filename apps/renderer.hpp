#pragma once

#include "image.hpp"

#include <rt/camera.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>

#include <execution>
#include <vector>

/// @brief Renders an image.
class Renderer final
{
public:
  /**
   * @brief Construct a new Renderer object.
   * @param image_width The width of the image to render.
   * @param image_height The height of the image to render.
   */
  [[nodiscard]] constexpr Renderer(const std::size_t image_width, const std::size_t image_height) noexcept
    : _image_width(image_width), _image_height(image_height)
  {}

  /**
   * @brief Renders the scene.
   * @param camera The camera to use.
   * @param scene The scene to render.
   * @return
   */
  [[nodiscard]] Image Render(const rt::Scene &scene, const rt::Camera &camera) const noexcept;

private:
  /**
   * @brief Computes the color of a ray.
   * @param ray The ray.
   * @param scene The scene.
   * @return
   */
  [[nodiscard]] static rt::Color RayColor(const rt::Scene &scene, const rt::Ray &ray) noexcept;

  /// @brief The width of the image.
  std::size_t _image_width;
  /// @brief The height of the image.
  std::size_t _image_height;
};
