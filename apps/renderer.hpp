#pragma once

#include "image.hpp"

#include <rt/camera.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>

#include <algorithm>
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
  [[nodiscard]] constexpr Renderer(const std::size_t image_width,
    const std::size_t image_height,
    const rt::Scene &scene) noexcept
    : _image_width(image_width), _image_height(image_height), _scene(scene)
  {}

  /**
   * @brief Renders the scene.
   * @param camera The camera to use.
   * @return
   */
  template<typename RenderFunc>
  [[nodiscard]] Image Render(const rt::Camera &camera, RenderFunc render_func) const noexcept
  {
    const auto vertical = camera.vertical();
    const auto horizontal = camera.horizontal();
    const auto width_max = static_cast<float>(_image_width - 1);
    const auto height_max = static_cast<float>(_image_height - 1);
    const auto direction_offset = camera.lower_left_ray();
    auto pixels = std::vector(_image_width, std::vector<rt::Color>(_image_height, { 0, 0, 0 }));

    std::transform(std::execution::par_unseq, pixels.begin(), pixels.end(), pixels.begin(), [&](auto &col) {
      const auto i = std::distance(pixels.data(), &col);
      std::transform(std::execution::par_unseq, col.begin(), col.end(), col.begin(), [&](auto &pixel) {
        const auto j = std::distance(col.data(), &pixel);
        const auto h = static_cast<float>(i) / width_max;
        const auto v = static_cast<float>(j) / height_max;
        const auto direction = h * horizontal + v * vertical + direction_offset;
        const auto ray = rt::Ray(camera.position(), direction);
        return render_func(_scene, ray);
      });
      return col;
    });

    return Image(std::move(pixels));
  }


private:
  /// @brief The width of the image.
  std::size_t _image_width;
  /// @brief The height of the image.
  std::size_t _image_height;
  /// @brief The scene to render.
  const rt::Scene &_scene;
};
