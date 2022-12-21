#include "image.hpp"

#include <fstream>

void Image::SaveAsPPM(const std::string &filename) const
{
  if (_pixels.empty()) { throw std::runtime_error("Image is empty."); }
  std::fstream file{ filename, std::fstream::out };
  if (!file.is_open()) { throw std::runtime_error("Failed to open file: " + filename + "."); }
  const int image_width = static_cast<int>(_pixels.size());
  const int image_height = static_cast<int>(_pixels[0].size());
  file << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  constexpr float kMultiplier = 255.999f;
  for (int j = image_height - 1; j >= 0; --j) {
    for (int i = 0; i < image_width; ++i) {
      auto row = static_cast<std::size_t>(j);
      auto col = static_cast<std::size_t>(i);
      auto &color = _pixels[col][row];
      const int ir = static_cast<int>(kMultiplier * color.x());
      const int ig = static_cast<int>(kMultiplier * color.y());
      const int ib = static_cast<int>(kMultiplier * color.z());
      file <<  ir << ' ' << ig << ' ' << ib << '\n';
    }
  }
}
