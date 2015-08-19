
#ifndef _Vector3_h_
#define _Vector3_h_

class Vector3{
public:
	//constructors
	Vector3(float ix, float iy, float iz);
	Vector3(float ia);
	Vector3();

	//variables
	float x,y,z;

	//operators
	const Vector3 operator+(const Vector3& right) const;
	const Vector3 operator-(const Vector3& right) const;
	const Vector3 operator*(const Vector3& right) const;
	const Vector3 operator/(const Vector3& right) const;
	Vector3& operator+=(const Vector3& right);
	Vector3& operator-=(const Vector3& right);
	Vector3& operator*=(const Vector3& right);
	Vector3& operator/=(const Vector3& right);

	//fucntions
	void normilize();
	float absolute() const;
	static float dotProduct(Vector3 &left, Vector3 &right);
	static Vector3 crossProduct(Vector3 &left, Vector3 &right);
};

#endif
