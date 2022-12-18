#pragma once

namespace rt {

/// @brief A camera in 3D space.
class Camera final
{
public:
  /**
   * @brief Constructs a camera with the given position, look-at point, and up vector.
   * @param focal_length The focal length of the camera.
   * @param viewport_width The width of the viewport.
   * @param viewport_height The height of the viewport.
   */
  [[nodiscard]] constexpr Camera(float focal_length, float viewport_width, float viewport_height) noexcept
    : _focal_length(focal_length), _viewport_width(viewport_width), _viewport_height(viewport_height)
  {} // TODO: Add position, look-at, and up vectors.

  /**
   * @brief Returns the focal length of the camera.
   * @return
   */
  [[nodiscard]] constexpr auto focal_length() const noexcept { return _focal_length; }

  /**
   * @brief Returns the width of the viewport.
   * @return
   */
  [[nodiscard]] constexpr auto viewport_width() const noexcept { return _viewport_width; }

  /**
   * @brief Returns the height of the viewport.
   * @return
   */
  [[nodiscard]] constexpr auto viewport_height() const noexcept { return _viewport_height; }

private:
  float _focal_length;
  float _viewport_width;
  float _viewport_height;
};

}// namespace rt