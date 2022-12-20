#pragma once

#include <rt/surface.hpp>

#include <memory>
#include <vector>

namespace rt {

/// @brief A scene in 3D space.
class Scene final : Surface
{
public:
  /**
   * @brief Removes all the objects from a scene.
   */
  void Clear() noexcept { _objects.clear(); }

  /**
   * @brief Returns whether the scene is empty.
   * @return
   */
  [[nodiscard]] bool IsEmpty() const noexcept { return _objects.empty(); }

  /**
   * @brief Adds an object to the scene.
   * @param object The object to add.
   */
  void Add(std::unique_ptr<Surface> object) noexcept { _objects.push_back(std::move(object)); }

  [[nodiscard]] bool Intersect(const Ray &ray, float t_min, float t_max, HitRecord &rec) const noexcept override;

private:
  /// @brief The surfaces in the scene.
  std::vector<std::unique_ptr<Surface>> _objects;
};

}// namespace rt
