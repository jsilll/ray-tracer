#include <catch2/catch_test_macros.hpp>

#include <rt/primitives/sphere.h>
#include <rt/ray.h>

using rt::Sphere;
using rt::Ray;
using rt::HitRecord;
using rt::Point;
using rt::Vec3f;

TEST_CASE("sphere_center")
{
  const Sphere a({ 1, 2, 3 }, 4);
  const auto b = a.center();
  REQUIRE(b.x() == 1.f);
  REQUIRE(b.y() == 2.f);
  REQUIRE(b.z() == 3.f);
}

TEST_CASE("sphere_radius")
{
  const Sphere a({ 1, 2, 3 }, 4);
  REQUIRE(a.radius() == 4.f);
}

TEST_CASE("sphere_radius2")
{
  const Sphere a({ 1, 2, 3 }, 4);
  REQUIRE(a.Radius2() == 16.f);
}

TEST_CASE("sphere_intersected")
{
  HitRecord rec;
  const Sphere sphere({ 0, 0, 0 }, 1);

  Ray ray({ 0, 0, -5 }, { 0, 0, 1 });
  REQUIRE(sphere.Intersect(ray, 0, 10, rec));
  REQUIRE(rec.t == 4.f);
  REQUIRE(rec.p == Point(0, 0, -1));
  REQUIRE(rec.normal == Vec3f(0, 0, -1));

  ray = { { 0, 0, -5 }, { 0, 0, -1 } };
  REQUIRE(!sphere.Intersect(ray, 0, 10, rec));

  ray = { { 0, 0, 0 }, { 0, 0, 1 } };
  REQUIRE(sphere.Intersect(ray, 0, 10, rec));
  REQUIRE(rec.t == 1.f);
  REQUIRE(rec.p == Point(0, 0, 1));
  REQUIRE(rec.normal == Vec3f(0, 0, 1));

  ray = { { 0, 0, 2 }, { 0, 0, 1 } };
  REQUIRE(!sphere.Intersect(ray, 0, 10, rec));

  ray = { { 0, 1, -5 }, { 0, 0, 1 } };
  REQUIRE(sphere.Intersect(ray, 0, 10, rec));
  REQUIRE(rec.t == 5.f);
  REQUIRE(rec.p == Point(0, 1, -0));
  REQUIRE(rec.normal == Vec3f(0, 1, 0));

  ray = { { 0, 2, -5 }, { 0, 0, 1 } };
  REQUIRE(!sphere.Intersect(ray, 0, 10, rec));
}