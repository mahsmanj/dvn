#include <gtest/gtest.h>

#include <dvn/qty/length.h>

using namespace dvn::qty;

namespace {

TEST(length, should_convert_meters_to_kilometers)
{
	meters length(1000.0f);
	kilometers expected(1.0f);
	kilometers actual = convert<kilometers>(length);
	EXPECT_FLOAT_EQ(expected.value(), actual.value());
}

}
