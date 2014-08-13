#include <gtest/gtest.h>

#include <dvn/math/vec2.h>

using namespace dvn::math;

namespace {

TEST(vec2, should_add_two_vectors)
{
	vec2 a(1.0f, 1.0f);
	vec2 b(1.0f, 2.0f);
	vec2 expected(2.0f, 3.0f);
	vec2 actual = a + b;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_subtract_two_vectors)
{
	vec2 a(1.0f, 1.0f);
	vec2 b(1.0f, 2.0f);
	vec2 expected(0.0f, -1.0f);
	vec2 actual = a - b;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_multiply_scalar_and_vector)
{
	vec2 a(1.0f, 2.0f);
	vec2 expected(2.0f, 4.0f);
	vec2 actual = 2.0f * a;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_multiply_vector_and_scalar)
{
	vec2 a(1.0f, 2.0f);
	vec2 expected(2.0f, 4.0f);
	vec2 actual = a * 2.0f;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_take_dot_product_of_two_vectors)
{
	vec2 a(1.0f, 1.0f);
	vec2 b(1.0f, 2.0f);
	scalar expected = 3.0f;
	scalar actual = dot(a, b);
	EXPECT_EQ(expected, actual);
}

}
