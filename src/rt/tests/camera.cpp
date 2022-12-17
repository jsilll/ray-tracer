#include <camera.hpp>
#include <catch2/catch_test_macros.hpp>

using rt::Camera;

TEST_CASE("camera_focal_length")
{
  constexpr Camera a(1, 3, 2);
  REQUIRE(a.focal_length() == 1);
}

TEST_CASE("camera_viewport_width")
{
  constexpr Camera a(1, 3, 2);
  REQUIRE(a.viewport_width() == 3);
}

TEST_CASE("camera_viewport_height")
{
  constexpr Camera a(1, 3, 2);
  REQUIRE(a.viewport_height() == 2);
}