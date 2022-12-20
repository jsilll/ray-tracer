#pragma once

#include <rt/color.hpp>

#include <vector>

/// @brief A 2D image.
class Image final
{
public:
  /**
   * @brief Construct a new Image object
   * @param pixels The pixels of the image.
   */
  [[nodiscard]] explicit Image(std::vector<std::vector<rt::Color>> &&pixels) noexcept : _pixels(std::move(pixels)) {}

  /**
   * @brief Save the image to a PPM file
   * @param filename The name of the file to save the image to.
   */
  void SaveAsPPM(const std::string &filename) const;

private:
  /// @brief The pixels of the image.
  std::vector<std::vector<rt::Color>> _pixels;
};