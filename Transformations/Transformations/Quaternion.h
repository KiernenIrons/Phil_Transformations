#ifndef QUATERNION_H
#define QUATERNION_H
#include <string.h>
#include "Vector3.h"

class Quaternion
{
	double x, y, z, w;
public:
	Quaternion() :
		w{ 0 }
		, x{ 0 }
		, y{ 0 }
		, z{ 0 }
	{
	}

	Quaternion(double _w, double _x, double _y, double _z)
	{
		w = _w; x = _x; y = _y; z = _z;
	}

	Quaternion(double _w, Vector3 v)
	{
		w = _w; x = v.m_x; y = v.m_x; z = v.m_x;
	}

	std::string ToString();

	double Modulus();

	Quaternion Conjugate();

	void FromAxisAngle(Vector3 axis, double angleRadian);

	Quaternion Multiply(Quaternion _q);

	Quaternion Copy();

	Vector3 Rotate(Vector3 pt, int _angle);

	Quaternion operator +(Quaternion q2);

	Quaternion operator -();

	Quaternion operator -(Quaternion q2);

	Quaternion operator *(double s);

	Quaternion operator *(float s);

	Quaternion operator *(int s);

	Quaternion Normalise();

	friend Quaternion operator *(double s, Quaternion t_quarternion);

	friend Quaternion operator *(float s, Quaternion t_quarternion);

	friend Quaternion operator *(int s, Quaternion t_quarternion);

	Quaternion operator *(Quaternion q2);
};
#endif