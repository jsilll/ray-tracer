#include <cassert>

#include "../camera.hpp"

using rt::Camera;

void test_camera_focal_length()
{
  Camera a(1, 3, 2);
  double b = a.focal_length();
  assert(b == 1);
}

void test_camera_viewport_width()
{
  Camera a(1, 3, 2);
  double b = a.viewport_width();
  assert(b == 3);
}

void test_camera_viewport_height()
{
  Camera a(1, 3, 2);
  double b = a.viewport_height();
  assert(b == 2);
}

int main()
{
  test_camera_focal_length();
  test_camera_viewport_width();
  test_camera_viewport_height();
}