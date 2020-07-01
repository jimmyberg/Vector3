
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
	x += right.x;
	y += right.y;
	z += right.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3 &right){
	x -= right.x;
	y -= right.y;
	z -= right.z;
	return *this;
}
Vector3& Vector3::operator*=(const Vector3 &right){
	x *= right.x;
	y *= right.y;
	z *= right.z;
	return *this;
}
Vector3& Vector3::operator/=(const Vector3 &right){
	x /= right.x;
	y /= right.y;
	z /= right.z;
	return *this;
}
void Vector3::normalize(){
	*this = normalized();
}
Vector3 Vector3::normalized() const{
	float lenghtInverse = 1/absolute();
	return Vector3(
		x * lenghtInverse,
		y * lenghtInverse,
		z * lenghtInverse);
}
float Vector3::absolute() const{
	return sqrt(absolute2());
}
float Vector3::absolute2() const{
	return x*x + y*y + z*z;
}
float Vector3::dotProduct(const Vector3 &left, const Vector3 &right){
	return left.x * right.x + left.y * right.y + left.z * right.z;
}
Vector3 Vector3::crossProduct(const Vector3 &left, const Vector3 &right){
	return Vector3(
		left.y*right.z - left.z*right.y ,
		left.z*right.x - left.x*right.z ,
		left.x*right.y - left.y*right.x );
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
	os << '{' << vector3.x << ',' << vector3.y << ',' << vector3.z << '}';
	return os;
}
