#pragma once

class Camera
{
public:
  Camera() noexcept : focal_length_(1.0), viewport_height_(2.0), viewport_width_(4.0) {}

  Camera(double focal_length, double viewport_height, double viewport_width) noexcept
    : focal_length_(focal_length), viewport_height_(viewport_height), viewport_width_(viewport_width)
  {}

  double focal_length() const noexcept { return focal_length_; }

  double viewport_width() const noexcept { return viewport_width_; }

  double viewport_height() const noexcept { return viewport_height_; }

private:
  double focal_length_;
  double viewport_width_;
  double viewport_height_;
};