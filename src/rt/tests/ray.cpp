#include <catch2/catch_test_macros.hpp>
#include <ray.hpp>

using rt::Ray;
using rt::Vec3;

TEST_CASE("ray_origin")
{
  constexpr Ray a(Vec3(1, 2, 3), Vec3(4, 5, 6));
  constexpr auto b = a.origin();
  REQUIRE(b.x() == 1);
  REQUIRE(b.y() == 2);
  REQUIRE(b.z() == 3);
}

TEST_CASE("ray_direction")
{
  constexpr Ray a(Vec3(1, 2, 3), Vec3(4, 5, 6));
  constexpr auto b = a.direction();
  REQUIRE(b.x() == 4);
  REQUIRE(b.y() == 5);
  REQUIRE(b.z() == 6);
}

TEST_CASE("ray_at")
{
  constexpr Ray a(Vec3(1, 2, 3), Vec3(4, 5, 6));
  constexpr auto b = a.At(2);
  REQUIRE(b.x() == 9);
  REQUIRE(b.y() == 12);
  REQUIRE(b.z() == 15);
}