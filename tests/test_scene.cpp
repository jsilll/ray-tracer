#include <catch2/catch_test_macros.hpp>

#include <rt/primitives/sphere.hpp>
#include <rt/scene.hpp>

#include <memory>

using rt::Ray;
using rt::Scene;
using rt::Sphere;
using rt::Point;
using rt::HitRecord;

TEST_CASE("scene_clear")
{
  Scene scene;
  scene.Add(std::make_unique<Sphere>(Point(0, 0, -1), 0.5f));
  scene.Clear();
  REQUIRE(scene.IsEmpty());
}

TEST_CASE("surface_intersect")
{
  Scene scene;
  HitRecord rec;

  Ray ray({ 0, 0, 0 }, { 0, 0, 1 });
  REQUIRE(!scene.Intersect(ray, 0, 10, rec));

  ray = { { 0, 0, -5 }, { 0, 0, 1 } };
  REQUIRE(!scene.Intersect(ray, 0, 10, rec));

  scene.Add(std::make_unique<Sphere>(Point(0, 0, 0), 1));
  REQUIRE(scene.Intersect(ray, 0, 10, rec));
}