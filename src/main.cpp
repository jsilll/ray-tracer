#include <algorithm>
#include <iostream>

#include <camera.hpp>
#include <color.hpp>
#include <point3.hpp>
#include <ray.hpp>
#include <vec3.hpp>

inline Color RayColor(const Ray &ray)
{
  const double t = 0.5 * (ray.direction().Normalized().y() + 1.);
  const Color white(1., 1., 1.);
  const Color blue(0.5, 0.7, 1.);
  const Color orange(1., 0.5, 0.);
  return std::max(0., 1. - t) * white * orange + t * blue;
}

inline void WriteColor(std::ostream &out, const Color &pixel_color)
{
  out << static_cast<int>(255.999 * pixel_color.x()) << ' ' << static_cast<int>(255.999 * pixel_color.y()) << ' '
      << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

int main()
{
  // Image
  const int IMAGE_WIDTH = 400;
  constexpr double ASPECT_RATIO = 16. / 9.;
  constexpr int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

  // Camera
  Camera cam(1., 2., ASPECT_RATIO * 2.);

  // Utilities
  Point3 origin(0, 0, 0);
  Vec3 vertical(0, cam.viewport_height(), 0);
  Vec3 horizontal(cam.viewport_width(), 0, 0);

  auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, cam.focal_length());

  // Writing Image
  std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";
  for (int j = IMAGE_HEIGHT - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < IMAGE_WIDTH; ++i) {
      // Computing this ray's direction
      const double u = double(i) / (IMAGE_WIDTH - 1);
      const double v = double(j) / (IMAGE_HEIGHT - 1);
      Vec3 direction = lower_left_corner + u * horizontal + v * vertical - origin;

      // Computing this ray's color
      Ray ray(origin, direction);
      Color pixel_color = RayColor(ray);

      // Writing this ray's color to the image
      WriteColor(std::cout, pixel_color);
    }
  }
  std::cerr << "\nDone.\n";

  std::exit(EXIT_SUCCESS);
}