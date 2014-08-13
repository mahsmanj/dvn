#ifndef DVN_QTY_REAL_H
#define DVN_QTY_REAL_H

namespace dvn {
namespace qty {

#ifdef DVN_USE_DOUBLE_PRECISION
	typedef double real;
#else
	typedef float real;
#endif

} // qty
} // dvn

#endif
