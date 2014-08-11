#ifndef DVN_QUANTITY_H
#define DVN_QUANTITY_H

#include <iostream>
#include <dvn/math/constants.h>
#include <dvn/math/scalar.h>

namespace dvn {
namespace math {

#define _TEMPLATE template <class base_unit, class derived_unit>
#define _QUANTITY typename quantity<base_unit, derived_unit>

_TEMPLATE
class quantity
{
public:
	typedef derived_unit unit;

	explicit quantity(scalar in_value)
	{
		_value = in_value;
	}

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

_TEMPLATE
template <class denominator_quantity>
inline static scalar _QUANTITY::per()
{
	typedef unit numerator_unit;
	typedef denominator_quantity::unit denominator_unit;

	// The result is a conversion factor: numerator units per denominator unit
	return base_unit::per<denominator_unit>() /
	       base_unit::per<numerator_unit>();
}

_TEMPLATE
inline _QUANTITY operator*(scalar left, _QUANTITY right);

_TEMPLATE
inline _QUANTITY operator/(scalar left, _QUANTITY right);

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

_TEMPLATE
_QUANTITY _QUANTITY::operator+(_QUANTITY right) const
{
	return _value + right.value();
}

_TEMPLATE
_QUANTITY _QUANTITY::operator-(_QUANTITY right) const
{
	return _value - right.value();
}

_TEMPLATE
_QUANTITY _QUANTITY::operator*(scalar right) const
{
	return _value * right;
}

_TEMPLATE
_QUANTITY _QUANTITY::operator/(scalar right) const
{
	return _value / right;
}

_TEMPLATE
inline scalar _QUANTITY::value() const
{
	return _value;
}

_TEMPLATE
inline _QUANTITY operator*(scalar left, _QUANTITY right)
{
	return _QUANTITY(left * right.value());
}

_TEMPLATE
inline _QUANTITY operator/(scalar left, _QUANTITY right)
{
	return _QUANTITY(left * right.value());
}

template <class target_quantity, class source_quantity>
target_quantity convert(source_quantity s)
{
	return target_quantity(s.value() * target_quantity::per<source_quantity>());
}

} // math
} // dvn

#endif
