#include <catch2/catch_test_macros.hpp>
#include <vec3.hpp>

using rt::Vec3;

TEST_CASE("vec3_x")
{
  constexpr Vec3 a(1, 2, 3);
  REQUIRE(a.x() == 1);
}

TEST_CASE("vec3_y")
{
  constexpr Vec3 a(1, 2, 3);
  REQUIRE(a.y() == 2);
}

TEST_CASE("vec3_z")
{
  constexpr Vec3 a(1, 2, 3);
  REQUIRE(a.z() == 3);
}

TEST_CASE("vec3_cross")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  constexpr auto c = a.Cross(b);
  REQUIRE(c.x() == -3);
  REQUIRE(c.y() == 6);
  REQUIRE(c.z() == -3);
}

TEST_CASE("vec3_dot")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  constexpr auto c = a.Dot(b);
  REQUIRE(c == 32);
}

TEST_CASE("vec3_norm")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr auto b = a.Norm();
  REQUIRE(b == std::sqrt(14));
}

TEST_CASE("vec3_norm_squared")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr auto b = a.NormSquared();
  REQUIRE(b == 14);
}

TEST_CASE("vec3_normalized")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr auto b = a.Normalized();
  REQUIRE(b.x() == 1 / std::sqrt(14));
  REQUIRE(b.y() == 2 / std::sqrt(14));
  REQUIRE(b.z() == 3 / std::sqrt(14));
}

TEST_CASE("vec3_operator_add")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  constexpr auto c = a + b;
  REQUIRE(c.x() == 5);
  REQUIRE(c.y() == 7);
  REQUIRE(c.z() == 9);
}

TEST_CASE("vec3_operator_add_assign")
{
  Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  a += b;
  REQUIRE(a.x() == 5);
  REQUIRE(a.y() == 7);
  REQUIRE(a.z() == 9);
}

TEST_CASE("vec3_operator_divide")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr auto b = a / 2;
  REQUIRE(b.x() == 0.5);
  REQUIRE(b.y() == 1);
  REQUIRE(b.z() == 1.5);
}

TEST_CASE("vec3_operator_divide_assign")
{
  Vec3 a(1, 2, 3);
  a /= 2;
  REQUIRE(a.x() == 0.5);
  REQUIRE(a.y() == 1);
  REQUIRE(a.z() == 1.5);
}

TEST_CASE("vec3_operator_multiply")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr auto b = a * 2;
  REQUIRE(b.x() == 2);
  REQUIRE(b.y() == 4);
  REQUIRE(b.z() == 6);
}

TEST_CASE("vec3_operator_multiply_assign")
{
  Vec3 a(1, 2, 3);
  a *= 2;
  REQUIRE(a.x() == 2);
  REQUIRE(a.y() == 4);
  REQUIRE(a.z() == 6);
}

TEST_CASE("vec3_operator_subtract")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  constexpr auto c = a - b;
  REQUIRE(c.x() == -3);
  REQUIRE(c.y() == -3);
  REQUIRE(c.z() == -3);
}

TEST_CASE("vec3_operator_subtract_assign")
{
  Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  a -= b;
  REQUIRE(a.x() == -3);
  REQUIRE(a.y() == -3);
  REQUIRE(a.z() == -3);
}

TEST_CASE("vec3_operator_unary_minus")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr auto b = -a;
  REQUIRE(b.x() == -1);
  REQUIRE(b.y() == -2);
  REQUIRE(b.z() == -3);
}