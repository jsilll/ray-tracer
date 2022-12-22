#include <rt/color.hpp>
#include <rt/ray.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>

/// @brief Aggregates the rendering utilities for the library.
namespace rt::rendering {

/**
 * @brief Computes the color according to the depth at the ray intersection.
 * @param scene The scene to render.
 * @param ray The ray to render.
 * @return
 */
rt::Color RenderDepthMap(const rt::Scene &scene, const rt::Ray &ray, const float max_depth) noexcept //TODO: add tests
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0, rt::utils::kInf, rec)) {
    const float t = std::min(1.f, rec.t / max_depth);
    return { 1 - t, 1 - t, 1 - t };
  } else {
    return { 0, 0, 0 };
  }
}

/**
 * @brief Computes the color according to the normal at the ray intersection.
 * @param scene The scene to render.
 * @param ray The ray to render.
 * @return
 */
rt::Color RenderNormalMap(const rt::Scene &scene, const rt::Ray &ray) noexcept //TODO: add tests and add this somewhere in the code
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0, rt::utils::kInf, rec)) {
    return rt::color::FromNormal(rec.normal);
  } else {
    return { 0, 0, 0 };
  }
}

}// namespace rt