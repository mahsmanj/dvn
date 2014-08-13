#ifndef DVN_MATH_SCALAR_H
#define DVN_MATH_SCALAR_H

namespace dvn {
namespace math {

#ifdef DVN_USE_DOUBLE_PRECISION_SCALAR
	typedef double scalar;
#else
	typedef float scalar;
#endif

} // math
} // dvn

#endif
