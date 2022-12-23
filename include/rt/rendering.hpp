#include <rt/color.hpp>
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
rt::Color RenderBeautyLambertianHack(const rt::Scene &scene, const rt::Ray &ray, int bounces) noexcept
{
  rt::HitRecord rec;
  if (bounces <= 0) return { 0, 0, 0 };
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    Point target = rec.p + rec.normal + Vec3::RandomWithinUnitSphere();
    return 0.5 * RenderBeautyLambertianHack(scene, { rec.p, target - rec.p }, bounces - 1);
  } else {
    const auto unit_direction = ray.direction().Normalized();
    const auto t = 0.5 * (unit_direction.y() + 1);
    return (1 - t) * rt::Color(1, 1, 1) + t * rt::Color(0.5, 0.7, 1);
  }
}

/**
 * @brief Computes the color of a ray of light.
 * @param scene The scene to render.
 * @param ray The ray to render.
 * @return
 */
rt::Color RenderBeautyTrueLambertian(const rt::Scene &scene, const rt::Ray &ray, int bounces) noexcept
{
  rt::HitRecord rec;
  if (bounces <= 0) return { 0, 0, 0 };
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    Point target = rec.p + rec.normal + Vec3::RandomInUnitSphere();
    return 0.5 * RenderBeautyLambertianHack(scene, { rec.p, target - rec.p }, bounces - 1);
  } else {
    const auto unit_direction = ray.direction().Normalized();
    const auto t = 0.5 * (unit_direction.y() + 1);
    return (1 - t) * rt::Color(1, 1, 1) + t * rt::Color(0.5, 0.7, 1);
  }
}

/**
 * @brief Computes the color of a ray of light.
 * @param scene The scene to render.
 * @param ray The ray to render.
 * @return
 */
rt::Color RenderBeautyAlternativeDiffuse(const rt::Scene &scene, const rt::Ray &ray, int bounces) noexcept
{
  rt::HitRecord rec;
  if (bounces <= 0) return { 0, 0, 0 };
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    Point target = rec.p + Vec3::RandomInHemisphere(rec.normal);
    return 0.5 * RenderBeautyLambertianHack(scene, { rec.p, target - rec.p }, bounces - 1);
  } else {
    const auto unit_direction = ray.direction().Normalized();
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
rt::Color RenderDepthMap(const rt::Scene &scene, const rt::Ray &ray, const double max_depth) noexcept
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
rt::Color RenderNormalMap(const rt::Scene &scene, const rt::Ray &ray) noexcept
{
  rt::HitRecord rec;
  if (scene.Intersect(ray, 0.001, rt::utils::kInf, rec)) {
    return rt::color::FromNormal(rec.normal);
  } else {
    return { 0, 0, 0 };
  }
}

}// namespace rt::rendering