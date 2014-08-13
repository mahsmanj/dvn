#ifndef DVN_QTY_QUANTITY_H
#define DVN_QTY_QUANTITY_H

#include <dvn/qty/real.h>

namespace dvn {
namespace qty {

template <class base_unit, class derived_unit, class real>
class quantity
{
public:
	typedef derived_unit unit;

	explicit quantity(real in_value);

	template <class denominator_quantity>
	inline static real per();

	inline quantity operator+(quantity right) const;
	inline quantity operator-(quantity right) const;
	inline quantity operator*(real right) const;
	inline quantity operator/(real right) const;

	inline real value() const;

private:
	real _value;
};

template <class base_unit, class derived_unit, class real>
inline typename quantity<base_unit, derived_unit, real> operator*(
	real left,
	quantity<base_unit, derived_unit, real> right);

template <class base_unit, class derived_unit, class real>
inline typename quantity<base_unit, derived_unit, real> operator/(
	real left,
	quantity<base_unit, derived_unit, real> right);

template <class target_quantity, class source_quantity>
target_quantity convert(source_quantity s);

#define DVN_TEMPLATE template <class base_unit, class derived_unit, class real>
#define DVN_TYPENAME typename quantity<base_unit, derived_unit, real>
#define DVN_CLASS quantity<base_unit, derived_unit, real>

DVN_TEMPLATE
DVN_CLASS::quantity(real in_value)
{
	_value = in_value;
}

DVN_TEMPLATE
template <class denominator_quantity>
inline static real DVN_CLASS::per()
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
DVN_TYPENAME DVN_CLASS::operator*(real right) const
{
	return _value * right;
}

DVN_TEMPLATE
DVN_TYPENAME DVN_CLASS::operator/(real right) const
{
	return _value / right;
}

DVN_TEMPLATE
inline real DVN_CLASS::value() const
{
	return _value;
}

DVN_TEMPLATE
inline DVN_TYPENAME operator*(real left, DVN_CLASS right)
{
	return DVN_TYPENAME(left * right.value());
}

DVN_TEMPLATE
inline DVN_TYPENAME operator/(real left, DVN_CLASS right)
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
