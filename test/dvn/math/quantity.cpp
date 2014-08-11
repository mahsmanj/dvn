#include <gtest/gtest.h>

#include <dvn/math/quantity.h>

using namespace dvn::math;

namespace {

TEST(quantity, should_convert_radians_to_degrees)
{
	radians angle(TWO_PI);
	degrees expected(360.0f);
	degrees actual = convert<degrees>(angle);
	EXPECT_FLOAT_EQ(expected.value, actual.value);
}

}
