#pragma once

namespace rt {

class Camera final
{
public:
  constexpr Camera(double focal_length, double viewport_width, double viewport_height) noexcept
    : focal_length_(focal_length), viewport_width_(viewport_width), viewport_height_(viewport_height)
  {}

  [[nodiscard]] constexpr auto focal_length() const noexcept { return focal_length_; }

  [[nodiscard]] constexpr auto viewport_width() const noexcept { return viewport_width_; }

  [[nodiscard]] constexpr auto viewport_height() const noexcept { return viewport_height_; }

private:
  double focal_length_;
  double viewport_width_;
  double viewport_height_;
};

}// namespace rt