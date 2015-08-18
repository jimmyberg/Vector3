
#ifndef __Vector3_h__
#define __Vector3_h__

class Vector3{
public:
	Vector3(float ix, float iy, float iz);
	Vector3(float ia);
	Vector3();
	float x,y,z;
	const Vector3 operator+(const Vector3& right) const;
	const Vector3 operator-(const Vector3& right) const;
	const Vector3 operator*(const Vector3& right) const;
	const Vector3 operator/(const Vector3& right) const;
	Vector3& operator+=(const Vector3& right);
	Vector3& operator-=(const Vector3& right);
	Vector3& operator*=(const Vector3& right);
	Vector3& operator/=(const Vector3& right);

	void normilize();
	float absolute();
private:

};

#endif
