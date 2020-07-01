#ifndef _QUATERNION_H_
#define _QUATERNION_H_

#include "Vector3.hpp"
#include <cmath>

class Vector3;

/**
 * @brief      This class describes a quaternion.
 *
 *             Quaternions are awesome magical math constructions that allow us
 *             to apply rotations. See 3Blue1Brown for an awesome explanation.
 *             Note: i*j*k = i^2 = j^2 = k^2 = -1. Order of multiplication matters.
 */
class Quaternion{
public:
	Quaternion(){}
	/**
	 * @brief      Constructs a quaternion rotation around vector v.
	 *
	 * @param[in]  v         The vector to rotate around. Vector length must
	 *                       equal 1.
	 * @param[in]  rotation  The rotation in radian.
	 */
	Quaternion(const Vector3& v, float rotation){
		rotation /= 2;
		real = cos(rotation);
		float sinPart = sin(rotation);
		i = sinPart * v.x;
		j = sinPart * v.y;
		k = sinPart * v.z;
	}
	/**
	 * @brief      Constructs a vector in quaternion space
	 *
	 * @param[in]  v     The vector to transform
	 */
	Quaternion(const Vector3& v): real(0), i(v.x), j(v.y), k(v.z){}
	/**
	 * @brief      Constructs directly a Quaternion.
	 *
	 * @param[in]  real  The real part
	 * @param[in]  i     i part (complex number)
	 * @param[in]  j     j part (complex number)
	 * @param[in]  k     k part (complex number)
	 */
	Quaternion(float real, float i, float j, float k): real(real), i(i), j(j), k(k){}
	/**
	 * @brief      Convert to conjugated version.
	 */
	void conjugate(){
		i = -i;
		j = -j;
		k = -k;
	}
	/**
	 * @brief      Returns the conjugated version.
	 *
	 * @return     The conjugate.
	 */
	Quaternion getConjugate() const{
		Quaternion ret(*this);
		ret.conjugate();
		return ret;
	}
	/**
	 * @brief      Multiplication of Quaternion.
	 *
	 *             Multiplying effectively rotates the result of the combine
	 *             rotation in complex space and multiplies each length.
	 *
	 * @param[in]  right  The right Quaternion
	 *
	 * @return     The result of the multiplication of two Quaternions
	 */
	Quaternion operator*(const Quaternion& right) const;
	Quaternion operator*(const Vector3& right) const;
	friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);
	/**
	 * @brief      Returns a vector representation of the object.
	 *
	 * @return     Vector representation of the object.
	 */
	Vector3 toVector(){return Vector3(i,j,k);}
	float real;
	float i;
	float j;
	float k;
private:
};

std::ostream& operator<<(std::ostream& os, const Quaternion& q);

#endif //_QUATERNION_H_
