#include <image.hpp>

#include <fstream>

constexpr auto kMultiplier = 256;

void Image::SaveAsPPM(const std::string &filename) const
{
  // Check if the image is empty
  if (_pixels.empty()) { throw std::runtime_error("Image is empty."); }

  // Open the file
  std::fstream file{ filename, std::fstream::out };
  if (!file.is_open()) { throw std::runtime_error("Failed to open file: " + filename + "."); }

  // Write the header
  const auto image_width = static_cast<int>(_pixels.size());
  const auto image_height = static_cast<int>(_pixels[0].size());
  file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  // Write the image
  for (int j = image_height - 1; j >= 0; --j) {
    for (int i = 0; i < image_width; ++i) {
      const auto row = static_cast<std::size_t>(j);
      const auto col = static_cast<std::size_t>(i);
      auto &color = _pixels[col][row];
      // Gamma Correction 2.0 + Clamping + Scaling to [0, 255)
      const auto ir = static_cast<int>(kMultiplier * rt::utils::Clamp(std::sqrt(color.x()), 0, 0.999));
      const auto ig = static_cast<int>(kMultiplier * rt::utils::Clamp(std::sqrt(color.y()), 0, 0.999));
      const auto ib = static_cast<int>(kMultiplier * rt::utils::Clamp(std::sqrt(color.z()), 0, 0.999));
      file << ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
}
