#pragma once

#include <rt/point.hpp>
#include <rt/ray.hpp>

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
  [[nodiscard]] Camera(const double focal_length,
    const double viewport_width,
    const double viewport_height,
    const Point &position,
    const Point &look_at,
    const Vec3 &vertical) noexcept
    : _focal_length(focal_length), _viewport_width(viewport_width), _viewport_height(viewport_height),
      _position(position), _look_at(look_at), _vertical(Vec3::Normalized(vertical) * viewport_height),
      _horizontal(Vec3::Cross(Vec3::Normalized(look_at - position), Vec3::Normalized(vertical)) * viewport_width),
      _lower_left_corner(position + Vec3::Normalized((look_at - position)) * focal_length - _horizontal / 2 - _vertical / 2)
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
  [[nodiscard]] constexpr auto horizontal() const noexcept { return _horizontal; }

  /**
   * @brief Returns the ray that passes through the left corner in the viewport.
   * @return
   */
  [[nodiscard]] constexpr auto Ray(double h, double v) const noexcept
  {
    return rt::Ray(_position, _lower_left_corner + h * _horizontal + v * _vertical - _position);
  }

private:
  /// @brief The focal length of the camera.
  double _focal_length;
  /// @brief The width of the viewport.
  double _viewport_width;
  /// @brief The height of the viewport.
  double _viewport_height;
  /// @brief The position of the camera.
  Point _position;
  /// @brief The point the camera is looking at.
  Point _look_at;
  /// @brief The vertical vector of the camera.
  Vec3 _vertical;
  /// @brief The right vector of the camera.
  Vec3 _horizontal;
  /// @brief The lower left corner of the viewport.
  Vec3 _lower_left_corner;
};

}// namespace rt