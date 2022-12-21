#pragma once

#include "image.hpp"

#include <rt/camera.hpp>
#include <rt/scene.hpp>
#include <rt/utils.hpp>

#include <algorithm>
#include <execution>
#include <vector>

/// @brief Types of renderers.
enum RenderType {
  /// @brief Renders the albedo of the scene.
  kAlbedo,
  /// @brief Renders the final image.
  kBeauty,
  /// @brief Renders the depth of the scene.
  kDepth,
  /// @brief Renders the normals of the scene.
  kNormals,
  /// @brief Renders the emissive materials of the scene.
  kEmissive,
  /// @brief Renders the metallic materials of the scene.
  kMetallic,
  /// @brief Renders the roughness materials of the scene.
  kRoughness,
};

/// @brief Renders an image.
class Renderer final
{
public:
  /**
   * @brief Construct a new Renderer object.
   * @param image_width The width of the image to render.
   * @param image_height The height of the image to render.
   */
  [[nodiscard]] constexpr Renderer(const std::size_t image_width,
    const std::size_t image_height,
    const rt::Scene &scene) noexcept
    : _image_width(image_width), _image_height(image_height), _scene(scene)
  {}

  /**
   * @brief Renders the scene.
   * @param camera The camera to use.
   * @return
   */
  [[nodiscard]] Image Render(const rt::Camera &camera) const noexcept;


private:
  /// @brief The width of the image.
  std::size_t _image_width;
  /// @brief The height of the image.
  std::size_t _image_height;
  /// @brief The scene to render.
  const rt::Scene &_scene;
};
