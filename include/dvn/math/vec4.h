#ifndef DVN_MATH_VEC4_H
#define DVN_MATH_VEC4_H

#include <dvn/math/scalar.h>
#include <dvn/math/vec3.h>

namespace dvn {
namespace math {

/**
 * A three-dimensional vector class.
 */
template <class scalar>
struct vec4_t
{
	vec4_t(scalar in_x, scalar in_y, scalar in_z, scalar in_w);
	vec4_t(const vec3_t<scalar>& in_xyz, scalar in_w);

	vec3_t<scalar> xyz() const;

	inline bool operator==(const vec4_t& right) const;
	inline vec4_t operator+(const vec4_t& right) const;
	inline vec4_t operator-(const vec4_t& right) const;
	inline vec4_t operator*(scalar right) const;

	scalar x;
	scalar y;
	scalar z;
	scalar w;
};

template <class scalar>
inline scalar dot(const vec4_t<scalar>& left, const vec4_t<scalar>& right);

template <class scalar>
vec4_t<scalar> operator*(scalar left, const vec4_t<scalar>& right);

typedef vec4_t<scalar> vec4;
typedef vec4_t<float> vec4f;
typedef vec4_t<double> vec4d;

template <class scalar>
vec4_t<scalar>::vec4_t(scalar in_x, scalar in_y, scalar in_z, scalar in_w)
	: x(in_x)
	, y(in_y)
	, z(in_z)
	, w(in_w)
{
}

template <class scalar>
vec4_t<scalar>::vec4_t(const vec3_t<scalar>& in_xyz, scalar in_w)
	: x(in_xyz.x)
	, y(in_xyz.y)
	, z(in_xyz.z)
	, w(in_w)
{
}

template <class scalar>
vec3_t<scalar> vec4_t<scalar>::xyz() const
{
	return vec3_t<scalar>(x, y, z);
}

template <class scalar>
bool vec4_t<scalar>::operator==(const vec4_t& right) const
{
	return x == right.x && y == right.y && z == right.z && w == right.w;
}

template <class scalar>
vec4_t<scalar> vec4_t<scalar>::operator+(const vec4_t& right) const
{
	return vec4_t(x + right.x, y + right.y, z + right.z, w + right.w);
}

template <class scalar>
vec4_t<scalar> vec4_t<scalar>::operator-(const vec4_t& right) const
{
	return vec4_t(x - right.x, y - right.y, z - right.z, w - right.w);
}

template <class scalar>
vec4_t<scalar> vec4_t<scalar>::operator*(scalar right) const
{
	return vec4_t(x * right, y * right, z * right, w * right);
}

template <class scalar>
scalar dot(const vec4_t<scalar>& left, const vec4_t<scalar>& right)
{
	return left.x * right.x +
	       left.y * right.y +
	       left.z * right.z +
	       left.w * right.w;
}

template <class scalar>
inline vec4_t<scalar> operator*(scalar left, const vec4_t<scalar>& right)
{
	return vec4_t<scalar>(
		left * right.x,
		left * right.y,
		left * right.z,
		left * right.w);
}

} // dvn
} // math

#endif
