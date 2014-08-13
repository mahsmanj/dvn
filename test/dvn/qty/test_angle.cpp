#include <gtest/gtest.h>

#include <dvn/qty/angle.h>
#include <dvn/math/constants.h>

using namespace dvn::qty;
using namespace dvn::math;

namespace {

TEST(angle, should_convert_radians_to_degrees)
{
	radians angle(constants<scalar>::two_pi());
	degrees expected(360.0f);
	degrees actual = convert<degrees>(angle);
	EXPECT_FLOAT_EQ(expected.value(), actual.value());
}

TEST(angle, should_convert_degrees_to_radians)
{
	degrees angle(360.0f);
	radians expected(constants<real>::two_pi());
	radians actual = convert<radians>(angle);
	EXPECT_FLOAT_EQ(expected.value(), actual.value());
}

TEST(angle, should_convert_radians_to_degrees_using_doubles)
{
	radiansd angle(constants<double>::two_pi());
	degreesd expected(360.0);
	degreesd actual = convert<degreesd>(angle);
	EXPECT_NEAR(expected.value(), actual.value(), 0.0000001);
}

}
