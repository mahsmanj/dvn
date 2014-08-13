#ifndef DVN_MATH_VEC2_H
#define DVN_MATH_VEC2_H

#include <dvn/math/scalar.h>

namespace dvn {
namespace math {

/**
 * A two-dimensional vector class.
 */
template <class scalar>
struct vec2_t
{
	vec2_t(scalar in_x, scalar in_y);

	inline bool operator==(const vec2_t& right) const;
	inline vec2_t operator+(const vec2_t& right) const;
	inline vec2_t operator-(const vec2_t& right) const;
	inline vec2_t operator*(scalar right) const;

	scalar x;
	scalar y;
};

template <class scalar>
inline scalar dot(const vec2_t<scalar>& left, const vec2_t<scalar>& right);

template <class scalar>
vec2_t<scalar> operator*(scalar left, const vec2_t<scalar>& right);

typedef vec2_t<scalar> vec2;
typedef vec2_t<float> vec2f;
typedef vec2_t<double> vec2d;

template <class scalar>
vec2_t<scalar>::vec2_t(scalar in_x, scalar in_y)
	: x(in_x)
	, y(in_y)
{
}

template <class scalar>
bool vec2_t<scalar>::operator==(const vec2_t& right) const
{
	return x == right.x && y == right.y;
}

template <class scalar>
vec2_t<scalar> vec2_t<scalar>::operator+(const vec2_t& right) const
{
	return vec2_t(x + right.x, y + right.y);
}

template <class scalar>
vec2_t<scalar> vec2_t<scalar>::operator-(const vec2_t& right) const
{
	return vec2_t(x - right.x, y - right.y);
}

template <class scalar>
vec2_t<scalar> vec2_t<scalar>::operator*(scalar right) const
{
	return vec2_t(x * right, y * right);
}

template <class scalar>
scalar dot(const vec2_t<scalar>& left, const vec2_t<scalar>& right)
{
	return left.x * right.x + left.y * right.y;
}

template <class scalar>
inline vec2_t<scalar> operator*(scalar left, const vec2_t<scalar>& right)
{
	return vec2_t<scalar>(left * right.x, left * right.y);
}

} // dvn
} // math

#endif
