#ifndef DVN_MATH_VEC3_H
#define DVN_MATH_VEC3_H

#include <dvn/math/scalar.h>
#include <dvn/math/vec2.h>

namespace dvn {
namespace math {

/**
 * A three-dimensional vector class.
 */
template <class scalar>
struct vec3_t
{
	vec3_t(scalar in_x, scalar in_y, scalar in_z);
	vec3_t(const vec2_t<scalar>& in_xy, scalar in_z);

	inline bool operator==(const vec3_t& right) const;
	inline vec3_t operator+(const vec3_t& right) const;
	inline vec3_t operator-(const vec3_t& right) const;
	inline vec3_t operator*(scalar right) const;

	scalar x;
	scalar y;
	scalar z;
};

template <class scalar>
inline scalar dot(const vec3_t<scalar>& left, const vec3_t<scalar>& right);

template <class scalar>
inline vec3_t<scalar> cross(
	const vec3_t<scalar>& left,
	const vec3_t<scalar>& right);

template <class scalar>
vec3_t<scalar> operator*(scalar left, const vec3_t<scalar>& right);

typedef vec3_t<scalar> vec3;
typedef vec3_t<float> vec3f;
typedef vec3_t<double> vec3d;

template <class scalar>
vec3_t<scalar>::vec3_t(scalar in_x, scalar in_y, scalar in_z)
	: x(in_x)
	, y(in_y)
	, z(in_z)
{
}

template <class scalar>
vec3_t<scalar>::vec3_t(const vec2_t<scalar>& in_xy, scalar in_z)
	: x(in_xy.x)
	, y(in_xy.y)
	, z(in_z)
{
}

template <class scalar>
bool vec3_t<scalar>::operator==(const vec3_t& right) const
{
	return x == right.x && y == right.y && z == right.z;
}

template <class scalar>
vec3_t<scalar> vec3_t<scalar>::operator+(const vec3_t& right) const
{
	return vec3_t(x + right.x, y + right.y, z + right.z);
}

template <class scalar>
vec3_t<scalar> vec3_t<scalar>::operator-(const vec3_t& right) const
{
	return vec3_t(x - right.x, y - right.y, z - right.z);
}

template <class scalar>
vec3_t<scalar> vec3_t<scalar>::operator*(scalar right) const
{
	return vec3_t(x * right, y * right, z * right);
}

template <class scalar>
scalar dot(const vec3_t<scalar>& left, const vec3_t<scalar>& right)
{
	return left.x * right.x + left.y * right.y + left.z * right.z;
}

template <class scalar>
inline vec3_t<scalar> cross(
	const vec3_t<scalar>& left,
	const vec3_t<scalar>& right)
{
	return vec3_t<scalar>(
		left.y * right.z - left.z * right.y,
		left.z * right.x - left.x * right.z,
		left.x * right.y - left.y * right.x);
}

template <class scalar>
inline vec3_t<scalar> operator*(scalar left, const vec3_t<scalar>& right)
{
	return vec3_t<scalar>(left * right.x, left * right.y, left * right.z);
}

} // dvn
} // math

#endif
