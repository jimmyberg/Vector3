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
		i = sinPart * v.data[0];
		j = sinPart * v.data[1];
		k = sinPart * v.data[2];
	}
	/**
	 * @brief      Constructs a vector in quaternion space
	 *
	 * @param[in]  v     The vector to transform
	 */
	Quaternion(const Vector3& v): real(0), i(v.data[0]), j(v.data[1]), k(v.data[2]){}
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
	Quaternion& operator*=(const Quaternion& right);
	Quaternion operator*(const Vector3& right) const;
	Quaternion operator*=(const Vector3& right);
	friend std::ostream& operator<<(std::ostream& os, const Quaternion& q);
	/**
	 * @brief      Returns a vector representation of the object.
	 *
	 * @return     Vector representation of the object.
	 */
	Vector3 toVector(){return Vector3(i,j,k);}
	/**
	 * @brief      Gets the rotated x vector.
	 *
	 *             When quaternion is not rotated, this just returns
	 *             Vector3(1,0,0)
	 *
	 * @return     The rotated x vector.
	 */
	Vector3 getRotatedXVector();
	/**
	 * @brief      Gets the rotated y vector.
	 *
	 *             When quaternion is not rotated, this just returns
	 *             Vector3(0,1,0)
	 *
	 * @return     The rotated y vector.
	 */
	Vector3 getRotatedYVector();
	/**
	 * @brief      Gets the rotated z vector.
	 *
	 *             When quaternion is not rotated, this just returns
	 *             Vector3(0,0,1)
	 *
	 * @return     The rotated z vector.
	 */
	Vector3 getRotatedZVector();
	float real = 1;
	float i = 0;
	float j = 0;
	float k = 0;
private:
};

std::ostream& operator<<(std::ostream& os, const Quaternion& q);

#endif //_QUATERNION_H_
