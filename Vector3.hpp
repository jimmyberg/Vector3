
#ifndef _Vector3_h_
#define _Vector3_h_

#include <iostream>
#include <math.h>

class Vector3{
public:
	//constructors
	constexpr Vector3(float ix, float iy, float iz): data{ix, iy, iz}{}
	constexpr Vector3(float ia): data{ia, ia, ia}{}
	constexpr Vector3(): data{0}{}

	//variables
	float data[3];

	//operators
	float operator[](unsigned int index) const{
		return data[index];
	}
	float& operator[](unsigned int index){
		return data[index];
	}
	Vector3 operator+(const Vector3 &right) const;
	Vector3 operator-(const Vector3 &right) const;
	Vector3 operator-() const{return Vector3(-data[0], -data[1], -data[2]);};
	Vector3 operator*(const Vector3 &right) const;
	Vector3 operator/(const Vector3 &right) const;
	Vector3& operator+=(const Vector3 &right);
	Vector3& operator-=(const Vector3 &right);
	Vector3& operator*=(const Vector3 &right);
	Vector3& operator/=(const Vector3 &right);

	//functions
	void normalize();
	Vector3 normalized() const;
	float absolute() const;
	float absolute2() const; // Squared variant
	bool isZero() const{return data[0] == 0 && data[1] == 0 && data[2] == 0;}
	static float dotProduct(const Vector3 &left, const Vector3 &right);
	static Vector3 crossProduct(const Vector3 &left, const Vector3 &right);
	float angleBetweenVectors(const Vector3& otherVector) const;
	/**
	 * @brief      Rotate this vector using another vector as rotation axis.
	 *
	 * @param[in]  v         Vector used as rotations axis. Needs to be
	 *                       normalized
	 * @param[in]  rotation  The rotation angle in radians.
	 */
	void rotateArroundVector(const Vector3& v, float rotation);
};

std::ostream& operator<<(std::ostream& os, const Vector3& vector3);
std::istream& operator>>(std::istream& is, Vector3& vector3);

#endif
