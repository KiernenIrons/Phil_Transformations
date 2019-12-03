#include "Quaternion.h"

std::string Quaternion::ToString()
{
	return "(" + std::to_string(w) + ","
		+ std::to_string(x) + "i,"
		+ std::to_string(y) + "j,"
		+ std::to_string(z) + "k)";
}

double Quaternion::Modulus()
{
	return sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::Conjugate()
{
	return Quaternion(w, -x, -y, -z);
}

void Quaternion::FromAxisAngle(Vector3 axis, double angleRadian)
{
	double m = axis.Length();
	if (m > 0.0001)
	{
		double ca = cos(angleRadian / 2);
		double sa = sin(angleRadian / 2);
		x = axis.m_x / m * sa;
		y = axis.m_y / m * sa;
		z = axis.m_z / m * sa;
		w = ca;
	}
	else
	{
		w = 1; x = 0; y = 0; z = 0;
	}
}

Quaternion Quaternion::Multiply(Quaternion _q)
{
	double nw = _q.w * w - _q.x * x - _q.y * y - _q.z * z;
	double nx = _q.w * x + _q.x * w + _q.y * z - _q.z * y;
	double ny = _q.w * y + _q.y * w + _q.z * x - _q.x * z;
	double nz = _q.w * z + _q.z * w + _q.x * y - _q.y * x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::Copy()
{
	return Quaternion(x, y, z, w);
}

//                  -1
// V'=q*V*q     ,
// Multiplying q1 with q2 is meaning of doing q2 firstly then q1
Vector3 Quaternion::Rotate(Vector3 pt, int _angle)
{
	Quaternion axis, rotate;
	axis = Normalise();
	double angleRad = 3.14159 / 180 * _angle;
	rotate = Quaternion(cos(angleRad / 2), sin(angleRad / 2) * axis.x, sin(angleRad / 2) * axis.y, sin(angleRad / 2) * axis.z);
	Quaternion conjugate = rotate.Conjugate();
	Quaternion qNode = Quaternion(0, pt.m_x, pt.m_y, pt.m_z);
	qNode = rotate * qNode * conjugate;
	return Vector3(static_cast<float>(qNode.x), static_cast<float>(qNode.y), static_cast<float>(qNode.z));
}

Quaternion Quaternion::operator+(Quaternion q2)
{
	return Quaternion(w + q2.w, x + q2.x, y + q2.y, z + q2.z);
}

Quaternion Quaternion::operator-()
{
	return Quaternion(-w, -x, -y, -z);
}

Quaternion Quaternion::operator-(Quaternion q2)
{
	return Quaternion(w - q2.w, x - q2.x, y - q2.y, z - q2.z);
}

Quaternion Quaternion::operator*(double s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion Quaternion::operator*(float s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion Quaternion::operator*(int s)
{
	return Quaternion(w * s, x * s, y * s, z * s);
}

Quaternion Quaternion::operator*(Quaternion q2)
{
	double nw = w * q2.w - x * q2.x - y * q2.y - z * q2.z;
	double nx = w * q2.x + x * q2.w + y * q2.z - z * q2.y;
	double ny = w * q2.y + y * q2.w + z * q2.x - x * q2.z;
	double nz = w * q2.z + z * q2.w + x * q2.y - y * q2.x;
	return Quaternion(nw, nx, ny, nz);
}

Quaternion Quaternion::Normalise()
{
	double m = w * w + x * x + y * y + z * z;
	if (m > 0.001)
	{
		m = sqrt(m);
		return Quaternion(w / m, x / m, y / m, z / m);
	}
	else
	{
		return Quaternion(1, 0, 0, 0);
	}
}

Quaternion operator*(double s, Quaternion t_quarternion)
{
	return Quaternion(t_quarternion.w * s, t_quarternion.x * s, t_quarternion.y * s, t_quarternion.z * s);
}

Quaternion operator*(float s, Quaternion t_quarternion)
{
	return Quaternion(t_quarternion.w * s, t_quarternion.x * s,
		t_quarternion.y * s, t_quarternion.z * s);
}

Quaternion operator*(int s, Quaternion t_quarternion)
{
	return Quaternion(t_quarternion.w * s, t_quarternion.x * s,
		t_quarternion.y * s, t_quarternion.z * s);
}