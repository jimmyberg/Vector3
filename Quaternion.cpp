#include "Quaternion.h"

Quaternion Quaternion::operator*(const Quaternion& right) const{
	Quaternion ret;
	ret.real =
		real * right.real -
		i    * right.i -
		j    * right.j -
		k    * right.k;
	ret.i =
		real * right.i +
		i    * right.real +
		j    * right.k -
		k    * right.j;
	ret.j =
		real * right.j -
		i    * right.k +
		j    * right.real +
		k    * right.i;
	ret.k =
		real * right.k +
		i    * right.j -
		j    * right.i +
		k    * right.real;
	return ret;
}

Quaternion& Quaternion::operator*=(const Quaternion& right){
	Quaternion copyMe(*this);
	*this = copyMe * right;
	return *this;
}

Quaternion Quaternion::operator*(const Vector3& right) const{
	Quaternion ret;
	ret.real =
		-i    * right.x -
		j    * right.y -
		k    * right.z;
	ret.i =
		real * right.x +
		j    * right.z -
		k    * right.y;
	ret.j =
		real * right.y -
		i    * right.z +
		k    * right.x;
	ret.k =
		real * right.z +
		i    * right.y -
		j    * right.x;
	return ret;
}

Quaternion Quaternion::operator*=(const Vector3& right){
	Quaternion copyMe(*this);
	*this = copyMe * right;
	return *this;
}

Vector3 Quaternion::getRotatedXVector(){
	Quaternion ret(-i, +real, +k, -j);
	return (ret * getConjugate()).toVector();
}

Vector3 Quaternion::getRotatedYVector(){
	Quaternion ret(-j, -k, +real, +i);
	return (ret * getConjugate()).toVector();
}

Vector3 Quaternion::getRotatedZVector(){
	Quaternion ret(-k, +j, -i, +real);
	return (ret * getConjugate()).toVector();
}

std::ostream& operator<<(std::ostream& os, const Quaternion& q){
	os << '{' << q.real << ',' << q.i << ',' << q.j << ',' << q.k << '}';
	return os;
}
