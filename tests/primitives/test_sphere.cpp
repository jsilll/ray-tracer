#include <catch2/catch_test_macros.hpp>

#include <rt/primitives/sphere.hpp>

using rt::Sphere;
using rt::Ray;
using rt::HitRecord;
using rt::Point;
using rt::Vec3;

TEST_CASE("sphere_center")
{
  const Sphere a({ 1, 2, 3 }, 4);
  REQUIRE(a.center() == Point(1, 2, 3));
}

TEST_CASE("sphere_radius")
{
  const Sphere a({ 1, 2, 3 }, 4);
  REQUIRE(a.radius() == 4);
}

TEST_CASE("sphere_radius2")
{
  const Sphere a({ 1, 2, 3 }, 4);
  REQUIRE(a.Radius2() == 16);
}

TEST_CASE("sphere_intersected")
{
  const Sphere sphere({ 0, 0, 0 }, 1);

  HitRecord rec;
  Ray ray({ 0, 0, -5 }, { 0, 0, 1 });
  REQUIRE(sphere.Intersect(ray, 0, 10, rec));
  REQUIRE(rec.t == 4);
  REQUIRE(rec.front_face == true);
  REQUIRE(rec.p == Point(0, 0, -1));
  REQUIRE(rec.normal == Vec3(0, 0, -1));

  ray = { { 0, 0, -5 }, { 0, 0, -1 } };
  REQUIRE(!sphere.Intersect(ray, 0, 10, rec));

  ray = { { 0, 0, 0 }, { 0, 0, 1 } };
  REQUIRE(sphere.Intersect(ray, 0, 10, rec));
  REQUIRE(rec.t == 1);
  REQUIRE(rec.front_face == false);
  REQUIRE(rec.p == Point(0, 0, 1));
  REQUIRE(rec.normal == Vec3(0, 0, -1));

  ray = { { 0, 0, 2 }, { 0, 0, 1 } };
  REQUIRE(!sphere.Intersect(ray, 0, 10, rec));

  ray = { { 0, 1, -5 }, { 0, 0, 1 } };
  REQUIRE(sphere.Intersect(ray, 0, 10, rec));
  REQUIRE(rec.t == 5);
  REQUIRE(rec.front_face == true);
  REQUIRE(rec.p == Point(0, 1, 0));
  REQUIRE(rec.normal == Vec3(0, 1, 0));

  ray = { { 0, 2, -5 }, { 0, 0, 1 } };
  REQUIRE(!sphere.Intersect(ray, 0, 10, rec));
}