#include <catch2/catch_test_macros.hpp>

#include <rt/vec3.hpp>

using rt::Vec3;

TEST_CASE("vec3_x")
{
  constexpr Vec3 a(1, 2, 3);
  STATIC_REQUIRE(a.x() == 1);
}

TEST_CASE("vec3_y")
{
  constexpr Vec3 a(1, 2, 3);
  STATIC_REQUIRE(a.y() == 2);
}

TEST_CASE("vec3_z")
{
  constexpr Vec3 a(1, 2, 3);
  STATIC_REQUIRE(a.z() == 3);
}

TEST_CASE("vec3_cross")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  constexpr auto c = Vec3::Cross(a, b);
  STATIC_REQUIRE(c.x() == -3);
  STATIC_REQUIRE(c.y() == 6);
  STATIC_REQUIRE(c.z() == -3);
}

TEST_CASE("vec3_dot")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  STATIC_REQUIRE(Vec3::Dot(a, b) == 32);
}

TEST_CASE("vec3_norm")
{
  constexpr Vec3 a(2, 2, 1);
  REQUIRE(Vec3::Norm(a) == 3);
}

TEST_CASE("vec3_norm_squared")
{
  constexpr Vec3 a(1, 2, 3);
  STATIC_REQUIRE(Vec3::NormSquared(a) == 14);
}

TEST_CASE("vec3_normalized")
{
  constexpr Vec3 a(1, 2, 2);
  const auto b = Vec3::Normalized(a);
  REQUIRE(b.x() == 1.0 / 3.0);
  REQUIRE(b.y() == 2.0 / 3.0);
  REQUIRE(b.z() == 2.0 / 3.0);
}

TEST_CASE("vec3_operator_add")
{
  constexpr Vec3 a(1, 2, 3);
  constexpr Vec3 b(4, 5, 6);
  constexpr auto c = a + b;
  STATIC_REQUIRE(c.x() == 5);
  STATIC_REQUIRE(c.y() == 7);
  STATIC_REQUIRE(c.z() == 9);
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
  STATIC_REQUIRE(b.x() == 0.5);
  STATIC_REQUIRE(b.y() == 1);
  STATIC_REQUIRE(b.z() == 1.5);
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
  STATIC_REQUIRE(b.x() == 2);
  STATIC_REQUIRE(b.y() == 4);
  STATIC_REQUIRE(b.z() == 6);
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
  STATIC_REQUIRE(c.x() == -3);
  STATIC_REQUIRE(c.y() == -3);
  STATIC_REQUIRE(c.z() == -3);
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
  STATIC_REQUIRE(b.x() == -1);
  STATIC_REQUIRE(b.y() == -2);
  STATIC_REQUIRE(b.z() == -3);
}

TEST_CASE("vec3_operator_unary_minus_assign")
{
  Vec3 a(1, 2, 3);
  a = -a;
  REQUIRE(a.x() == -1);
  REQUIRE(a.y() == -2);
  REQUIRE(a.z() == -3);
}
