#include <catch2/catch_test_macros.hpp>

#include <rt/ray.hpp>

using rt::Ray;

TEST_CASE("ray_origin")
{
  constexpr Ray a({ 1, 2, 3 }, { 4, 5, 6 });
  STATIC_REQUIRE(a.origin() == rt::Point(1, 2, 3));
}

TEST_CASE("ray_direction")
{
  constexpr Ray a({ 1, 2, 3 }, { 4, 5, 6 });
  STATIC_REQUIRE(a.direction() == rt::Vec3(4, 5, 6));
}

TEST_CASE("ray_at")
{
  constexpr Ray a({ 1, 2, 3 }, { 4, 5, 6 });
  STATIC_REQUIRE(a.At(2) == rt::Vec3(9, 12, 15));
}