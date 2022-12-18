#include <catch2/catch_test_macros.hpp>

#include <rt/camera.h>

using rt::Camera;

TEST_CASE("camera_focal_length")
{
  constexpr Camera camera(1, 3, 2);
  STATIC_REQUIRE(camera.focal_length() == 1.f);
}

TEST_CASE("camera_viewport_width")
{
  constexpr Camera camera(1, 3, 2);
  STATIC_REQUIRE(camera.viewport_width() == 3.f);
}

TEST_CASE("camera_viewport_height")
{
  constexpr Camera camera(1, 3, 2);
  STATIC_REQUIRE(camera.viewport_height() == 2.f);
}
