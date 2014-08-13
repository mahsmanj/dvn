#include <gtest/gtest.h>

#include <dvn/math/vec3.h>

using namespace dvn::math;

namespace {

TEST(vec3, should_add_two_vectors)
{
	vec3 a(1.0f, 1.0f, 1.0f);
	vec3 b(1.0f, 2.0f, 3.0f);
	vec3 expected(2.0f, 3.0f, 4.0f);
	vec3 actual = a + b;
	EXPECT_EQ(expected, actual);
}

TEST(vec3, should_subtract_two_vectors)
{
	vec3 a(1.0f, 1.0f, 1.0f);
	vec3 b(1.0f, 2.0f, 3.0f);
	vec3 expected(0.0f, -1.0f, -2.0f);
	vec3 actual = a - b;
	EXPECT_EQ(expected, actual);
}

TEST(vec3, should_multiply_scalar_and_vector)
{
	vec3 a(1.0f, 2.0f, 3.0f);
	vec3 expected(2.0f, 4.0f, 6.0f);
	vec3 actual = 2.0f * a;
	EXPECT_EQ(expected, actual);
}

TEST(vec3, should_multiply_vector_and_scalar)
{
	vec3 a(1.0f, 2.0f, 3.0f);
	vec3 expected(2.0f, 4.0f, 6.0f);
	vec3 actual = a * 2.0f;
	EXPECT_EQ(expected, actual);
}

TEST(vec3, should_take_dot_product_of_two_vectors)
{
	vec3 a(1.0f, 1.0f, 1.0f);
	vec3 b(1.0f, 2.0f, 3.0f);
	scalar expected = 6.0f;
	scalar actual = dot(a, b);
	EXPECT_EQ(expected, actual);
}

TEST(vec3, should_take_cross_product_of_two_vectors)
{
	vec3 a(1.0f, 0.0f, 0.0f);
	vec3 b(0.0f, 1.0f, 0.0f);
	vec3 expected(0.0f, 0.0f, 1.0f);
	vec3 actual = cross(a, b);
	EXPECT_EQ(expected, actual);
}

}
