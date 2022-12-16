#include <cassert>

#include "../vec3.hpp"

using rt::Vec3;

void test_vec3_cross()
{
  Vec3 a(1, 2, 3);
  Vec3 b(4, 5, 6);
  Vec3 c = a.Cross(b);
  assert(c.x() == -3);
  assert(c.y() == 6);
  assert(c.z() == -3);
}

void test_vec3_dot()
{
  Vec3 a(1, 2, 3);
  Vec3 b(4, 5, 6);
  double c = a.Dot(b);
  assert(c == 32);
}

void test_vec3_norm()
{
  Vec3 a(1, 2, 3);
  double b = a.Norm();
  assert(b == std::sqrt(14));
}

void test_vec3_norm_squared()
{
  Vec3 a(1, 2, 3);
  double b = a.NormSquared();
  assert(b == 14);
}

void test_vec3_normalized()
{
  Vec3 a(1, 2, 3);
  Vec3 b = a.Normalized();
  assert(b.x() == 1 / std::sqrt(14));
  assert(b.y() == 2 / std::sqrt(14));
  assert(b.z() == 3 / std::sqrt(14));
}

void test_vec3_operator_add()
{
  Vec3 a(1, 2, 3);
  Vec3 b(4, 5, 6);
  Vec3 c = a + b;
  assert(c.x() == 5);
  assert(c.y() == 7);
  assert(c.z() == 9);
}

void test_vec3_operator_add_assign()
{
  Vec3 a(1, 2, 3);
  Vec3 b(4, 5, 6);
  a += b;
  assert(a.x() == 5);
  assert(a.y() == 7);
  assert(a.z() == 9);
}

void test_vec3_operator_divide()
{
  Vec3 a(1, 2, 3);
  Vec3 b = a / 2;
  assert(b.x() == 0.5);
  assert(b.y() == 1);
  assert(b.z() == 1.5);
}

void test_vec3_operator_divide_assign()
{
  Vec3 a(1, 2, 3);
  a /= 2;
  assert(a.x() == 0.5);
  assert(a.y() == 1);
  assert(a.z() == 1.5);
}

void test_vec3_operator_index()
{
  Vec3 a(1, 2, 3);
  assert(a[0] == 1);
  assert(a[1] == 2);
  assert(a[2] == 3);
}

void test_vec3_operator_multiply()
{
  Vec3 a(1, 2, 3);
  Vec3 b = a * 2;
  assert(b.x() == 2);
  assert(b.y() == 4);
  assert(b.z() == 6);
}

void test_vec3_operator_multiply_assign()
{
  Vec3 a(1, 2, 3);
  a *= 2;
  assert(a.x() == 2);
  assert(a.y() == 4);
  assert(a.z() == 6);
}

void test_vec3_operator_subtract()
{
  Vec3 a(1, 2, 3);
  Vec3 b(4, 5, 6);
  Vec3 c = a - b;
  assert(c.x() == -3);
  assert(c.y() == -3);
  assert(c.z() == -3);
}

void test_vec3_operator_subtract_assign()
{
  Vec3 a(1, 2, 3);
  Vec3 b(4, 5, 6);
  // a -= b;
  assert(a.x() == -3);
  assert(a.y() == -3);
  assert(a.z() == -3);
}

void test_vec3_operator_unary_minus()
{
  Vec3 a(1, 2, 3);
  Vec3 b = -a;
  assert(b.x() == -1);
  assert(b.y() == -2);
  assert(b.z() == -3);
}

void test_vec3_operator_unary_plus()
{
  Vec3 a(1, 2, 3);
  Vec3 b = /*+*/ a;
  assert(b.x() == 1);
  assert(b.y() == 2);
  assert(b.z() == 3);
}

void test_vec3()
{
  test_vec3_cross();
  test_vec3_dot();
  test_vec3_norm();
  test_vec3_norm_squared();
  test_vec3_normalized();
  test_vec3_operator_add();
  test_vec3_operator_add_assign();
  test_vec3_operator_divide();
  test_vec3_operator_divide_assign();
  test_vec3_operator_index();
  test_vec3_operator_multiply();
  test_vec3_operator_multiply_assign();
  test_vec3_operator_subtract();
  test_vec3_operator_subtract_assign();
  test_vec3_operator_unary_minus();
  test_vec3_operator_unary_plus();
}