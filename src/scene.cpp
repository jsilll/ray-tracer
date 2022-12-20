#include <rt/scene.hpp>

#include <execution>

namespace rt {

bool Scene::Intersect(const Ray &ray, const float t_min, const float t_max, HitRecord &rec) const noexcept
{
  bool hit_anything = false;
  float closest_so_far = t_max;

  std::for_each(std::execution::seq, _objects.begin(), _objects.end(), [&](const auto &object) {
    if (object->Intersect(ray, t_min, closest_so_far, rec)) {
      hit_anything = true;
      closest_so_far = rec.t;
    }
  });

  return hit_anything;
}

}// namespace rt