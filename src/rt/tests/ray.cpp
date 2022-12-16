#include <cassert>

#include "../ray.hpp"

using rt::Ray;
using rt::Vec3;

void test_ray_origin()
{
  Ray a(Vec3(1, 2, 3), Vec3(4, 5, 6));
  Vec3 b = a.origin();
  assert(b.x() == 1);
  assert(b.y() == 2);
  assert(b.z() == 3);
}

void test_ray_direction()
{
  Ray a(Vec3(1, 2, 3), Vec3(4, 5, 6));
  Vec3 b = a.direction();
  assert(b.x() == 4);
  assert(b.y() == 5);
  assert(b.z() == 6);
}

void test_ray_at()
{
  Ray a(Vec3(1, 2, 3), Vec3(4, 5, 6));
  Vec3 b = a.At(2);
  assert(b.x() == 9);
  assert(b.y() == 12);
  assert(b.z() == 15);
}

int main()
{
  test_ray_origin();
  test_ray_direction();
  test_ray_at();
}
