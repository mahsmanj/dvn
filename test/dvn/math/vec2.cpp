#include <gtest/gtest.h>

#include <dvn/math/vec2.h>

using namespace dvn::math;

namespace {

TEST(vec2, should_add_two_vectors)
{
	vec2 a(1, 1);
	vec2 b(1, 2);
	vec2 expected(2, 3);
	vec2 actual = a + b;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_subtract_two_vectors)
{
	vec2 a(1, 1);
	vec2 b(1, 2);
	vec2 expected(2, 3);
	vec2 actual = a + b;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_multiply_scalar_and_vector)
{
	vec2 a(1, 2);
	vec2 expected(2, 4);
	vec2 actual = 2 * a;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_multiply_vector_and_scalar)
{
	vec2 a(1, 2);
	vec2 expected(2, 4);
	vec2 actual = a * 2;
	EXPECT_EQ(expected, actual);
}

TEST(vec2, should_take_dot_product_of_two_vectors)
{
	vec2 a(1, 1);
	vec2 b(1, 2);
	scalar expected = 3;
	scalar actual = dot(a, b);
	EXPECT_EQ(expected, actual);
}

}
