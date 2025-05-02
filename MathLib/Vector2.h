#pragma once

#include "Config.h"
#include <math.h>

class Vector2
{
public:
	Vector2();
	Vector2(Real x, Real y);
	Vector2(const Vector2& other);

	Real x();
	Real y();

	void setX(Real x);
	void setY(Real y);
	void set(Real x, Real y);

	Vector2 operator+(const Vector2& other);
	Vector2 operator-(const Vector2& other);
	Vector2 operator*(Real scalar);
	Vector2 operator/(Real scalar);

	void operator+=(const Vector2& other);
	void operator-=(const Vector2& other);
	void operator*=(Real scalar);
	void operator/=(Real scalar);

	bool operator==(const Vector2& other);
	bool operator!=(const Vector2& other);

	Real length();
	void normalise();
	Vector2 normaliseCopy();

	Real dot(const Vector2& other);
protected:
	Real mX, mY;
};

