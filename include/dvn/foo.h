#ifndef DVN_FOO_H
#define DVN_FOO_H

#ifdef _DVN_EXPORTING
	#define _DVN_EXPORT __declspec(dllexport)
#else
	#define _DVN_EXPORT __declspec(dllimport)
#endif

namespace dvn {

void foo();

} // dvn

#endif
