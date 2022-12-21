#pragma once

#include <rt/surface.hpp>

#include <memory>
#include <vector>

namespace rt {

/// @brief A scene in 3D space.
class Scene final : Surface
{
public:
  Scene() noexcept = default;

  /**
   * @brief Move constructs a scene.
   * @param scene
   */
  Scene(Scene &&scene) noexcept : _objects(std::move(scene._objects)) {}

  /**
   * @brief Reassigns the scene with move semantics.
   * @param scene
   * @return
   */
  Scene &operator=(Scene &&scene) noexcept
  {
    _objects = std::move(scene._objects);
    return *this;
  }

  /// @brief Deletes the copy constructor.
  Scene(const Scene &) = delete;

  /// @brief Deletes the copy assignment operator.
  Scene &operator=(const Scene &) = delete;

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
