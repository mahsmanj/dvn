#ifndef DVN_MATH_VECTOR2_H
#define DVN_MATH_VECTOR2_H

namespace dvn {
namespace math {

/**
 * A two-dimensional vector class.
 */
template <class scalar>
struct vector2
{
	vector2(scalar in_x, scalar in_y);

	inline bool operator==(const vector2& right) const;
	inline vector2 operator+(const vector2& right) const;
	inline vector2 operator-(const vector2& right) const;
	inline vector2 operator*(scalar right) const;

	scalar x;
	scalar y;
};

template <class scalar>
inline scalar dot(const vector2<scalar>& left, const vector2<scalar>& right);

template <class scalar>
vector2<scalar> operator*(scalar left, const vector2<scalar>& right);

template <class scalar>
vector2<scalar>::vector2(scalar in_x, scalar in_y)
	: x(in_x)
	, y(in_y)
{
}

template <class scalar>
bool vector2<scalar>::operator==(const vector2& right) const
{
	return x == right.x && y == right.y;
}

template <class scalar>
vector2<scalar> vector2<scalar>::operator+(const vector2& right) const
{
	return vector2(x + right.x, y + right.y);
}

template <class scalar>
vector2<scalar> vector2<scalar>::operator-(const vector2& right) const
{
	return vector2(x - right.x, y - right.y);
}

template <class scalar>
vector2<scalar> vector2<scalar>::operator*(scalar right) const
{
	return vector2(x * right, y * right);
}

template <class scalar>
scalar dot(const vector2<scalar>& left, const vector2<scalar>& right)
{
	return left.x * right.x + left.y * right.y;
}

template <class scalar>
inline vector2<scalar> operator*(scalar left, const vector2<scalar>& right)
{
	return vector2<scalar>(left * right.x, left * right.y);
}

} // dvn
} // math

#endif
