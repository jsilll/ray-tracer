#include <catch2/catch_test_macros.hpp>

#include <rt/color.h>

using rt::Color;
using rt::Vec3f;

TEST_CASE("color_from_normal")
{
  const auto color = rt::color::FromNormal(Vec3f(1, 2, 3).Normalized());
  REQUIRE(color.x() == 0.63363062f);
  REQUIRE(color.y() == 0.76726124f);
  REQUIRE(color.z() == 0.90089186f);
}