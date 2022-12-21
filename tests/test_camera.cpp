#include <catch2/catch_test_macros.hpp>

#include <rt/camera.hpp>

using rt::Camera;

TEST_CASE("camera_focal_length")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.focal_length() == 1.f);
}

TEST_CASE("camera_viewport_width")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.viewport_width() == 3.f);
}

TEST_CASE("camera_viewport_height")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.viewport_height() == 2.f);
}

TEST_CASE("camera_position")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.position() == rt::Point(0, 0, 0));
}

TEST_CASE("camera_look_at")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.look_at() == rt::Point(0, 0, -1));
}

TEST_CASE("camera_up")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.vertical() == rt::Vec3f(0, 2, 0));
}
