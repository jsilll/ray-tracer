#pragma once

#include <rt/point.hpp>

namespace rt {

/// @brief A camera in 3D space.
class Camera final
{
public:
  /**
   * @brief Constructs a camera with the given position, look-at point, and vertical vector.
   * @param focal_length The focal length of the camera.
   * @param viewport_width The width of the viewport.
   * @param viewport_height The height of the viewport.
   * @param position The position of the camera.
   * @param look_at The point the camera is looking at.
   * @param vertical The vertical vector of the camera.
   */
  [[nodiscard]] Camera(const float focal_length,
    const float viewport_width,
    const float viewport_height,
    const Point &position,
    const Point &look_at,
    const Vec3f &vertical) noexcept
    : _focal_length(focal_length), _viewport_width(viewport_width), _viewport_height(viewport_height),
      _position(position), _look_at(look_at), _vertical(vertical.Normalized() * viewport_height),
      _horizontal((look_at - position).Normalized().Cross(vertical.Normalized()) * viewport_width),
      _lower_left_corner(position + (look_at - position).Normalized() * focal_length - _horizontal / 2 - _vertical / 2)
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
   * @brief Returns the vertical vector of the camera.
   * @return
   */
  [[nodiscard]] constexpr auto vertical() const noexcept { return _vertical; }

  /**
   * @brief Returns the horizontal vector of the camera.
   * @return
   */
  [[nodiscard]] constexpr auto horizontal() const noexcept { return _horizontal; } // TODO: add tests

  /**
   * @brief Returns the ray that passes through the left corner in the viewport.
   * @return
   */
  [[nodiscard]] constexpr auto lower_left_ray() const noexcept { return _lower_left_corner - _position; } // TODO: add tests

private:
  /// @brief The focal length of the camera.
  float _focal_length;
  /// @brief The width of the viewport.
  float _viewport_width;
  /// @brief The height of the viewport.
  float _viewport_height;
  /// @brief The position of the camera.
  Point _position;
  /// @brief The point the camera is looking at.
  Point _look_at;
  /// @brief The vertical vector of the camera.
  Vec3f _vertical;
  /// @brief The right vector of the camera.
  Vec3f _horizontal;
  /// @brief The lower left corner of the viewport.
  Vec3f _lower_left_corner;
};

}// namespace rt