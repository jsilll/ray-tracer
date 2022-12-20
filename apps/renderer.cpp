#include "renderer.hpp"

Image Renderer::Render(const rt::Scene &scene, const rt::Camera &camera) const noexcept
{
  constexpr rt::Point origin(0, 0, 0);
  std::vector<std::vector<rt::Color>> pixels(_image_width, std::vector<rt::Color>(_image_height, { 0, 0, 0 }));

  // TODO: Get these directly from the camera.
  const rt::Vec3f vertical(0, camera.viewport_height(), 0);
  const rt::Vec3f horizontal(camera.viewport_width(), 0, 0);
  const auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - rt::Vec3f(0, 0, camera.focal_length());

  // Filling each pixel with its corresponding ray direction.
  for (std::size_t i = 0; i < _image_width; ++i) {
    for (std::size_t j = 0; j < _image_height; ++j) {
      const auto u = static_cast<float>(i) / (static_cast<float>(_image_width - 1));
      const auto v = static_cast<float>(j) / (static_cast<float>(_image_height - 1));
      pixels[i][j] = lower_left_corner + u * horizontal + v * vertical - origin;
    }
  }

  // Rendering the image
  std::for_each(std::execution::par_unseq, pixels.begin(), pixels.end(), [&](auto &row) {
    std::for_each(std::execution::par_unseq, row.begin(), row.end(), [&](auto &pixel) {
      // Computing the color of the pixel
      // @note: Hack: each pixel already has a ray direction stored in it
      pixel = RayColor(rt::Ray(origin, pixel), scene);
    });
  });

  return Image(std::move(pixels));
}

rt::Color Renderer::RayColor(const rt::Ray &ray, const rt::Scene &scene) noexcept
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0, rt::utils::kInf, rec)) {
    return rt::color::FromNormal(rec.normal);
  } else {
    return { 0, 0, 0 };
  }
  // rt::Vec3f unit_direction = ray.direction().Normalized();
  // const auto t = 0.5f * (unit_direction.y() + 1.0f);
  // return (1.0f - t) * rt::Color(1.0, 1.0, 1.0) + t * rt::Color(0.5, 0.7f, 1.0);
}