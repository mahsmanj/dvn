#ifndef DVN_MATH_SCALAR_H
#define DVN_MATH_SCALAR_H

namespace dvn {
namespace math {

#ifndef DVN_USE_DOUBLE_PRECISION_SCALAR
	typedef float scalar;
#else
	typedef double scalar;
#endif

} // math
} // dvn

#endif
