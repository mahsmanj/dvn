#ifndef DVN_MATH_CONSTANTS_H
#define DVN_MATH_CONSTANTS_H

#include <dvn/math/scalar.h>

namespace dvn {
namespace math {

template <class scalar>
class constants
{
public:
	inline static scalar pi();
	inline static scalar two_pi();
	inline static scalar degrees_per_radian();
	inline static scalar radians_per_degree();
};

template <class scalar>
scalar constants<scalar>::pi()
{
	return static_cast<scalar>(3.141592653689793);
}

template <class scalar>
scalar constants<scalar>::two_pi()
{
	return static_cast<scalar>(2.0 * pi());
}

template <class scalar>
scalar constants<scalar>::degrees_per_radian()
{
	return static_cast<scalar>(180.0 / pi());
}

template <class scalar>
scalar constants<scalar>::radians_per_degree()
{
	return static_cast<scalar>(pi() / 180.0);
}

} // math
} // dvn

#endif
