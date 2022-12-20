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
   * @param cam The camera to use.
   * @param scene The scene to render.
   * @return
   */
  [[nodiscard]] Image Render(const rt::Camera &cam, const rt::Scene &scene) const noexcept
  {
    constexpr rt::Point origin(0, 0, 0);

    // TODO: Get these  from the camera.
    const rt::Vec3f vertical(0, cam.viewport_height(), 0);
    const rt::Vec3f horizontal(cam.viewport_width(), 0, 0);
    const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - rt::Vec3f(0, 0, cam.focal_length());

    std::vector<std::vector<rt::Color>> pixels(_image_width, std::vector<rt::Color>(_image_height, { 0, 0, 0 }));

    // TODO: Find a better way to do this
    // Computing the ray direction for each pixel
    for (std::size_t i = 0; i < _image_width; ++i) {
      for (std::size_t j = 0; j < _image_height; ++j) {
        const auto u = static_cast<float>(i) / (static_cast<float>(_image_width - 1));
        const auto v = static_cast<float>(j) / (static_cast<float>(_image_height - 1));
        pixels[i][j] = lower_left_corner + u * horizontal + v * vertical - origin;
      }
    }

    std::for_each(std::execution::par_unseq, pixels.begin(), pixels.end(), [&](auto &row) {
      std::for_each(std::execution::par_unseq, row.begin(), row.end(), [&](auto &pixel) {
        // Computing the color of the pixel
        // @note: Each pixel already has a ray direction in it.
        pixel = RayColor(rt::Ray(origin, pixel), scene);
      });
    });

    return Image(std::move(pixels));
  }

private:
  /**
   * @brief Computes the color of a ray.
   * @param ray The ray.
   * @param scene The scene.
   * @return
   */
  [[nodiscard]] static rt::Color RayColor(const rt::Ray &ray, const rt::Scene &scene)
  {
    rt::HitRecord rec;
    if (scene.Intersect(ray, 0, rt::utils::kInf, rec)) { return 0.5 * (rec.normal + rt::Color(1, 1, 1)); }
    rt::Vec3f unit_direction = ray.direction().Normalized();
    const auto t = 0.5f * (unit_direction.y() + 1.0f);
    return (1.0f - t) * rt::Color(1.0, 1.0, 1.0) + t * rt::Color(0.5, 0.7f, 1.0);
  }

  /// @brief The width of the image.
  std::size_t _image_width;
  /// @brief The height of the image.
  std::size_t _image_height;
};
