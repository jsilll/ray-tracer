#pragma once

#include <rt/color.hpp>
#include <rt/materials/material.hpp>
#include <rt/ray.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>

/// @brief Aggregates the rendering utilities for the library.
namespace rt::rendering {

/**
 * @brief Computes the color of a ray of light.
 * @param scene The scene to render.
 * @param ray The ray to render.
 * @return
 */
[[nodiscard]] rt::Color RenderBeauty(const rt::Scene &scene, const rt::Ray &ray, int bounces) noexcept
{
  if (bounces <= 0) return { 0, 0, 0 };

  rt::HitRecord rec;
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    // Objects
    Color attenuation({ 0, 0, 0 });
    Ray scattered({ 0, 0, 0 }, { 0, 0, 0 });
    if (rec.material->Scatter(ray, rec, attenuation, scattered)) {
      return attenuation * RenderBeauty(scene, scattered, bounces - 1);
    } else {
      return { 0, 0, 0 };
    }
  } else {
    // Sky
    const auto unit_direction = Vec3::Normalized(ray.direction());
    const auto t = 0.5 * (unit_direction.y() + 1);
    return (1 - t) * rt::Color(1, 1, 1) + t * rt::Color(0.5, 0.7, 1);
  }
}

/**
 * @brief Computes the color according to the depth at the ray intersection.
 * @param scene The scene to render.
 * @param ray The ray to render.
 * @return
 */
[[nodiscard]] rt::Color RenderDepth(const rt::Scene &scene, const rt::Ray &ray, const double max_depth) noexcept
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    const double t = std::min(1.0, rec.t / max_depth);
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
[[nodiscard]] rt::Color RenderNormal(const rt::Scene &scene, const rt::Ray &ray) noexcept
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    return rt::color::FromNormal(rec.normal);
  } else {
    return { 0, 0, 0 };
  }
}

}// namespace rt::rendering