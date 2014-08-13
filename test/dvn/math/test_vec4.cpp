#include <gtest/gtest.h>

#include <dvn/math/vec4.h>

using namespace dvn::math;

namespace {

TEST(vec4, should_add_two_vectors)
{
	vec4 a(1.0f, 1.0f, 1.0f, 1.0f);
	vec4 b(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 expected(2.0f, 3.0f, 4.0f, 5.0f);
	vec4 actual = a + b;
	EXPECT_EQ(expected, actual);
}

TEST(vec4, should_subtract_two_vectors)
{
	vec4 a(1.0f, 1.0f, 1.0f, 1.0f);
	vec4 b(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 expected(0.0f, -1.0f, -2.0f, -3.0f);
	vec4 actual = a - b;
	EXPECT_EQ(expected, actual);
}

TEST(vec4, should_multiply_scalar_and_vector)
{
	vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 expected(2.0f, 4.0f, 6.0f, 8.0f);
	vec4 actual = 2.0f * a;
	EXPECT_EQ(expected, actual);
}

TEST(vec4, should_multiply_vector_and_scalar)
{
	vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
	vec4 expected(2.0f, 4.0f, 6.0f, 8.0f);
	vec4 actual = a * 2.0f;
	EXPECT_EQ(expected, actual);
}

TEST(vec4, should_take_dot_product_of_two_vectors)
{
	vec4 a(1.0f, 1.0f, 1.0f, 1.0f);
	vec4 b(1.0f, 2.0f, 3.0f, 4.0f);
	scalar expected = 10.0f;
	scalar actual = dot(a, b);
	EXPECT_EQ(expected, actual);
}

}
