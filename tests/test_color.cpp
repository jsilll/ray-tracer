#include <catch2/catch_test_macros.hpp>

#include <rt/color.hpp>

using rt::Color;
using rt::Vec3;

TEST_CASE("color_from_normal")
{
  const auto color = rt::color::FromNormal(Vec3(1, 2, 3).Normalized());
  REQUIRE(color.x() == ((1.0 / std::sqrt(14)  + 1.0) / 2.0));
  REQUIRE(color.y() == ((2.0 / std::sqrt(14)  + 1.0) / 2.0));
  REQUIRE(color.z() == ((3.0 / std::sqrt(14)  + 1.0) / 2.0));
}