#ifndef DVN_QTY_LENGTH_H
#define DVN_QTY_LENGTH_H

#include <dvn/qty/quantity.h>

namespace dvn {
namespace qty {

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
	template <class derived_unit, class real>
	inline static real per();

	template <>
	inline static real per<meter, real>()
	{
		return static_cast<real>(1.0);
	}

	template <>
	inline static real per<kilometer, real>()
	{
		return static_cast<real>(1000.0);
	}
};

typedef quantity<length, meter, real> meters;
typedef quantity<length, kilometer, real> kilometers;

} // qty
} // dvn

#endif
