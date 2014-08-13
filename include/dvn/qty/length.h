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

template <class real>
class length
{
public:
	template <class derived_unit>
	inline static real per();

	template <>
	inline static real per<meter>()
	{
		return static_cast<real>(1.0);
	}

	template <>
	inline static real per<kilometer>()
	{
		return static_cast<real>(1000.0);
	}
};

typedef quantity<length<real>, meter, real> meters;
typedef quantity<length<float>, meter, float> metersf;
typedef quantity<length<double>, meter, double> metersd;

typedef quantity<length<real>, kilometer, real> kilometers;
typedef quantity<length<float>, kilometer, float> kilometersf;
typedef quantity<length<double>, kilometer, double> kilometersd;

} // qty
} // dvn

#endif
