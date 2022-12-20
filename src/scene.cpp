#include <rt/scene.hpp>

namespace rt {

bool Scene::Intersect(const Ray &ray, float t_min, float t_max, HitRecord &rec) const noexcept
{
  bool hit_anything = false;
  float closest_so_far = t_max;
  for (const auto &object : _objects) {
    if (object->Intersect(ray, t_min, closest_so_far, rec)) {
      hit_anything = true;
      closest_so_far = rec.t;
    }
  }
  return hit_anything;
}

}// namespace rt