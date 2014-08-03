#include <gtest/gtest.h>
#include <dvn/foo.h>

namespace {

TEST(FooTest, DoesXYZ)
{
	dvn::foo();
	EXPECT_EQ(1, 1);
}

TEST(FooTest, DoesABC)
{
	dvn::foo();
	EXPECT_EQ(1, 0);
}

}
