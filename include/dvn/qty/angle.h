#ifndef DVN_QTY_ANGLE_H
#define DVN_QTY_ANGLE_H

#include <dvn/qty/quantity.h>

namespace dvn {
namespace qty {

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
	template <class derived_unit, class real>
	inline static real per();

	template <>
	inline static real per<degree, real>()
	{
		return static_cast<real>(1.0);
	}

	template <>
	inline static real per<radian, real>()
	{
		return static_cast<real>(57.2957795131);
	}
};

typedef quantity<angle, degree, real> degrees;
typedef quantity<angle, radian, real> radians;

} // qty
} // dvn

#endif
