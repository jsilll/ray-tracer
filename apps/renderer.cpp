#include "renderer.hpp"

#include <rt/color.hpp>
#include <rt/ray.hpp>
#include <rt/rendering.hpp>

Image Renderer::Render(const rt::Camera &camera) const noexcept
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
      return rt::RenderDepth(_scene, rt::Ray(camera.position(), direction));
    });
    return col;
  });

  return Image(std::move(pixels));
}
