#pragma once

#include <rt/color.hpp>

#include <vector>

/// @brief A 2D image.
class Image final
{
public:
  Image() = default;

  /**
   * @brief Construct a new Image object
   * @param pixels The pixels of the image.
   */
  [[nodiscard]] explicit Image(const std::vector<std::vector<rt::Color>> &&pixels) noexcept : _pixels(pixels) {}

  /**
   * @brief Construct a new Image object from another image with move semantics.
   * @param img The image to move.
   */
  Image(Image &&img) noexcept : _pixels(std::move(img._pixels)) {}

  /**
   * @brief Reassign the image with move semantics.
   * @param img The image to move.
   */
  Image &operator=(Image &&img) noexcept
  {
    _pixels = std::move(img._pixels);
    return *this;
  }

  /// @brief Disable copy constructor.
  Image(Image &) = delete;

  /// @brief Disable copy constructor.
  Image &operator=(Image &) = delete;

  /**
   * @brief Save the image to a PPM file
   * @param filename The name of the file to save the image to.
   */
  void SaveAsPPM(const std::string &filename) const;

private:
  /// @brief The pixels of the image.
  std::vector<std::vector<rt::Color>> _pixels;
};