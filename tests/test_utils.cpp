#include <catch2/catch_test_macros.hpp>

#include <rt/utils.hpp>

using rt::utils::Clamp;
using rt::utils::DegreesToRadians;

constexpr bool ApproxEquals(double a, double b, double e) { return std::fabs(a - b) < e; }

TEST_CASE("utils_degrees_to_radians")
{
  REQUIRE(DegreesToRadians(0) == 0);
  REQUIRE(DegreesToRadians(180) == rt::utils::kPi);
  REQUIRE(DegreesToRadians(360) == 2 * rt::utils::kPi);
  REQUIRE(ApproxEquals(DegreesToRadians(50), 0.8726646259971648, 1e-6));
  REQUIRE(ApproxEquals(DegreesToRadians(80), 1.3962634015954636, 1e-6));
}

TEST_CASE("utils_clamp")
{
  REQUIRE(Clamp(0, 0, 1) == 0);
  REQUIRE(Clamp(0.5, 0, 1) == 0.5);
  REQUIRE(Clamp(1, 0, 1) == 1);
  REQUIRE(Clamp(1.5, 0, 1) == 1);
}