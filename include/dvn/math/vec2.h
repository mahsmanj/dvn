#ifndef DVN_VEC2_H
#define DVN_VEC2_H

#include <dvn/math/real.h>

namespace dvn {
namespace math {

/**
 * A two-dimensional vector class.
 */
class vec2
{
public:
	vec2(real in_x, real in_y);

	inline bool operator==(const vec2& right) const;
	inline vec2 operator+(const vec2& right) const;
	inline vec2 operator-(const vec2& right) const;
	inline vec2 operator*(real right) const;

	real x;
	real y;
	real z;
};

inline real dot(const vec2& left, const vec2& right);

vec2 operator*(real left, const vec2& right);

bool vec2::operator==(const vec2& right) const
{
	return x == right.x && y == right.y;
}

vec2 vec2::operator+(const vec2& right) const
{
	return vec2(x + right.x, y + right.y);
}

vec2 vec2::operator-(const vec2& right) const
{
	return vec2(x - right.x, y - right.y);
}

vec2 vec2::operator*(real right) const
{
	return vec2(x * right, y * right);
}

real dot(const vec2& left, const vec2& right)
{
	return left.x * right.x + left.y * right.y;
}

inline vec2 operator*(real left, const vec2& right)
{
	return vec2(left * right.x, left * right.y);
}

} // dvn
} // math

#endif
