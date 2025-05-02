#include "Vector3.h"
#include <limits>

Vector3::Vector3() : Vector2(), mZ(-std::numeric_limits<Real>::max())
{
}

Vector3::Vector3(Real x, Real y, Real z) : Vector2(x, y), mZ(z)
{
}

Vector3::Vector3(const Vector2& vec2) : Vector2(vec2), mZ(-std::numeric_limits<Real>::max())
{
}

Vector3::Vector3(const Vector3& vec) : Vector2(vec.mX, vec.mY), mZ(vec.mZ)
{
}

Real Vector3::z()
{
	return mZ;
}

void Vector3::setZ(Real z)
{
	mZ = z;
}

void Vector3::set(Real x, Real y, Real z)
{
	Vector2::set(x, y);
	mZ = z;
}

Vector3 Vector3::operator+(const Vector3& other)
{
	return Vector3(mX + other.mX, mY + other.mY, mZ + other.mZ);
}

Vector3 Vector3::operator-(const Vector3& other)
{
	return Vector3(mX - other.mX, mY - other.mY, mZ - other.mZ);
}

Vector3 Vector3::operator*(Real scalar)
{
	return Vector3(mX * scalar, mY * scalar, mZ * scalar);
}

Vector3 Vector3::operator/(Real scalar)
{
	return (scalar != 0) ? Vector3(mX / scalar, mY / scalar, mZ / scalar) : *this;
}

void Vector3::operator+=(const Vector3& other)
{
	Vector2::operator+=(other);
	mZ += other.mZ;
}

void Vector3::operator-=(const Vector3& other)
{
	Vector2::operator-=(other);
	mZ -= other.mZ;
}

void Vector3::operator*=(Real scalar)
{
	Vector2::operator*=(scalar);
	mZ *= scalar;
}

void Vector3::operator/=(Real scalar)
{
	if (scalar != 0)
	{
		Vector2::operator*=(scalar);
		mZ /= scalar;
	}
}

bool Vector3::operator==(const Vector3& other)
{
	return Vector2::operator==(other) && mZ == other.mZ;
}

bool Vector3::operator!=(const Vector3& other)
{
	return !(*this == other);
}

Real Vector3::length()
{
	return sqrt(mX * mX + mY * mY + mZ * mZ);
}

void Vector3::normalise()
{
	Real l = length();
	if (l != 0)
		*this /= l;
}

Vector3 Vector3::normaliseCopy()
{
	Real l = length();
	if (l != 0)
		return Vector3(*this / l);
}

Real Vector3::dot(const Vector3& other)
{
	return Vector2::dot(other) + mZ * other.mZ;
}

Vector3 Vector3::cross(const Vector3& other)
{
	return Vector3(
		mY * other.mZ - mZ * other.mY,
		mZ * other.mX - mX * other.mZ,
		mX * other.mY - mY * other.mX
	);
}
