#include "renderer.hpp"

#include <iterator>

Image Renderer::Render(const rt::Scene &scene, const rt::Camera &camera) const noexcept
{
  // TODO: Get these directly from the camera.
  const rt::Vec3f vertical(0, camera.viewport_height(), 0);
  const rt::Vec3f horizontal(camera.viewport_width(), 0, 0);
  const auto lower_left_corner = camera.position() - horizontal / 2 - vertical / 2 - rt::Vec3f(0, 0, camera.focal_length());

  // Creating a 2D array of pixels
  auto pixels = std::vector(_image_width, std::vector<rt::Color>(_image_height, { 0, 0, 0 }));

  // Rendering the image
  const float width_max = static_cast<float>(_image_width - 1);
  const float height_max = static_cast<float>(_image_height - 1);
  const auto direction_offset = lower_left_corner - camera.position();
  std::transform(std::execution::par_unseq, pixels.begin(), pixels.end(), pixels.begin(), [&](auto &col) {
    const auto i = std::distance(pixels.data(), &col);
    std::transform(std::execution::par_unseq, col.begin(), col.end(), col.begin(), [&](auto &pixel) {
      const auto j = std::distance(col.data(), &pixel);
      const auto h = static_cast<float>(i) / width_max;
      const auto v = static_cast<float>(j) / height_max;
      const auto direction = h * horizontal + v * vertical + direction_offset;
      return RayColor(scene, rt::Ray(camera.position(), direction));
    });
    return col;
  });

  // Returning the image
  return Image(std::move(pixels));
}

rt::Color Renderer::RayColor(const rt::Scene &scene, const rt::Ray &ray) noexcept
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0, rt::utils::kInf, rec)) {
    return rt::color::FromNormal(rec.normal);
  } else {
    rt::Vec3f unit_direction = ray.direction().Normalized();
    const auto t = 0.5f * (unit_direction.y() + 1.0f);
    return (1.0f - t) * rt::Color(1.0, 1.0, 1.0) + t * rt::Color(0.5, 0.7f, 1.0);
  }
}