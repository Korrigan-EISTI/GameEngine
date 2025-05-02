#include "Vector2.h"
#include <limits>

Vector2::Vector2() : 
	mX(-std::numeric_limits<double>::max()),
	mY(-std::numeric_limits<double>::max())
{
}

Vector2::Vector2(Real x, Real y) :
	mX(x),
	mY(y)
{
}

Vector2::Vector2(const Vector2& other)
{
	*this = other;
}

Real Vector2::x()
{
	return mX;
}

Real Vector2::y()
{
	return mY;
}

void Vector2::setX(Real x)
{
	mX = x;
}

void Vector2::setY(Real y)
{
	mY = y;
}

void Vector2::set(Real x, Real y)
{
	mX = x;
	mY = y;
}

Vector2 Vector2::operator+(const Vector2& other)
{
	return Vector2(mX + other.mX, mY + other.mY);
}

Vector2 Vector2::operator-(const Vector2& other)
{
	return Vector2(mX - other.mX, mY - other.mY);
}

Vector2 Vector2::operator*(Real scalar)
{
	return Vector2(mX * scalar, mY * scalar);
}

Vector2 Vector2::operator/(Real scalar)
{
	return (scalar != 0) ? Vector2(mX / scalar, mY / scalar) : *this;
}

void Vector2::operator+=(const Vector2& other)
{
	mX += other.mX;
	mY += other.mY;
}

void Vector2::operator-=(const Vector2& other)
{
	mX -= other.mX;
	mY -= other.mY;
}

void Vector2::operator*=(Real scalar)
{
	mX *= scalar;
	mY *= scalar;
}

void Vector2::operator/=(Real scalar)
{
	if (scalar != 0)
	{
		mX /= scalar;
		mY /= scalar;
	}
}

bool Vector2::operator==(const Vector2& other)
{
	return mX == other.mX && mY == other.mY;
}

bool Vector2::operator!=(const Vector2& other)
{
	return !(*this == other);
}

Real Vector2::length()
{
	return sqrt(mX * mX + mY * mY);
}

void Vector2::normalise()
{
	Real l = length();
	if (l != 0)
		*this /= l;
}

Vector2 Vector2::normaliseCopy()
{
	Real l = length();
	if (l != 0)
		return *this / l;
}

Real Vector2::dot(const Vector2& other)
{
	return mX * other.mX + mY * other.mY;
}