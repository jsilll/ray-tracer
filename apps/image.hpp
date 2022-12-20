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
  explicit Image(std::vector<std::vector<rt::Color>> &&pixels) noexcept : _pixels(std::move(pixels)) {}

  /**
   * @brief Save the image to a PPM file
   * @param filename The name of the file to save the image to.
   */
  void SaveAsPPM(const std::string &filename) const
  {
    if (_pixels.empty()) { throw std::runtime_error("Image is empty"); }

    std::fstream file{ filename, std::fstream::out };

    if (!file.is_open()) { throw std::runtime_error("Failed to open file: " + filename); }

    // Getting Image Sizes
    int image_width = static_cast<int>(_pixels.size());
    int image_height = static_cast<int>(_pixels[0].size());

    // Writing Image
    file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    for (int j = image_height; j >= 0; --j) {
      for (int i = 0; i < image_width; ++i) {
        auto row = static_cast<std::size_t>(j);
        auto col = static_cast<std::size_t>(i);
        WriteColorBMP(file, _pixels[col][row]);
      }
    }
  }

private:
  /**
   * @brief Writes a color to a file in the PPM format.
   * @param out The file to write to.
   * @param pixel_color The color to write.
   */
  static void WriteColorBMP(std::fstream &out, const rt::Color &pixel_color)
  {
    constexpr float multiplier = 255.999f;
    out << static_cast<int>(multiplier * pixel_color.x()) << ' ' << static_cast<int>(multiplier * pixel_color.y()) << ' '
        << static_cast<int>(multiplier * pixel_color.z()) << '\n';
  }

  std::vector<std::vector<rt::Color>> _pixels;
};