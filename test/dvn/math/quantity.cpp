#include <gtest/gtest.h>

#include <dvn/math/quantity.h>

using namespace dvn::math;

namespace {

TEST(quantity, should_convert_radians_to_degrees)
{
	radians angle(TWO_PI);
	degrees expected(360.0f);
	degrees actual = convert<degrees>(angle);
	EXPECT_FLOAT_EQ(expected.value(), actual.value());
}

TEST(quantity, should_convert_degrees_to_radians)
{
	degrees angle(360.0f);
	radians expected(TWO_PI);
	radians actual = convert<radians>(angle);
	EXPECT_FLOAT_EQ(expected.value(), actual.value());
}

TEST(quantity, should_convert_meters_to_kilometers)
{
	meters length(1000.0f);
	kilometers expected(1.0f);
	kilometers actual = convert<kilometers, meters>(length);
	EXPECT_FLOAT_EQ(expected.value(), actual.value());
}

}
