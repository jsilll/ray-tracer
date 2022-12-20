#include <catch2/catch_test_macros.hpp>

#include <rt/surface.hpp>

using rt::HitRecord;
using rt::Ray;

TEST_CASE("hit_record_set_normal")
{
  HitRecord rec;

  constexpr Ray ray({ 0, 0, 0 }, { 0, 0, 1 });

  rec.set_face_normal(ray, { 0, 0, 1 });
  REQUIRE(rec.front_face == false);
  REQUIRE(rec.normal == rt::Vec3f(0, 0, -1));

  rec.set_face_normal(ray, { 0, 0, -1 });
  REQUIRE(rec.front_face == true);
  REQUIRE(rec.normal == rt::Vec3f(0, 0, -1));
}
