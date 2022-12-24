#include <catch2/catch_test_macros.hpp>

#include <rt/camera.hpp>

using rt::Camera;

TEST_CASE("camera_focal_length")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.focal_length() == 1);
}

TEST_CASE("camera_viewport_width")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.viewport_width() == 3);
}

TEST_CASE("camera_viewport_height")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.viewport_height() == 2);
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
  REQUIRE(camera.vertical() == rt::Vec3(0, 2, 0));
}

TEST_CASE("camera_horizontal")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  REQUIRE(camera.horizontal() == rt::Vec3(3, 0, 0));
}

TEST_CASE("camera_ray")
{
  const auto camera = Camera(1, 3, 2, { 0, 0, 0 }, { 0, 0, -1 }, { 0, 1, 0 });
  const auto ray1 = camera.Ray(0, 0);
  REQUIRE(ray1.origin() == rt::Point(0, 0, 0));
  REQUIRE(ray1.direction() == rt::Vec3(-1.5, -1, -1));

  const auto ray2 = camera.Ray(1, 1);
  REQUIRE(ray2.origin() == rt::Point(0, 0, 0));
  REQUIRE(ray2.direction() == rt::Vec3(1.5, 1, -1));
}