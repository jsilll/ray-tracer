#pragma once

#include <image.hpp>
#include <thread_pool.hpp>

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
  [[nodiscard]] Image Render(const rt::Camera &camera, RenderFunc render_func, unsigned int threads) const noexcept
  {
    auto pixels = std::vector(_image_width, std::vector(_image_height, rt::Color(0, 0, 0)));

    const auto width_max = static_cast<float>(_image_width - 1);
    const auto height_max = static_cast<float>(_image_height - 1);

    ThreadPool pool{ threads };
    std::vector<std::future<void>> futures;
    for (std::size_t col = 0; col < _image_width; ++col) {
      futures.emplace_back(pool.enqueue([&, col] {
        for (std::size_t row = 0; row < _image_height; ++row) {
          for (int s = 0; s < _samples_per_pixel; ++s) {
            const auto u = (static_cast<float>(col) + rt::utils::RandomFloat()) / width_max;
            const auto v = (static_cast<float>(row) + rt::utils::RandomFloat()) / height_max;
            pixels[col][row] += render_func(_scene, camera.Ray(u, v));
          }
          pixels[col][row] /= static_cast<float>(_samples_per_pixel);
        }
      }));
    }

    for (auto &future : futures) { future.get(); }

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
