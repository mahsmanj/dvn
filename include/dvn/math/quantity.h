#ifndef DVN_MATH_QUANTITY_H
#define DVN_MATH_QUANTITY_H

#include <iostream>
#include <dvn/math/constants.h>
#include <dvn/math/scalar.h>

namespace dvn {
namespace math {

template <class base_unit, class derived_unit>
class quantity
{
public:
	typedef derived_unit unit;

	explicit quantity(scalar in_value);

	template <class denominator_quantity>
	inline static scalar per();

	inline quantity operator+(quantity right) const;
	inline quantity operator-(quantity right) const;
	inline quantity operator*(scalar right) const;
	inline quantity operator/(scalar right) const;

	inline scalar value() const;

private:
	scalar _value;
};

template <class base_unit, class derived_unit>
inline typename quantity<base_unit, derived_unit> operator*(
	scalar left,
	quantity<base_unit, derived_unit> right);

template <class base_unit, class derived_unit>
inline typename quantity<base_unit, derived_unit> operator/(
	scalar left,
	quantity<base_unit, derived_unit> right);

template <class target_quantity, class source_quantity>
target_quantity convert(source_quantity s);

class degree
{
public:
	static const char* name()
	{
		return "degree";
	}
};

class radian
{
public:
	static const char* name()
	{
		return "radian";
	}
};

class angle
{
public:
	template <class derived_unit>
	inline static scalar per();

	template <>
	inline static scalar per<degree>()
	{
		return 1.0f;
	}

	template <>
	inline static scalar per<radian>()
	{
		return DEGREES_PER_RADIAN;
	}
};

typedef quantity<angle, degree> degrees;
typedef quantity<angle, radian> radians;

class meter
{
public:
	static const char* name()
	{
		return "meter";
	}
};

class kilometer
{
public:
	static const char* name()
	{
		return "kilometer";
	}
};

class length
{
public:
	template <class derived_unit>
	inline static scalar per();

	template <>
	inline static scalar per<meter>()
	{
		return 1.0f;
	}

	template <>
	inline static scalar per<kilometer>()
	{
		return 1000.0f;
	}
};

typedef quantity<length, meter> meters;
typedef quantity<length, kilometer> kilometers;

#define DVN_TEMPLATE template <class base_unit, class derived_unit>
#define DVN_TYPENAME typename quantity<base_unit, derived_unit>
#define DVN_CLASS quantity<base_unit, derived_unit>

DVN_TEMPLATE
DVN_CLASS::quantity(scalar in_value)
{
	_value = in_value;
}

DVN_TEMPLATE
template <class denominator_quantity>
inline static scalar DVN_CLASS::per()
{
	typedef unit numerator_unit;
	typedef denominator_quantity::unit denominator_unit;

	// The result is a conversion factor: numerator units per denominator unit
	return base_unit::per<denominator_unit>() /
	       base_unit::per<numerator_unit>();
}

DVN_TEMPLATE
DVN_TYPENAME DVN_CLASS::operator+(DVN_CLASS right) const
{
	return _value + right.value();
}

DVN_TEMPLATE
DVN_TYPENAME DVN_CLASS::operator-(DVN_CLASS right) const
{
	return _value - right.value();
}

DVN_TEMPLATE
DVN_TYPENAME DVN_CLASS::operator*(scalar right) const
{
	return _value * right;
}

DVN_TEMPLATE
DVN_TYPENAME DVN_CLASS::operator/(scalar right) const
{
	return _value / right;
}

DVN_TEMPLATE
inline scalar DVN_CLASS::value() const
{
	return _value;
}

DVN_TEMPLATE
inline DVN_TYPENAME operator*(scalar left, DVN_CLASS right)
{
	return DVN_TYPENAME(left * right.value());
}

DVN_TEMPLATE
inline DVN_TYPENAME operator/(scalar left, DVN_CLASS right)
{
	return DVN_TYPENAME(left * right.value());
}

template <class target_quantity, class source_quantity>
target_quantity convert(source_quantity s)
{
	return target_quantity(s.value() * target_quantity::per<source_quantity>());
}

#undef DVN_TEMPLATE
#undef DVN_TYPENAME
#undef DVN_CLASS

} // math
} // dvn

#endif
