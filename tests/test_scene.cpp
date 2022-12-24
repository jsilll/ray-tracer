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
  scene.Add(std::make_unique<Sphere>(Point(0, 0, -1), 0.5));
  scene.Clear();
  REQUIRE(scene.IsEmpty());
}

TEST_CASE("surface_intersect")
{
  HitRecord rec;

  const  Scene scene1;
  const auto ray1 = Ray({ 0, 0, 0 }, { 0, 0, 1 });
  REQUIRE(!scene1.Intersect(ray1, 0, 10, rec));
  const auto ray2 = Ray( { 0, 0, -5 }, { 0, 0, 1 } );
  REQUIRE(!scene1.Intersect(ray2, 0, 10, rec));

  Scene scene2;
  const auto ray3 = Ray({ 0, 0, 0 }, { 0, 0, 1 });
  scene2.Add(std::make_unique<Sphere>(Point(0, 0, 0), 1));
  REQUIRE(scene2.Intersect(ray3, 0, 10, rec));
}