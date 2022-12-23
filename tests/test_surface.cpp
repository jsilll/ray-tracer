#include <catch2/catch_test_macros.hpp>

#include <rt/object3d.hpp>

using rt::HitRecord;
using rt::Ray;

TEST_CASE("hit_record_set_normal")
{
  HitRecord rec;

  constexpr Ray ray({ 0, 0, 0 }, { 0, 0, 1 });

  rec.SetFaceNormal(ray, { 0, 0, 1 });
  REQUIRE(rec.front_face == false);
  REQUIRE(rec.normal == rt::Vec3(0, 0, -1));

  rec.SetFaceNormal(ray, { 0, 0, -1 });
  REQUIRE(rec.front_face == true);
  REQUIRE(rec.normal == rt::Vec3(0, 0, -1));
}
