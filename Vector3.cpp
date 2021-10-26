
#include "Vector3.hpp"
#include "Quaternion.h"

Vector3 Vector3::operator+(const Vector3 &right) const{
	Vector3 temp(*this);
	temp += right;
	return temp;
}

Vector3 Vector3::operator-(const Vector3 &right) const{
	Vector3 temp(*this);
	temp -= right;
	return temp;
}

Vector3 Vector3::operator*(const Vector3 &right) const{
	Vector3 temp(*this);
	temp *= right;
	return temp;
}

Vector3 Vector3::operator/(const Vector3 &right) const{
	Vector3 temp(*this);
	temp /= right;
	return temp;
}

Vector3& Vector3::operator+=(const Vector3 &right){
	for (int index = 0; index < 3; ++index)
		data[index] += right.data[index];
	return *this;
}
Vector3& Vector3::operator-=(const Vector3 &right){
	for (int index = 0; index < 3; ++index)
		data[index] -= right.data[index];
	return *this;
}

Vector3& Vector3::operator*=(const Vector3 &right){
	for (int index = 0; index < 3; ++index)
		data[index] *= right.data[index];
	return *this;
}

Vector3& Vector3::operator/=(const Vector3 &right){
	for (int index = 0; index < 3; ++index)
		data[index] /= right.data[index];
	return *this;
}

void Vector3::normalize(){
	*this = normalized();
}

Vector3 Vector3::normalized() const{
	float lenghtInverse = 1/absolute();
	return Vector3(
		data[0] * lenghtInverse,
		data[1] * lenghtInverse,
		data[2] * lenghtInverse);
}

float Vector3::absolute() const{
	return sqrt(absolute2());
}

float Vector3::absolute2() const{
	float ret = 0;
	for (int index = 0; index < 3; ++index)
		ret += data[index]*data[index];
	return ret;
}

float Vector3::dotProduct(const Vector3 &left, const Vector3 &right){
	float ret = 0;
	for (int index = 0; index < 3; ++index)
		ret += left.data[index]*right.data[index];
	return ret;
}

Vector3 Vector3::crossProduct(const Vector3 &left, const Vector3 &right){
	return Vector3(
		left.data[1]*right.data[2] - left.data[2]*right.data[1] ,
		left.data[2]*right.data[0] - left.data[0]*right.data[2] ,
		left.data[0]*right.data[1] - left.data[1]*right.data[0] );
}

float Vector3::angleBetweenVectors(const Vector3& otherVector) const{
	// Two vectors form a triangle with sides abs(v1), abs(v1) and abs(v1-v2).
	// Apply good old geometry and you get this.
	return acos(
		dotProduct(*this, otherVector)
		/
		sqrt(absolute2() * otherVector.absolute2())
		);
}

void Vector3::rotateArroundVector(const Vector3& v, float rotation){
	const Quaternion rotationInQuaternionSpace(v, rotation);
	// Apply rotation
	*this = (rotationInQuaternionSpace * *this * rotationInQuaternionSpace.getConjugate()).toVector();
}

std::ostream& operator<<(std::ostream& os, const Vector3& vector3){
	os << '{' << vector3.data[0] << ',' << vector3.data[1] << ',' << vector3.data[2] << '}';
	return os;
}

std::istream& operator>>(std::istream& is, Vector3& vector3){
	is.ignore(256, '{');
	is >> vector3[0];
	is.ignore(256, ',');
	is >> vector3[1];
	is.ignore(256, ',');
	is >> vector3[2];
	is.ignore(256, '}');
	return is;
}
