
#include "Vector3.hpp"
#include <math.h>

Vector3::Vector3(float ix, float iy, float iz): x(ix), y(iy), z(iz){}
Vector3::Vector3(float ia): x(ia), y(ia), z(ia){}
Vector3::Vector3(): x(0), y(0), z(0){}

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
void Vector3::normilize(){
	float lenght = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	x /= lenght;
	y /= lenght;
	z /= lenght;
}
float absolute() const{
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
}
static float dotProduct(Vector3 &left, Vector3 &right){
	return left.x * right.x + left.y * right.y + left.z * right.z;
}
static Vector3 crossProduct(Vector3 &left, Vector3 &right){
	return Vector3(
		left.y*right.z - left.z*right.y ,
		left.z*right.x - left.x*right.z ,
		left.x*right.y - left.y*right.x );
}