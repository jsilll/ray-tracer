#include <catch2/catch_test_macros.hpp>

#include <rt/camera.hpp>

using rt::Camera;

TEST_CASE("camera_focal_length")
{
  constexpr Camera camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  STATIC_REQUIRE(camera.focal_length() == 1.f);
}

TEST_CASE("camera_viewport_width")
{
  constexpr Camera camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  STATIC_REQUIRE(camera.viewport_width() == 3.f);
}

TEST_CASE("camera_viewport_height")
{
  constexpr Camera camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  STATIC_REQUIRE(camera.viewport_height() == 2.f);
}

TEST_CASE("camera_position")
{
  constexpr Camera camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  STATIC_REQUIRE(camera.position() == rt::Point(0, 0, 0));
}

TEST_CASE("camera_look_at")
{
  constexpr Camera camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  STATIC_REQUIRE(camera.look_at() == rt::Point(0, 0, -1));
}

TEST_CASE("camera_up")
{
  constexpr Camera camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  STATIC_REQUIRE(camera.up() == rt::Vec3f(0, 1, 0));
}
