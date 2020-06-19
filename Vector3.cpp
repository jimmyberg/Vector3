
#include "Vector3.hpp"

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
	float lenght = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	x /= lenght;
	y /= lenght;
	z /= lenght;
}
Vector3 Vector3::normalized() const{
	float lenght = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
	return Vector3(
		x / lenght,
		y / lenght,
		z / lenght);
}
float Vector3::absolute() const{
	return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
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
		(absolute() * otherVector.absolute())
		);
}

std::ostream& operator<<(std::ostream& os, const Vector3& vector3){
    os << '{' << vector3.x << ',' << vector3.y << ',' << vector3.z << '}';
    return os;
}
