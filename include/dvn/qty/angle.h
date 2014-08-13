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

template <class real>
class angle
{
public:
	template <class derived_unit>
	inline static real per();

	template <>
	inline static real per<degree>()
	{
		return static_cast<real>(1.0);
	}

	template <>
	inline static real per<radian>()
	{
		return static_cast<real>(57.295779513082320877);
	}
};

typedef quantity<angle<real>, degree, real> degrees;
typedef quantity<angle<float>, degree, float> degreesf;
typedef quantity<angle<double>, degree, double> degreesd;

typedef quantity<angle<real>, radian, real> radians;
typedef quantity<angle<float>, radian, float> radiansf;
typedef quantity<angle<double>, radian, double> radiansd;

} // qty
} // dvn

#endif
