#include <catch2/catch_test_macros.hpp>

#include <rt/vec3.hpp>

using rt::Vec3f;

TEST_CASE("vec3_x")
{
  constexpr Vec3f a(1, 2, 3);
  STATIC_REQUIRE(a.x() == 1.f);
}

TEST_CASE("vec3_y")
{
  constexpr Vec3f a(1, 2, 3);
  STATIC_REQUIRE(a.y() == 2.f);
}

TEST_CASE("vec3_z")
{
  constexpr Vec3f a(1, 2, 3);
  STATIC_REQUIRE(a.z() == 3.f);
}

TEST_CASE("vec3_cross")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr Vec3f b(4, 5, 6);
  constexpr auto c = a.Cross(b);
  STATIC_REQUIRE(c.x() == -3.f);
  STATIC_REQUIRE(c.y() == 6.f);
  STATIC_REQUIRE(c.z() == -3.f);
}

TEST_CASE("vec3_dot")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr Vec3f b(4, 5, 6);
  STATIC_REQUIRE(a.Dot(b) == 32.f);
}

TEST_CASE("vec3_norm")
{
  constexpr Vec3f a(2, 2, 1);
  REQUIRE(a.Norm() == 3.f);
}

TEST_CASE("vec3_norm_squared")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr auto b = a.NormSquared();
  STATIC_REQUIRE(b == 14.f);
}

TEST_CASE("vec3_normalized")
{
  constexpr Vec3f a(1, 2, 2);
  auto b = a.Normalized();
  REQUIRE(b.x() == 1.f / 3.f);
  REQUIRE(b.y() == 2.f / 3.f);
  REQUIRE(b.z() == 2.f / 3.f);
}

TEST_CASE("vec3_operator_add")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr Vec3f b(4, 5, 6);
  constexpr auto c = a + b;
  STATIC_REQUIRE(c.x() == 5.f);
  STATIC_REQUIRE(c.y() == 7.f);
  STATIC_REQUIRE(c.z() == 9.f);
}

TEST_CASE("vec3_operator_add_assign")
{
  Vec3f a(1, 2, 3);
  constexpr Vec3f b(4, 5, 6);
  a += b;
  REQUIRE(a.x() == 5.f);
  REQUIRE(a.y() == 7.f);
  REQUIRE(a.z() == 9.f);
}

TEST_CASE("vec3_operator_divide")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr auto b = a / 2;
  STATIC_REQUIRE(b.x() == 0.5f);
  STATIC_REQUIRE(b.y() == 1.f);
  STATIC_REQUIRE(b.z() == 1.5f);
}

TEST_CASE("vec3_operator_divide_assign")
{
  Vec3f a(1, 2, 3);
  a /= 2;
  REQUIRE(a.x() == 0.5f);
  REQUIRE(a.y() == 1.f);
  REQUIRE(a.z() == 1.5f);
}

TEST_CASE("vec3_operator_multiply")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr auto b = a * 2;
  STATIC_REQUIRE(b.x() == 2.f);
  STATIC_REQUIRE(b.y() == 4.f);
  STATIC_REQUIRE(b.z() == 6.f);
}

TEST_CASE("vec3_operator_multiply_assign")
{
  Vec3f a(1, 2, 3);
  a *= 2.f;
  REQUIRE(a.x() == 2.f);
  REQUIRE(a.y() == 4.f);
  REQUIRE(a.z() == 6.f);
}

TEST_CASE("vec3_operator_subtract")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr Vec3f b(4, 5, 6);
  constexpr auto c = a - b;
  STATIC_REQUIRE(c.x() == -3.f);
  STATIC_REQUIRE(c.y() == -3.f);
  STATIC_REQUIRE(c.z() == -3.f);
}

TEST_CASE("vec3_operator_subtract_assign")
{
  Vec3f a(1, 2, 3);
  constexpr Vec3f b(4, 5, 6);
  a -= b;
  REQUIRE(a.x() == -3.f);
  REQUIRE(a.y() == -3.f);
  REQUIRE(a.z() == -3.f);
}

TEST_CASE("vec3_operator_unary_minus")
{
  constexpr Vec3f a(1, 2, 3);
  constexpr auto b = -a;
  STATIC_REQUIRE(b.x() == -1.f);
  STATIC_REQUIRE(b.y() == -2.f);
  STATIC_REQUIRE(b.z() == -3.f);
}

TEST_CASE("vec3_operator_unary_minus_assign")
{
  Vec3f a(1, 2, 3);
  a = -a;
  REQUIRE(a.x() == -1.f);
  REQUIRE(a.y() == -2.f);
  REQUIRE(a.z() == -3.f);
}
