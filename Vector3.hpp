
#ifndef _Vector3_h_
#define _Vector3_h_

#include <iostream>
#include <math.h>

class Vector3{
public:
	//constructors
	constexpr Vector3(float ix, float iy, float iz): x(ix), y(iy), z(iz){}
	constexpr Vector3(float ia): x(ia), y(ia), z(ia){}
	constexpr Vector3(): x(0), y(0), z(0){}

	//variables
	float x,y,z;

	//operators
	Vector3 operator+(const Vector3 &right) const;
	Vector3 operator-(const Vector3 &right) const;
	Vector3 operator-() const{return Vector3(-x, -y, -z);};
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
	bool isZero(){return x == 0 && y == 0 && z == 0;}
	static float dotProduct(const Vector3 &left, const Vector3 &right);
	static Vector3 crossProduct(const Vector3 &left, const Vector3 &right);
};

std::ostream& operator<<(std::ostream& os, const Vector3& vector3);

#endif
