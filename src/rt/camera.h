#pragma once

#include <rt/point.h>

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
   * @param position The position of the camera.
   * @param look_at The point the camera is looking at.
   * @param up The up vector of the camera.
   */
  [[nodiscard]] constexpr Camera(const float focal_length,
    const float viewport_width,
    const float viewport_height,
    const Point position,
    const Point look_at,
    const Vec3f up) noexcept
    : _focal_length(focal_length), _viewport_width(viewport_width), _viewport_height(viewport_height),
      _position(position), _look_at(look_at), _up(up)
  {}

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

  /**
   * @brief Returns the position of the camera.
   * @return
   */
  [[nodiscard]] constexpr auto position() const noexcept { return _position; }

  /**
   * @brief Returns the point the camera is looking at.
   * @return
   */
  [[nodiscard]] constexpr auto look_at() const noexcept { return _look_at; }

  /**
   * @brief Returns the up vector of the camera.
   * @return
   */
  [[nodiscard]] constexpr auto up() const noexcept { return _up; }

private:
  float _focal_length;
  float _viewport_width;
  float _viewport_height;
  Point _position;
  Point _look_at;
  Vec3f _up;
};

}// namespace rt