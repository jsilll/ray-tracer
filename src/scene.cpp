#include <rt/scene.hpp>

#include <execution>

namespace rt {

bool Scene::Intersect(const Ray &ray, const double t_min, const double t_max, HitRecord &rec) const noexcept
{
  rec.t = t_max;
  bool hit_anything = false;
  std::for_each(std::execution::seq, _objects.begin(), _objects.end(), [&](const auto &object) {
    if (object->Intersect(ray, t_min, rec.t, rec)) { hit_anything = true; }
  });
  return hit_anything;
}

}// namespace rt