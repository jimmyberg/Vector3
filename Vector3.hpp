
#ifndef _Vector3_h_
#define _Vector3_h_

#include <iostream>
#include <math.h>

class Vector3{
public:
	//constructors
	Vector3(float ix, float iy, float iz);
	Vector3(float ia);
	Vector3();

	//variables
	float x,y,z;

	//operators
	Vector3 operator+(const Vector3 &right) const;
	Vector3 operator-(const Vector3 &right) const;
	Vector3 operator*(const Vector3 &right) const;
	Vector3 operator/(const Vector3 &right) const;
	Vector3& operator+=(const Vector3 &right);
	Vector3& operator-=(const Vector3 &right);
	Vector3& operator*=(const Vector3 &right);
	Vector3& operator/=(const Vector3 &right);

	//fucntions
	void normalize();
	Vector3 normalized() const;
	float absolute() const;
	static float dotProduct(const Vector3 &left, const Vector3 &right);
	static Vector3 crossProduct(const Vector3 &left, const Vector3 &right);
};

std::ostream& operator<<(std::ostream& os, const Vector3& vector3);

#endif
