
#include "Vector3.h"
#include <math.h>

Vector3::Vector3(float ix, float iy, float iz): x(ix), y(iy), z(iz){}
Vector3::Vector3(float ia): x(ia), y(ia), z(ia){}
Vector3::Vector3(): x(0), y(0), z(0){}

const Vector3 Vector3::operator+(const Vector3& right) const{
	Vector3 temp(*this);
	temp += right;
	return temp;
}
const Vector3 Vector3::operator-(const Vector3& right) const{
	Vector3 temp(*this);
	temp -= right;
	return temp;
}
const Vector3 Vector3::operator*(const Vector3& right) const{
	Vector3 temp(*this);
	temp *= right;
	return temp;
}
const Vector3 Vector3::operator/(const Vector3& right) const{
	Vector3 temp(*this);
	temp /= right;
	return temp;
}
Vector3& Vector3::operator+=(const Vector3& right){
	x += right.x;
	y += right.y;
	z += right.z;
	return *this;
}
Vector3& Vector3::operator-=(const Vector3& right){
	x -= right.x;
	y -= right.y;
	z -= right.z;
	return *this;
}
Vector3& Vector3::operator*=(const Vector3& right){
	x *= right.x;
	y *= right.y;
	z *= right.z;
	return *this;
}
Vector3& Vector3::operator/=(const Vector3& right){
	x /= right.x;
	y /= right.y;
	z /= right.z;
	return *this;
}
void Vector3::normilize(){
	float lenght = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	x /= lenght;
	y /= lenght;
	z /= lenght;
}
float absolute(){
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}