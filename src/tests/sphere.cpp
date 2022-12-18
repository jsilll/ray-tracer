#include <catch2/catch_test_macros.hpp>

#include <rt/primitives/sphere.h>
#include <rt/ray.h>

using rt::Sphere;
using rt::Ray;

TEST_CASE("sphere_center")
{
  constexpr Sphere a({ 1, 2, 3 }, 4);
  constexpr auto b = a.center();
  REQUIRE(b.x() == 1.f);
  REQUIRE(b.y() == 2.f);
  REQUIRE(b.z() == 3.f);
}

TEST_CASE("sphere_radius")
{
  constexpr Sphere a({ 1, 2, 3 }, 4);
  STATIC_REQUIRE(a.radius() == 4.f);
}

TEST_CASE("sphere_radius2")
{
  constexpr Sphere a({ 1, 2, 3 }, 4);
  REQUIRE(a.Radius2() == 16.f);
}

TEST_CASE("sphere_intersected_by")
{
  constexpr Sphere sphere({ 0, 0, 0 }, 1);

  constexpr Ray r1({ 0, 0, -5 }, { 0, 0, 1 });
  REQUIRE(sphere.IntersectedBy(r1) == true);

  constexpr Ray r2({ 0, 0, -5 }, { 0, 1, 0 });
  REQUIRE(sphere.IntersectedBy(r2) == false);

  constexpr Ray r3({ 0, 0, -5 }, { 0, 0, -1 });
  REQUIRE(sphere.IntersectedBy(r3) == true);

  constexpr Ray r4(rt::Point(0, 0, -5), { 0, 0, 1 });
  REQUIRE(sphere.IntersectedBy(r4) == true);

  constexpr Ray r5(rt::Point(0, 0, -5), { 0, 0, 1 });
  REQUIRE(sphere.IntersectedBy(r5) == true);
}