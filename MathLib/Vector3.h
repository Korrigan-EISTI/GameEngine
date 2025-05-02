#pragma once

#include "Vector2.h"

class Vector3 : public Vector2
{
public:
	Vector3();
	Vector3(Real x, Real y, Real z);
	Vector3(const Vector2& vec2);
	Vector3(const Vector3& vec2);

	const Real z();

	void setZ(Real z);
	void set(Real x, Real y, Real z);

	Vector3 operator+(const Vector3& other);
	Vector3 operator-(const Vector3& other);
	Vector3 operator*(Real scalar);
	Vector3 operator/(Real scalar);

	void operator+=(const Vector3& other);
	void operator-=(const Vector3& other);
	void operator*=(Real scalar);
	void operator/=(Real scalar);

	bool operator==(const Vector3& other);
	bool operator!=(const Vector3& other);

	Real length();
	void normalise();
	Vector3 normaliseCopy();

	Real dot(const Vector3& other);
	Vector3 cross(const Vector3& other);
protected:
	Real mZ;
private:
};

