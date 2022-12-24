#pragma once

#include <image.hpp>

#include <rt/camera.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>

#include <algorithm>
#include <execution>
#include <thread>
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
    const int samples_per_pixel,
    const rt::Scene &scene) noexcept
    : _image_width(image_width), _image_height(image_height), _samples_per_pixel(samples_per_pixel), _scene(scene)
  {}

  /**
   * @brief Renders the scene.
   * @param camera The camera to use.
   * @return
   */
  template<typename RenderFunc>
  [[nodiscard]] Image Render(const rt::Camera &camera, RenderFunc render_func) const noexcept
  {
    // Reserve memory for the image
    auto pixels = std::vector(_image_width, std::vector(_image_height, rt::Color(0, 0, 0)));

    // Pre-computing the max image width and height
    const auto width_max = static_cast<double>(_image_width - 1);
    const auto height_max = static_cast<double>(_image_height - 1);

    std::for_each(std::execution::par_unseq, std::begin(pixels), std::end(pixels), [&](auto &col) {
      const auto col_idx = &col - &pixels[0];
      std::for_each(std::execution::par_unseq, std::begin(col), std::end(col), [&](auto &row) {
        const auto row_idx = &row - &col[0];
        // Anti-aliasing
        for (int s = 0; s < _samples_per_pixel; ++s) {
          const auto u = (static_cast<double>(col_idx) + rt::utils::RandomDouble()) / width_max;
          const auto v = (static_cast<double>(row_idx) + rt::utils::RandomDouble()) / height_max;
          row += render_func(_scene, camera.Ray(u, v));
        }
        row /= static_cast<double>(_samples_per_pixel);
      });
    });

    // Pass the pixels to the image
    return Image(std::move(pixels));
  }

private:
  /// @brief The width of the image.
  std::size_t _image_width;
  /// @brief The height of the image.
  std::size_t _image_height;
  /// @brief The samples per pixel.
  int _samples_per_pixel;
  /// @brief The scene to render.
  const rt::Scene &_scene;
};
