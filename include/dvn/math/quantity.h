#ifndef DVN_QUANTITY_H
#define DVN_QUANTITY_H

#include <dvn/math/constants.h>
#include <dvn/math/scalar.h>

namespace dvn {
namespace math {

template <class source_unit>
struct quantity
{
	explicit quantity(scalar in_value)
	{
		value = in_value;
	}

	template <class target_unit>
	inline static scalar per()
	{
		return target_unit::per<source_unit>();
	}

	inline quantity operator+(quantity right) const;
	inline quantity operator-(quantity right) const;
	inline quantity operator*(scalar right) const;
	inline quantity operator/(scalar right) const;

	scalar value;
};

template <class target, class source>
target convert_to(source s);

class radian;

class degree
{
public:
	template <class target>
	inline static scalar per();

	template <>
	inline static scalar per<radian>()
	{
		return DEGREES_PER_RADIAN;
	}
};

class radian
{
public:
	template <class target>
	inline static scalar per();

	template <>
	inline static scalar per<degree>()
	{
		return RADIANS_PER_DEGREE;
	}
};

typedef quantity<degree> degrees;
typedef quantity<radian> radians;


template <class source>
quantity<source> quantity<source>::operator+(quantity right) const
{
	return value + right.value;
}

template <class source>
quantity<source> quantity<source>::operator-(quantity right) const
{
	return value - right.value;
}

template <class source>
quantity<source> quantity<source>::operator*(scalar right) const
{
	return value * right;
}

template <class source>
quantity<source> quantity<source>::operator/(scalar right) const
{
	return value / right;
}

template <class target_quantity, class source_quantity>
target_quantity convert_to(source_quantity s)
{
	return target_quantity(s.value * target_quantity::per<source_quantity>());
}

} // math
} // dvn

#endif
